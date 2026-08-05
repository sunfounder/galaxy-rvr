#!/bin/bash
set -e

HEX_FILE="galaxy-rvr.ino.2.0.0.hex"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

echo ""
echo "Update Arduino Firmware"
echo ""
echo "firmware: $HEX_FILE"
echo "###########################################################################"
echo ""

# Check avrdude
if ! command -v avrdude &>/dev/null; then
    echo "Error: avrdude not found. Install it with: brew install avrdude"
    exit 1
fi

# List available serial ports
ports=()
i=0
echo "Ports List:"
shopt -s nullglob
for port in /dev/tty.usbmodem* /dev/tty.usbserial* /dev/tty.wchusbserial*; do
    if [ -e "$port" ]; then
        i=$((i + 1))
        ports[$i]="$port"
        echo "$i. $port"
    fi
done

if [ $i -eq 0 ]; then
    echo "No Arduino-compatible serial ports found."
    echo "Make sure your Arduino UNO is connected via USB."
    exit 1
fi

echo ""
read -p "Enter a COM port of Arduino (1-$i): " choice

if [ -z "${ports[$choice]}" ]; then
    echo "Invalid selection."
    exit 1
fi

SELECTED_PORT="${ports[$choice]}"
echo "You selected: $SELECTED_PORT"

avrdude -p atmega328p -c arduino -P "$SELECTED_PORT" -D -U "flash:w:$SCRIPT_DIR/$HEX_FILE:a"

if [ $? -eq 0 ]; then
    echo "Successfully uploaded $HEX_FILE on $SELECTED_PORT"
else
    echo "Failed to upload $HEX_FILE on $SELECTED_PORT"
    exit 1
fi
