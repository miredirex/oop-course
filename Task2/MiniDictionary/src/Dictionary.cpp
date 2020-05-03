#include <dictionary/Dictionary.h>

std::optional<std::string> Dictionary::GetTranslation(const std::string& word) const
{
    bool containsKey = m_dictionary.find(word) != m_dictionary.end();
    return containsKey ? std::optional(m_dictionary.at(word)) : std::nullopt;
}

void Dictionary::SaveTranslation(const std::string& untranslated, const std::string& translated)
{
    m_dictionary.insert({ untranslated, translated });
}

void Dictionary::Serialize(std::ofstream& output) const
{
    for (const auto&[word, translation] : m_dictionary)
    {
        output << word << TRANSLATION_DELIMITER << translation << std::endl;
    }
}

void Dictionary::Deserialize(std::ifstream& input, bool clearExistingDictionary)
{
    if (clearExistingDictionary)
    {
        m_dictionary.clear();
    }

    std::string line;
    while (std::getline(input, line))
    {
        size_t delimiterIndex = line.find(TRANSLATION_DELIMITER);

        if (delimiterIndex == std::string::npos)
        {
            continue;
        }

        std::string untranslated = line.substr(0, delimiterIndex);
        std::string translated = line.substr(delimiterIndex + TRANSLATION_DELIMITER.size(), line.size());

        m_dictionary.insert({ untranslated, translated });
    }
}
