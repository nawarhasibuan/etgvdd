param (
    [Parameter(Mandatory = $true)]
    [string]$ArgStr
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

# Split path ke array
$parts = $ArgStr -split '/'

# File = elemen terakhir
$FileName = $parts[-1]

# Folder = semua segmen kecuali terakhir
if ($parts.Length -gt 1) {
    $FolderName = ($parts[0..($parts.Length - 2)] -join '/')
} else {
    $FolderName = ""
}

# Path sesuai struktur
if ($FolderName -ne "") {
    $ExePath = "bin/contests/$FolderName/$FileName.exe"
    $InputFile = "tests/$FolderName/input/$FileName.txt"
    $OutputFile = "tests/$FolderName/output/$FileName.txt"
} else {
    $ExePath = "bin/contests/$FileName.exe"
    $InputFile = "tests/input/$FileName.txt"
    $OutputFile = "tests/output/$FileName.txt"
}

# Baca input file
$Lines = Get-Content $InputFile
$n = [int]$Lines[0]
$DataLines = $Lines[1..($Lines.Count - 1)]
$LinesPerPart = [Math]::Ceiling($DataLines.Count / $n)

# Folder output harus ada
$OutputDir = Split-Path $OutputFile
if (-not (Test-Path $OutputDir)) {
    New-Item -ItemType Directory -Path $OutputDir -Force | Out-Null
}

# Jalankan proses
for ($i = 0; $i -lt $n; $i++) {
    $StartIndex = $i * $LinesPerPart
    $EndIndex = [Math]::Min(($StartIndex + $LinesPerPart - 1), $DataLines.Count - 1)

    if ($StartIndex -gt $EndIndex) {
        break
    }

    $PartLines = $DataLines[$StartIndex..$EndIndex]
    $InputString = $PartLines -join "`n"

    $InputFileTemp = "input_$i.txt"
    $OutputFileTemp = "output_$i.txt"

    # Buat input file sementara
    $InputString | Out-File -Encoding ASCII -FilePath $InputFileTemp


    # Jalankan EXE dengan stdin & stdout redirect
    $process = Start-Process `
        -FilePath ".\$ExePath" `
        -RedirectStandardInput $InputFileTemp `
        -RedirectStandardOutput $OutputFileTemp `
        -NoNewWindow `
        -PassThru

    $process.WaitForExit()
}

# Gabungkan output
$outputs = @()
for ($i = 0; $i -lt $n; $i++) {
    $OutputFileTemp = "output_$i.txt"
    if (Test-Path $OutputFileTemp) {
        $outputs += Get-Content $OutputFileTemp
    }
}

# Tulis ke file output final
$outputs | Set-Content $OutputFile


# Hapus file sementara
for ($i = 0; $i -lt $n; $i++) {
    Remove-Item -Force "input_$i.txt" -ErrorAction SilentlyContinue
    Remove-Item -Force "output_$i.txt" -ErrorAction SilentlyContinue
}

Write-Host "Input: $InputFile"
Write-Host "Output: $OutputFile"
