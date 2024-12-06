@echo off
set FILENAME=%1

:: Compile the source file
clang++ -Wall -std=c++17 %FILENAME%.cpp -o %FILENAME%.exe

:: Check if compilation was successful
if %ERRORLEVEL% NEQ 0 (
	echo Compilation failed!
	exit /b %ERRORLEVEL%
)

:: Run the program with the input
%FILENAME%.exe < %FILENAME%.txt

:: Run the program with the test_input
%FILENAME%.exe < %FILENAME%_test.txt