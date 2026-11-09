#!/bin/bash

FILENAME="$1"
REALDATA="$2"

# Compile
g++ -g -Wall -std=c++20 "$FILENAME.cpp" \
    ../general/General.cpp \
    ../general/Debug.cpp \
    -I../general \
    -o "$FILENAME"

# Stop if compilation failed
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Run real input unless "test" was specified
if [ "$REALDATA" != "test" ]; then
    echo "Real"
    ./"$FILENAME" < "input/$FILENAME.txt"
fi

# Run test input
echo "Test"
./"$FILENAME" < "input/${FILENAME}_test.txt"
