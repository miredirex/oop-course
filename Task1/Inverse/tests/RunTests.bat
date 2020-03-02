@echo off
setlocal
chcp 65001 >nul
set InverseProgram="%~1"
set SuccessfulTests=0
set CurrentTest=0
set InputFile=""
set TempOutput="%TEMP%\inverse_output.txt"

if %InverseProgram%=="" (
    echo Please specify path to the executable
    echo Usage: RunTests.bat executable.exe
    exit /B 1
)
if not exist %InverseProgram% (
    echo Executable not found, check the path and try again
    exit /B 1
)

rem --- Тесты ---

for /l %%x in (1, 1, 5) do (
   set /A CurrentTest+=1
   %InverseProgram% %%x.txt > %TempOutput% || goto :failed
   fc "Expected Output\%%x.txt" %TempOutput% || goto :failed
   echo Test %%x successful
   set /A successful+=1
)

rem #8. det = 0, обратной матрицы не существует
set /A CurrentTest+=1
%InverseProgram% "det0.txt" > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #9. Если input файл не предоставлен
set /A CurrentTest+=1
%InverseProgram% "" > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #10. Если input файл не найден
set /A CurrentTest+=1
set InputFile="this_file_doesnt_exist.txt"
%InverseProgram% "%InputFile%" > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #11. Без аргументов не должна выполняться
set /A CurrentTest+=1
%InverseProgram% > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1


rem Тесты прошли успешно
echo Tests passed: %successful%/9
echo All tests successful
exit /B 0

:failed
echo Failed test %CurrentTest%
echo Tests passed: %successful%/9
exit /B 1