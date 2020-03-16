@echo off
setlocal
chcp 65001 > nul
set FlipByteProgram="%~1"
set SuccessfulTests=0
set CurrentTest=0
set Answer=0
set TempOutput="%TEMP%/flipbyte_output.txt"

if %FlipByteProgram%=="" (
    echo Please specify path to the executable
    echo Usage: RunTests.bat executable.exe
    exit /B 1
)
if not exist %FlipByteProgram% (
    echo Executable not found, check the path and try again
    exit /B 1
)

rem --- Тесты ---

rem #1. 6 = 96
set /A CurrentTest+=1
%FlipByteProgram% 6 > %TempOutput% || goto :failed
set /p Answer=<%TempOutput%
if %Answer% NEQ 96 goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #2. Без аргументов не должно выполняться
set /A CurrentTest+=1
%FlipByteProgram% > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #3. Число не диапазоне от 0 до 255 (256)
set /A CurrentTest+=1
%FlipByteProgram% 256 > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #4. Число не диапазоне от 0 до 255 (-1)
set /A CurrentTest+=1
%FlipByteProgram% -1 > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #5. Число 255
set /A CurrentTest+=1
%FlipByteProgram% 255 > %TempOutput% || goto :failed
set /p Answer=<%TempOutput%
if %Answer% NEQ 255 goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #6. Число 0
set /A CurrentTest+=1
%FlipByteProgram% 0 > %TempOutput% || goto :failed
set /p Answer=<%TempOutput%
if %Answer% NEQ 0 goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #7. 128 = 1
set /A CurrentTest+=1
%FlipByteProgram% 128 > %TempOutput% || goto :failed
set /p Answer=<%TempOutput%
if %Answer% NEQ 1 goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #8. 170 = 85 (10101010 = 01010101)
set /A CurrentTest+=1
%FlipByteProgram% 170 > %TempOutput% || goto :failed
set /p Answer=<%TempOutput%
if %Answer% NEQ 85 goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #9. Передача строки как аргумент
set /A CurrentTest+=1
%FlipByteProgram% "string" > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #10. Очень большое число
set /A CurrentTest+=1
%FlipByteProgram% 214748364700000 > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #11. Очень большое отрицательное число
set /A CurrentTest+=1
%FlipByteProgram% -414748364700000 > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #12. Число может начинаться с нулей (00000000123)
set /A CurrentTest+=1
%FlipByteProgram% 00000000123 > %TempOutput% || goto :failed
set /p Answer=<%TempOutput%
if %Answer% NEQ 222 goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #13. Число может начинаться с нулей, но по-прежнему не может превышать границы (00000000256)
set /A CurrentTest+=1
%FlipByteProgram% 00000000256 > nul && goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem Тесты прошли успешно
echo Tests passed: %successful%/13
echo All tests successful
exit /B 0

:failed
echo Failed test %CurrentTest%
echo Tests passed: %successful%/13
exit /B 1