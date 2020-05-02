#include <htmldecode/htmldecode.h>

EntityMap const& GetHtmlEntitiesMap()
{
    static EntityMap htmlEntityMap = {
        {
            { "&quot;", '"' },
            { "&apos;", '\'' },
            { "&lt;",   '<' },
            { "&gt;",   '>' },
            { "&amp;",  '&' }
        }
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
                bool isEntityFound = (html.substr(index, escaped.length()) == escaped);
                // Replace if found
                if (isEntityFound)
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
