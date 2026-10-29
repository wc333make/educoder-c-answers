# GitHub 上传环境备忘（本机实测结论）

记录一次踩坑的完整过程，换机器或换网络时按这个清单排查即可。

## 一、结论速查

| 项目 | 值 |
| --- | --- |
| GitHub 账号 | `wc333make`（id `301688005`） |
| 仓库 | https://github.com/wc333make/educoder-c-answers （public，默认分支 `master`） |
| 可用出口 | 本地 SOCKS5 `127.0.0.1:10808`（Clash/V2Ray 类客户端） |
| git TLS 后端 | 必须 `openssl`，不能用默认的 schannel |
| gh 认证方式 | `gh auth login --web`（设备码）+ 走代理 |
| 凭据 | Windows 凭据管理器（`credential.helper=manager`，系统级） |

## 二、三个坑与对应解法

### 1. `github.com:443` 直连超时（21s），`api.github.com` 却正常

不是“网速慢”，是 `github.com` 这条路经常被掐。所有 git 操作都走 `github.com`，所以 `git push` 必挂，而 `gh`（走 `api.github.com`）反而没事。

解法：给 git 单独配 github.com 的代理（只影响 github.com，其它远端不受影响）：

```powershell
git config --global http.https://github.com/.proxy socks5h://127.0.0.1:10808
```

`gh` 走环境变量：

```powershell
$env:ALL_PROXY = 'socks5://127.0.0.1:10808'
```

注意 git 要 `socks5h://`（让代理解析 DNS），gh 要 `socks5://`。

### 2. `schannel: AcquireCredentialsHandle failed: SEC_E_NO_CREDENTIALS`

Windows 自带 TLS 实现读不到证书库（受限令牌/沙箱环境常见）。表现为 curl、git 全部 TLS 失败，看起来像网络问题。

解法：

```powershell
git config --global http.sslBackend openssl
```

Git for Windows 自带 OpenSSL，改后端即可绕开。

### 3. `fatal: could not read Username` / `couldn't create signal pipe`

git 的凭据助手要靠 msys 的 `sh.exe` 起子进程，受限环境里创建命名管道被拒。

解法：以完整权限运行一次 `git push`（本项目在 DSH 里用 `sandbox_permissions: danger-full-access`）。凭据由 Windows 凭据管理器提供，push 成功后不必每次重配。

## 三、一次性初始化（新机器照抄）

```powershell
# 1. 安装
winget install --id GitHub.cli
winget install --id Git.Git

# 2. 走代理登录（设备码，无需在聊天里贴 token）
$env:ALL_PROXY = 'socks5://127.0.0.1:10808'
gh auth login --hostname github.com --git-protocol https --web

# 3. 固定 TLS 与代理
git config --global http.sslBackend openssl
git config --global http.https://github.com/.proxy socks5h://127.0.0.1:10808

# 4. 验证
gh api /user --jq .login
git ls-remote https://github.com/cli/cli HEAD
```

## 四、日常上传

先点源环境脚本（**不要**用「再包一层 gh.ps1」的写法，PowerShell 5.1 会把带双引号的参数重新拆开）：

```powershell
. .\scripts\gh-env.ps1      # 设好 ALL_PROXY / git 代理 / openssl
gh api /user --jq .login    # 之后直接调用 gh、git 即可
```

改完文件后一键提交推送：

```powershell
.\scripts\push.ps1 -Message "docs: 更新教程"
```

或者手动：

```powershell
git add -A
git commit -m "..."
git push
```

> ⚠️ 小坑：`gh api` 的 `--jq` 表达式里**不要写双引号**（如 `'.login + " x"'`），PS 5.1 传参给原生 exe 时会拆开，报 `accepts 1 arg(s), received 3`。需要拼字符串就用 PowerShell 解析：
>
> ```powershell
> $u = gh api /user | ConvertFrom-Json
> "$($u.login) ($($u.public_repos) repos)"
> ```
>
> `--json` 的多字段参数要整体加引号：`--json 'name,visibility'`，否则逗号会被当成数组。


## 五、只改单个文件（不想 clone/push 时）

```powershell
$env:ALL_PROXY = 'socks5://127.0.0.1:10808'
$b64 = [Convert]::ToBase64String([IO.File]::ReadAllBytes('README.md'))
gh api -X PUT repos/wc333make/educoder-c-answers/contents/README.md `
  -f message='docs: update README' -f content=$b64 -f sha=(gh api repos/wc333make/educoder-c-answers/contents/README.md --jq .sha)
```

## 六、安全

- 不要把 PAT 贴进聊天记录；优先用 `gh auth login --web` 设备码。
- 令牌存在 Windows 凭据管理器（`gh auth status` 显示 `keyring`），可用 `gh auth logout` 随时撤销。
- 本仓库不含账号、Cookie、学号、姓名等个人信息。
