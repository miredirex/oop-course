#include "htmldecode.h"

std::unordered_map<std::string, char>& GetHtmlEntitiesMap()
{
    static std::unordered_map<std::string, char> htmlEntityMap = {
            { "&quot;", '"' },
            { "&apos;", '\'' },
            { "&lt;",   '<' },
            { "&gt;",   '>' },
            { "&amp;",  '&' }
    };

    return htmlEntityMap;
}

std::string HtmlDecode(const std::string& html)
{
    std::string decoded;

    auto entities = GetHtmlEntitiesMap();

    auto it = html.begin();
    while (it != html.end())
    {
        bool isEntityReplaced = false;

        // Scan for '&' symbol
        if (*it == ENTITY_IDENTIFIER)
        {
            // If found, iterate through possible entities
            for (const auto&[escaped, unescaped] : entities)
            {
                auto index = it - html.begin();
                // From current index, substr length of possible entity and perform search on that
                size_t escapedOccurrence = html.substr(index, escaped.length()).find(escaped);
                // Replace if found
                if (escapedOccurrence != std::string::npos)
                {
                    decoded += unescaped;
                    it += escaped.length();
                    isEntityReplaced = true;

                    break;
                }
            }
        }

        if (!isEntityReplaced)
        {
            decoded += *it;
            ++it;
        }
    }

    return decoded;
}
