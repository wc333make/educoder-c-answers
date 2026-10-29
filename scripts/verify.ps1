# 本地体检：检查 answers/ 的文件数、命名、编码(BOM)与换行(CRLF)
# 用法:  pwsh -File scripts/verify.ps1
$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent $PSScriptRoot
$ans  = Join-Path $repo 'answers'

if (-not (Test-Path -LiteralPath $ans)) { throw "找不到 answers 目录: $ans" }

$dirs  = Get-ChildItem -LiteralPath $ans -Directory | Sort-Object Name
$files = Get-ChildItem -LiteralPath $ans -Recurse -File -Include *.c,*.h

"作业目录: {0}   代码文件: {1}" -f $dirs.Count, $files.Count
""

$bad = @()
foreach ($d in $dirs) {
    $fs = Get-ChildItem -LiteralPath $d.FullName -File -Include *.c,*.h
    "  {0,-46} {1,3} 个文件" -f $d.Name, $fs.Count
}

""
"编码/换行检查:"
foreach ($f in $files) {
    $bytes = [IO.File]::ReadAllBytes($f.FullName)
    $hasBom = ($bytes.Length -ge 3 -and $bytes[0] -eq 0xEF -and $bytes[1] -eq 0xBB -and $bytes[2] -eq 0xBF)
    $text = [IO.File]::ReadAllText($f.FullName)
    $crlf = $text.Contains("`r`n")
    $lfOnly = ($text -replace "`r`n", '').Contains("`n")
    if (-not $hasBom -or -not $crlf -or $lfOnly) {
        $bad += ("{0}  BOM={1} CRLF={2} 混用LF={3}" -f $f.Name, $hasBom, $crlf, $lfOnly)
    }
}
if ($bad.Count -eq 0) { "  全部通过（UTF-8 BOM + CRLF）" } else { $bad | ForEach-Object { "  [!] $_" } }

""
"命名检查（应形如 NN_题目名.c / NN_题目名__平台文件名）:"
$badName = $files | Where-Object { $_.Name -notmatch '^\d{2}_.+\.(c|h)$' }
if (-not $badName) { "  全部符合命名规则" } else { $badName | ForEach-Object { "  [!] " + $_.Name } }

""
"含疑似隐私串检查:"
$pat = 'cookie|token=|password|passwd|学号|student_?id'
$hits = $files | Select-String -Pattern $pat -SimpleMatch:$false -CaseSensitive:$false |
        Where-Object { $_.Line -notmatch '\btoken\b\s*\[|char\s+token|\btoken\b\s*=' }
if (-not $hits) { "  未发现可疑内容" } else { $hits | ForEach-Object { "  [!] {0}:{1}" -f $_.Filename, $_.LineNumber } }
