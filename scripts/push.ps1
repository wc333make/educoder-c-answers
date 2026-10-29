# 一键提交并推送：commit + push（自动带 openssl TLS 后端与 github.com 代理）
#   用法：.\scripts\push.ps1 -Message "docs: 更新教程"
param(
    [string]$Message = "chore: 更新答案与文档",
    [string]$Remote = "origin",
    [string]$Branch = "master"
)

$ErrorActionPreference = 'Stop'
Push-Location (Split-Path $PSScriptRoot -Parent)
try {
    $proxy = (git config --get http.https://github.com/.proxy)
    if (-not $proxy) {
        git config http.https://github.com/.proxy 'socks5h://127.0.0.1:10808'
        $proxy = (git config --get http.https://github.com/.proxy)
    }
    if (-not (git config --get http.sslBackend)) {
        git config http.sslBackend openssl
    }

    git add -A
    $staged = (git diff --cached --name-only)
    if ($staged) {
        git -c core.quotepath=false commit -m $Message
        "已提交 {0} 个文件" -f (($staged | Measure-Object).Count)
    } else {
        "没有变更需要提交"
    }

    git push $Remote $Branch
    if ($LASTEXITCODE -ne 0) {
        throw "push 失败：若报 could not read Username / signal pipe，请以完整权限重试（凭据助手需要创建命名管道）"
    }
    "已推送：$(git remote get-url $Remote) ($Branch)"
}
finally {
    Pop-Location
}
