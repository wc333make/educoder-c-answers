# gh 包装器：自动带上代理，避免每次手写 $env:ALL_PROXY
#   用法：.\scripts\gh.ps1 api /user --jq .login
param([Parameter(ValueFromRemainingArguments = $true)][string[]]$GhArgs)

$ErrorActionPreference = 'Stop'

# 本地 SOCKS5 代理（Clash / V2Ray 等常见端口），按需改成你自己的
$proxy = 'socks5://127.0.0.1:10808'
if (-not $env:ALL_PROXY) { $env:ALL_PROXY = $proxy }
$env:NO_PROXY = '127.0.0.1,localhost'

$gh = Join-Path $env:ProgramFiles 'GitHub CLI\gh.exe'
if (-not (Test-Path -LiteralPath $gh)) { $gh = 'gh' }

& $gh @GhArgs
exit $LASTEXITCODE
