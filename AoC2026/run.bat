@echo off
set FILENAME=%1
set REALDATA=%2

:: Compile the source file
clang++ -Wall -std=c++20 %FILENAME%.cpp General.cpp Debug.cpp -o %FILENAME%.exe

:: Check if compilation was successful
if %ERRORLEVEL% NEQ 0 (
	echo Compilation failed!
	exit /b %ERRORLEVEL%
)

if "%REALDATA%" NEQ "test" (
	:: Run the program with the input
	echo Real
	%FILENAME%.exe < %FILENAME%.txt
)

:: Run the program with the test_input
echo Test
%FILENAME%.exe < %FILENAME%_test.txt