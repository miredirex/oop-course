#pragma once

#include <string>
#include <iostream>
#include <dictionary/Dictionary.h>
#include <dictionary/DictionaryIO.h>

class DictionaryApplication
{
public:
    explicit DictionaryApplication(Dictionary& dictionary) : m_dictionary(dictionary) {};

    void RequestTranslation(const std::string& wordToTranslate);

    void RequestSavingDictionary(const char* filename) const;

    bool HasUnsavedChanges() const;

private:
    Dictionary& m_dictionary;
    bool m_hasUnsavedChanges = false;
};