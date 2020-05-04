#include <dictionary/Dictionary.h>
#include <StringUtils.h>
#include <algorithm>

using namespace stringutils;

std::optional<std::string> Dictionary::GetTranslation(const std::string& word) const
{
    std::string wordLowerCase = ToLowerCase(word);

    bool containsKey = m_dictionary.find(wordLowerCase) != m_dictionary.end();
    return containsKey ? std::optional(m_dictionary.at(wordLowerCase)) : std::nullopt;
}

void Dictionary::SaveTranslation(const std::string& untranslated, const std::string& translated)
{
    m_dictionary.insert({ ToLowerCase(untranslated), translated });
}

void Dictionary::Serialize(std::ostream& output) const
{
    for (const auto&[word, translation] : m_dictionary)
    {
        output << word << TRANSLATION_DELIMITER << translation << std::endl;
    }
}

void Dictionary::Deserialize(std::istream& input, bool clearExistingDictionary)
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

bool Dictionary::IsEmpty() const
{
    return m_dictionary.empty();
}
