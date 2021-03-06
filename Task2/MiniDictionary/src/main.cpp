#include <iostream>
#include <dictionary/Dictionary.h>
#include <dictionary/DictionaryIO.h>
#include <dictionary/DictionaryApplication.h>

using namespace std;

struct Arg
{
    const char* dictionaryFileName;
};

optional<Arg> ParseArgs(int argc, char* argv[])
{
    if (argc < 2) return nullopt;
    return Arg { argv[1] };
}

const char* INPUT_LOOP_TERMINATOR = "...";

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Dictionary dictionary;
    DictionaryApplication dictionaryApp(dictionary);

    optional<Arg> arg = ParseArgs(argc, argv);

    if (arg.has_value())
    {
        DeserializeDictionaryFromFile(arg->dictionaryFileName, dictionary);
    } else
    {
        cout << "Запуск программы должен происходить с параметром: MiniDictionary.exe <текстовый_файл.txt>\n";
        return 1;
    }

    string userInput;
    while (getline(cin, userInput))
    {
        if (userInput == INPUT_LOOP_TERMINATOR)
        {
            break;
        }

        optional<string> translation = dictionary.GetTranslation(userInput);
        if (translation.has_value())
        {
            cout << *translation << '\n';
        } else
        {
            dictionaryApp.RequestTranslation(userInput);
        }
    }

    if (dictionaryApp.HasUnsavedChanges())
    {
        DictionaryApplication::RequestSavingChanges([&](bool hasUserAgreed)
        {
            if (hasUserAgreed)
            {
                SerializeDictionaryToFile(arg->dictionaryFileName, dictionary);
            }
        });
    }

    return 0;
}
