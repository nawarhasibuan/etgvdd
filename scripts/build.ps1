# ===============================================
# Compile all .cpp files into bin/ if needed
# PowerShell version
# ===============================================

New-Item -ItemType Directory -Force -Path "./bin" | Out-Null

# Get all .cpp files recursively
Get-ChildItem -Recurse -Filter "*.cpp" | ForEach-Object {

    $cppPath = $_.FullName
    $relPath = Resolve-Path -Relative $cppPath

    # Remove leading .\ if exists
    if ($relPath.StartsWith(".\")) {
        $relPath = $relPath.Substring(2)
    }

    # Remove src\ if exists
    $relPath = $relPath -replace "^src\\",""

    # Replace .cpp with .exe
    $exeRelPath = $relPath -replace "\.cpp$", ".exe"

    # Final output path under bin/
    $outputPath = Join-Path -Path "bin" -ChildPath $exeRelPath

    # Ensure parent directory exists
    $outputDir = Split-Path $outputPath -Parent
    if (-not (Test-Path $outputDir)) {
        New-Item -ItemType Directory -Path $outputDir | Out-Null
    }

    # Check timestamps
    $needsBuild = $true
    if (Test-Path $outputPath) {
        $srcTime = (Get-Item $cppPath).LastWriteTime
        $exeTime = (Get-Item $outputPath).LastWriteTime
        if ($srcTime -le $exeTime) {
            $needsBuild = $false
        }
    }

    if ($needsBuild) {
        g++ -std=c++17 -O2 -Wall "`"$cppPath`"" -o "`"$outputPath`""
    }

}

Write-Host "Done Compiling!"
