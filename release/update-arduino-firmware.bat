@echo off
setlocal enabledelayedexpansion

set avrdudePath="avrdude.exe"
set arduinoHexFile="galaxy-rvr.ino.2.0.0.hex"

echo.
echo Update Arduino Firmware
echo.
echo firmware: %arduinoHexFile%
echo ###########################################################################
echo.

set /a i=0
:: Initialize an array to store COM ports
set "comPorts[0]=None"
echo Ports List:
:: Use 'wmic' command to list all devices that might be COM ports
for /f "tokens=*" %%i in ('wmic path Win32_PnPEntity where "Name like '%%(COM%%'" get Name /format:list 2^>nul') do (
    :: Check if the line contains 'COM'
    echo %%i | findstr /C:"COM" >nul
    if not errorlevel 1 (
        set /a i+=1
        :: Extract everything after the '=' character
        for /f "tokens=2 delims==" %%j in ("%%i") do (
            :: Store the COM port information in the array
            set "comPorts[!i!]=%%j"
            :: Display the COM port information without 'Name='
            echo !i!. %%j
        )
    )
)

:: Prompt the user to select a COM port by number
echo.
set /p userChoice="Enter a COM port of Arduino (1-%i%): "
set "selectedPort=!comPorts[%userChoice%]!"

set selectedPortNumber=""

:: Check if a valid selection was made
if defined selectedPort (
    echo You selected: !selectedPort!
    :: Extract just the COM number (e.g., COM9) from the selected port
    for /f "tokens=*" %%k in ("!selectedPort!") do (
        echo %%k | findstr /R "COM[0-9]*" >nul
        if not errorlevel 1 (
            :: This time, specifically extract the part after 'COM'
            for /f "tokens=1-2 delims=()" %%m in ("%%k") do (
                set "portName=%%n"
                :: Ensure the extracted part is not empty
                if not "%%n"=="" (
                    echo Selected COM port number: %%n
                    set selectedPortNumber=%%n
                ) else (
                    echo Could not extract COM port number.
                    pause
                    exit /b
                )
            )
        )
    )
) else (
    echo Invalid selection.
    pause
    exit /b
)

"%avrdudePath%" -patmega328p -carduino -P!selectedPortNumber! -D -Uflash:w:"%arduinoHexFile%":a
if !errorlevel! equ 0 (
    echo Successfully uploaded %arduinoHexFile% on !selectedPortNumber!
    pause
) else (
    echo Failed to uploaded %arduinoHexFile% on !selectedPortNumber!
    pause
)

endlocal
pause