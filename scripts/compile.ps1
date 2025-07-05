param (
    [Parameter(Mandatory = $true)]
    [string]$ArgStr
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

# --------- Pecah ArgStr ----------
$parts = $ArgStr -split '/'

$FileName = $parts[-1]

if ($parts.Length -gt 1) {
    $FolderName = ($parts[0..($parts.Length - 2)] -join '/')
} else {
    $FolderName = ""
}

# --------- Path Source & Output ----------
if ($FolderName -ne "") {
    $SourceFile = "src/contests/$FolderName/$FileName.cpp"
    $ExeFile = "bin/contests/$FolderName/$FileName.exe"
} else {
    $SourceFile = "src/contests/$FileName.cpp"
    $ExeFile = "bin/contests/$FileName.exe"
}

Write-Host "Source File: $SourceFile"
Write-Host "Executable:  $ExeFile"

# --------- Check Source ----------
if (-not (Test-Path $SourceFile)) {
    Write-Host "Source file tidak ditemukan!"
    exit 1
}

# --------- Pastikan Folder Output Ada ----------
$OutDir = Split-Path $ExeFile
if (-not (Test-Path $OutDir)) {
    New-Item -ItemType Directory -Path $OutDir -Force | Out-Null
}

# --------- Compile ----------
Write-Host "Compiling..."
$cmd = "g++ -O2 -std=c++17 -o `"$ExeFile`" `"$SourceFile`""

Write-Host "> $cmd"
Invoke-Expression $cmd

if ($LASTEXITCODE -ne 0) {
    Write-Host "Compile failed!"
    exit 1
}

Write-Host "Compile success: $ExeFile"
