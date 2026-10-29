# 在当前 PowerShell 会话里设置好 GitHub 上传所需的环境变量。
# 用法（先点源进来，再直接调用 gh / git，避免参数二次转义的坑）：
#     . .\scripts\gh-env.ps1
#     gh api /user --jq .login
#     git push
param([switch]$NoProxy)

$proxy = 'socks5://127.0.0.1:10808'   # 改成你自己的代理端口

if (-not $NoProxy) {
    if (-not $env:ALL_PROXY)   { $env:ALL_PROXY   = $proxy }
    if (-not $env:HTTPS_PROXY) { $env:HTTPS_PROXY = $proxy }
    $env:NO_PROXY = '127.0.0.1,localhost'
}

# git 侧的两项修正（只影响 github.com，不影响其它远端）
$ghProxy = 'socks5h://127.0.0.1:10808'
if (-not (git config --global --get http.sslBackend)) {
    git config --global http.sslBackend openssl
}
if (-not (git config --global --get http.https://github.com/.proxy)) {
    git config --global http.https://github.com/.proxy $ghProxy
}

Write-Host "gh 代理已就绪：ALL_PROXY=$env:ALL_PROXY" -ForegroundColor DarkGray
Write-Host ("git: sslBackend=" + (git config --global --get http.sslBackend) +
            "  github proxy=" + (git config --global --get http.https://github.com/.proxy)) -ForegroundColor DarkGray
