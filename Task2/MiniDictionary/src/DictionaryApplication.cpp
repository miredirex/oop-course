#include <dictionary/DictionaryApplication.h>
#include <iostream>
#include <functional>

void DictionaryApplication::RequestTranslation(const std::string& wordToTranslate)
{
    std::cout << "Неизвестное слово \"" << wordToTranslate << "\". Введите перевод или пустую строку для отказа.\n";

    std::string userTranslation;
    getline(std::cin, userTranslation);
    if (userTranslation.empty())
    {
        std::cout << "Слово \"" << wordToTranslate << "\" проигнорировано.\n";
    } else
    {
        m_workingDictionary.SaveTranslation(wordToTranslate, userTranslation);
        m_hasUnsavedChanges = true;

        std::cout << "Слово \"" << wordToTranslate << "\" сохранено в словаре как \"" << userTranslation << "\"\n";
    }
}

void DictionaryApplication::RequestSavingChanges(const std::function<void(bool)>& hasUserAgreedCallback)
{
    std::cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";

    std::string action;
    getline(std::cin, action);

    bool hasUserAgreed = ( !action.empty() && tolower(action[0]) == 'y' );
    hasUserAgreedCallback(hasUserAgreed);
}

bool DictionaryApplication::HasUnsavedChanges() const
{
    return m_hasUnsavedChanges;
}
