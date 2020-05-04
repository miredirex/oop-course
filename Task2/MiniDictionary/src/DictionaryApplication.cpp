#include <dictionary/DictionaryApplication.h>
#include <iostream>

void DictionaryApplication::RequestTranslation(const std::string& wordToTranslate)
{
    printf("Неизвестное слово \"%s\". Введите перевод или пустую строку для отказа.\n", wordToTranslate.c_str());

    std::string userTranslation;
    getline(std::cin, userTranslation);
    if (userTranslation.empty())
    {
        printf("Слово \"%s\" проигнорировано.\n", wordToTranslate.c_str());
    } else
    {
        m_workingDictionary.SaveTranslation(wordToTranslate, userTranslation);
        m_hasUnsavedChanges = true;

        printf("Слово \"%s\" сохранено в словаре как \"%s\"\n", wordToTranslate.c_str(), userTranslation.c_str());
    }
}

void DictionaryApplication::RequestSavingDictionary(const char* filename) const
{
    printf("В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n");

    std::string action;
    getline(std::cin, action);
    if (!action.empty() && tolower(action[0]) == 'y')
    {
        SerializeDictionaryToFile(filename, m_workingDictionary);
    }
}

bool DictionaryApplication::HasUnsavedChanges() const
{
    return m_hasUnsavedChanges;
}
