param ()

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$BinFolder = "bin"

Write-Host "Deleting all files in $BinFolder/ ..."

if (Test-Path $BinFolder) {
    # Remove-Item secara rekursif, paksa, dan tidak konfirmasi
    Remove-Item "$BinFolder\*" -Recurse -Force -ErrorAction SilentlyContinue

    # Pastikan bin folder tetap ada (dibuat ulang kalau hilang)
    if (-not (Test-Path $BinFolder)) {
        New-Item -ItemType Directory -Path $BinFolder | Out-Null
    }

    Write-Host "$BinFolder/ has been cleaned."
} else {
    Write-Host "$BinFolder/ folder does not exist. Creating it..."
    New-Item -ItemType Directory -Path $BinFolder | Out-Null
    Write-Host "$BinFolder/ created."
}
