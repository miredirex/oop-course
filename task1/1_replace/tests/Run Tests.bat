@echo off
setlocal
chcp 65001 >nul
set ReplaceProgram="%~1"
set SuccessfulTests=0
set CurrentTest=0
set InputFile=""


rem --- Тесты ---

rem #1. Замена слова experiment на task в простейшем предложении
set /A CurrentTest+=1
set InputFile="1experiment_to_task.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" experiment task || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #2. Проверка русского языка (кодировка UTF-8)
set /A CurrentTest+=1
set InputFile="2russian_lang.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" поддерживаться работать || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #3. Проверка многострочных файлов
set /A CurrentTest+=1
set InputFile="3several_lines.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" here HERE || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #4. Замена не должна производиться: искомое слово больше того, что в файле, но начинается также
set /A CurrentTest+=1
set InputFile="4no_replace.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" words 123 || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #5. Замена пробелов
set /A CurrentTest+=1
set InputFile="5replacing_spaces.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" " " "<space>" || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #6. Не должно заменить раздельное слово
set /A CurrentTest+=1
set InputFile="6shouldnt_replace.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" заменить 1 || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #7. Замена всего предложения
set /A CurrentTest+=1
set InputFile="7whole_sentence_to_hello.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" "the whole sentence is replaced with hello" "hello" || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #8. Все предложение целиком между различными знаками должно быть заменено
set /A CurrentTest+=1
set InputFile="8whole_inner_sentence_to_hello.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" "the whole inner sentence is replaced with hello" "hello" || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #9. Не должно удариться в рекурсию
set /A CurrentTest+=1
set InputFile="9shouldnt_fail_recursion.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" ма мама || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #10. Замена подстроки '1231234' в '12312312345'
set /A CurrentTest+=1
set InputFile="10_12312312345.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" 1231234 success || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #11. Замена слова в длинном тексте
set /A CurrentTest+=1
set InputFile="11loremipsum.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" amet privet || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem #11. searchString = ""
set /A CurrentTest+=1
set InputFile="12justempty.txt"
%ReplaceProgram% %InputFile% "%TEMP%\output.txt" "" "zameni" || goto :failed
fc "Expected Output\%InputFile%" "%TEMP%\output.txt" || goto :failed
echo Test %CurrentTest% successful
set /A successful+=1

rem Тесты прошли успешно
echo Tests passed: %successful%/12
echo All tests successful
exit /B 0

:failed
echo Failed test %CurrentTest%
echo Tests passed: %successful%/12
exit /B 1