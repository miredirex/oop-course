#pragma once

#include <string>
#include <dictionary/Dictionary.h>
#include <dictionary/DictionaryIO.h>

class DictionaryApplication
{
public:
    explicit DictionaryApplication(Dictionary& dictionary) : m_workingDictionary(dictionary) {};

    void RequestTranslation(const std::string& wordToTranslate);

    void RequestSavingDictionary(const char* filename) const;

    [[nodiscard]]
    bool HasUnsavedChanges() const;

private:
    Dictionary& m_workingDictionary;
    bool m_hasUnsavedChanges = false;
};