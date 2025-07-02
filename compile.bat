@echo off
REM ===== Compile all .cpp files to bin/ folder if not up to date =====

echo Creating bin folder if not exists...
mkdir bin >nul 2>nul

REM Iterate all .cpp files in current folder and subfolders
for /r %%f in (*.cpp) do (

    REM Use delayed expansion for variables
    setlocal enabledelayedexpansion

    REM Rel path: remove current dir prefix
    set "rel=%%f"
    set "rel=!rel:%CD%\=!"

    REM Remove leading backslash if any
    if "!rel:~0,1!"=="\" set "rel=!rel:~1!"

    REM Remove 'src\' if exists
    set "rel=!rel:src\=!"

    REM Replace .cpp with .exe
    set "exe=!rel:.cpp=.exe!"

    REM Windows uses \ for folders
    set "exe=!exe:/=\!"

    REM Final output path in bin/
    set "output=bin\!exe!"

    REM Create output subfolder if needed
    for %%a in ("!output!") do mkdir "%%~dpa" >nul 2>nul

    REM Compare timestamps
    if not exist "!output!" (
        echo Compiling: %%f -> !output!
        g++ -std=c++17 -O2 -Wall "%%f" -o "!output!"
    ) else (
        for %%a in ("%%f") do for %%b in ("!output!") do (
            if %%~ta GTR %%~tb (
                echo Compiling: %%f -> !output!
                g++ -std=c++17 -O2 -Wall "%%f" -o "!output!"
            )
        )
    )

    endlocal
)

echo Done!
pause
