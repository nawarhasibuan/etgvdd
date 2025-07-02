@echo off
REM ===== Delete all files and subfolders inside bin/ =====

echo Deleting all files in bin/...

REM Check if bin folder exists
if exist bin (
    REM Delete all files and folders inside bin recursively and quietly
    rmdir /s /q bin
    mkdir bin
    echo bin/ has been cleaned.
) else (
    echo bin/ folder does not exist.
)

pause
