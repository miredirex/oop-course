#pragma once

#include <string>
#include <fstream>
#include <map>
#include <optional>

class Dictionary
{
public:
    [[nodiscard]]
    std::optional<std::string> GetTranslation(const std::string& word) const;

    void SaveTranslation(const std::string& untranslated, const std::string& translated);

    void Serialize(std::ostream& output) const;

    void Deserialize(std::istream& input, bool clearExistingDictionary);

private:
    const std::string TRANSLATION_DELIMITER = ":\t";

    std::map<std::string, std::string> m_dictionary;
};
