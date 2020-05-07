#pragma once

#include <string>
#include <dictionary/Dictionary.h>
#include <dictionary/DictionaryIO.h>
#include <functional>

class DictionaryApplication
{
public:
    explicit DictionaryApplication(Dictionary& dictionary) : m_workingDictionary(dictionary) {};

    void RequestTranslation(const std::string& wordToTranslate);

    static void RequestSavingChanges(const std::function<void(bool)>& hasUserAgreedCallback);

    [[nodiscard]]
    bool HasUnsavedChanges() const;

private:
    Dictionary& m_workingDictionary;
    bool m_hasUnsavedChanges = false;
};