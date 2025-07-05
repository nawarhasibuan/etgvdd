param (
    [Parameter(Mandatory = $true, Position = 0)]
    [string]$ScriptName,

    [Parameter(Position = 1)]
    [string[]]$ScriptArgs
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

# Path ke script target
$TargetScript = "scripts/$ScriptName.ps1"

if (-not (Test-Path $TargetScript)) {
    Write-Host "Script tidak ditemukan: $TargetScript"
    exit 1
}

Write-Host "Menjalankan: $TargetScript"
if ($ScriptArgs) {
    Write-Host "Dengan argumen: $ScriptArgs"
}

# Build command line
$argStr = $ScriptArgs -join ' '

# Jalankan script target dengan argumen
Invoke-Expression ".\$TargetScript $argStr"
