# Educoder C 语言实训答案库 · 附浏览器自动化提交手册

一套可直接覆盖到头歌（Educoder）实训关卡里的 C 语言参考答案，以及一套**用 DeepSeek Harness（DSH）驱动浏览器、批量粘贴 + 逐关评测**的实践手册。

> 说明：本仓库只包含**代码答案**与**操作方法**，不含任何账号、Cookie、Token、学号、姓名等个人信息。课程名、作业 ID、关卡 ID 属于平台公开信息。

---

## 这是什么

- `answers/`：18 个实训作业、121 道关卡的参考答案（122 个代码文件，其中 4 道题各需要 2~3 个文件）。
- `docs/INDEX.zh-CN.md`：逐题清单——关卡序号、题目名、代码文件、**平台内对应路径**（如 `src/stepN/stepN_main.c`）、题型、验证情况。
- `docs/tutorial.md`：手把手教程（纯手工操作 + 自动化两种方式）。
- `docs/skill.md`：可直接复制进 AI Agent 的“技能卡”，写明工具调用顺序、坐标无关的定位方式、常见坑。
- `scripts/verify.ps1`：本地体检脚本，检查文件数、命名、UTF-8 BOM、CRLF。

## 目录结构

```
educoder-c-answers/
├─ answers/
│  ├─ 01_xxx[作业ID]/
│  │  ├─ 01_题目名.c
│  │  ├─ 02_题目名.h
│  │  └─ 11_多文件题__file1.c / __file2.c / __file.h
│  └─ ...
├─ docs/
│  ├─ INDEX.zh-CN.md      # 逐题清单（关卡 ↔ 文件 ↔ 平台路径）
│  ├─ tutorial.md         # 使用教程
│  └─ skill.md            # Agent 技能卡
├─ scripts/verify.ps1
├─ README.md
└─ LICENSE
```

## 30 秒上手（手工方式）

1. 打开课程 → 实训作业 → 进入某一关。
2. 在 `docs/INDEX.zh-CN.md` 里找到这道题对应的文件。
3. 编辑器里 **Ctrl+A 全选 → 删除 → 粘贴** 整份文件内容（不要只粘片段）。
4. 点 **评测**，等结果。
5. 通过后点 **下一关**；未通过就看“测试结果”里的输入/输出对比再改。

### 文件命名约定

| 形式 | 含义 |
| --- | --- |
| `NN_题目名.c` | 整份覆盖平台的 `.c` 源文件 |
| `NN_题目名.h` | 只覆盖平台头文件（函数题，内容是不可独立编译的函数体） |
| `NN_题目名__原平台文件名` | 一道题需要改多个文件时，同前缀即同一题 |

## 自动化提交（可选）

`docs/tutorial.md` 的第 3 节起完整写了流程，核心是：

1. 用**独立 profile 的浏览器**（例如 DSH 的 agent 浏览器）打开课程页并登录，这样不干扰你日常的浏览器，也不会误用你已登录的 Cookie。
2. 让 Agent 通过 CDP（Chrome DevTools Protocol）**在后台**读取页面结构、点击“评测/下一关”，全程不动鼠标、不抢前台窗口。
3. 每两次评测之间**静默 30 秒**（平台侧有频率限制）。
4. **任何一关评测失败立即停止**，把失败关卡与报错留给人工判断。

## 已知缺口（诚实声明）

- 4 道题在公开答案集中本身缺失，仓库未编造答案：见 `docs/INDEX.zh-CN.md` 的“无答案题目”表。
- 多文件题（如“多文件 C 程序”）需要在平台的文件下拉里**逐个文件切换**再粘贴；部分平台的该下拉控件对自动化点击不响应，建议手工完成这一关。

## 上传与维护（GitHub）

本仓库已发布在 **https://github.com/wc333make/educoder-c-answers**。想在别的机器上复刻同样的上传能力，按 [`docs/github-setup.md`](docs/github-setup.md) 走一遍即可：里面的三条关键结论是「`github.com` 走本地 SOCKS5 代理」「git 必须切到 OpenSSL TLS 后端」「凭据交给 Windows 凭据管理器」。

日常更新：

```powershell
. .\scripts\gh-env.ps1                 # 一次性设好代理 / TLS 后端
.\scripts\push.ps1 -Message "docs: xxx" # commit + push
```

## 合规与免责

- 仅用于**个人学习与自查**。请遵守所在课程与平台的学术诚信要求。
- 直接提交他人答案可能违反课程规定，风险自负。
- 若你是课程教师/平台方并希望下架本仓库，请开 issue。

## License

MIT，见 `LICENSE`。
