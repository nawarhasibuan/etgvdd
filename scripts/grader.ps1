param (
    [Parameter(Mandatory = $true)]
    [string]$ArgStr
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

# --- Pecah path ---
$parts = $ArgStr -split '/'

$FileName = $parts[-1]

if ($parts.Length -gt 1) {
    $FolderName = ($parts[0..($parts.Length - 2)] -join '/')
} else {
    $FolderName = ""
}

# --- Path output & expected ---
if ($FolderName -ne "") {
    $OutputFile = "tests/$FolderName/output/$FileName.txt"
    $ExpectedFile = "tests/$FolderName/expected/$FileName.txt"
} else {
    $OutputFile = "tests/output/$FileName.txt"
    $ExpectedFile = "tests/expected/$FileName.txt"
}

# Write-Host "==== Step 1: Compile ===="
.\scripts\compile.ps1 -ArgStr $ArgStr

# Write-Host "==== Step 2: Run ===="
.\scripts\run.ps1 -ArgStr $ArgStr

# Write-Host "==== Step 3: Compare Output ===="

# Pastikan kedua file ada
if (-not (Test-Path $OutputFile)) {
    Write-Host "Output file tidak ditemukan: $OutputFile"
    exit 1
}
if (-not (Test-Path $ExpectedFile)) {
    Write-Host "Expected file tidak ditemukan: $ExpectedFile"
    exit 1
}

# Baca isi file
$output = Get-Content $OutputFile -Raw
$expected = Get-Content $ExpectedFile -Raw

# Normalisasi baris
$output = $output -replace "`r`n", "`n"
$expected = $expected -replace "`r`n", "`n"

if ($output -eq $expected) {
    Write-Host "`n Output SAMA dengan Expected!"
    exit 0
} else {
    Write-Host "`n Output BERBEDA dengan Expected!"
    Write-Host "=== Diff ==="
    # Tampilkan diff baris demi baris
    Compare-Object -ReferenceObject ($expected -split "`n") -DifferenceObject ($output -split "`n") | Format-Table
    exit 1
}
