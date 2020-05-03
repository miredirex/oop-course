#pragma once

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <optional>

//todo: using TranslationMap = std::map<std::string, std::vector<std::string>>;

class Dictionary
{
public:
    [[nodiscard]] std::optional<std::string> GetTranslation(const std::string& word) const;

    void SaveTranslation(const std::string& untranslated, const std::string& translated);

    void Serialize(std::ofstream& output) const;

    void Deserialize(std::ifstream& input, bool clearExistingDictionary);

private:
    const std::string TRANSLATION_DELIMITER = ":\t";

    std::map<std::string, std::string> m_dictionary;
};
