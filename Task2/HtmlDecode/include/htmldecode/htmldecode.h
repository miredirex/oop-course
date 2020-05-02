#ifndef HTMLDECODE_H
#define HTMLDECODE_H

#include <string>
#include <array>

const char ENTITY_IDENTIFIER = '&';
const size_t ENTITIES_COUNT = 5u;
using EntityMap = std::array<std::pair<std::string, char>, ENTITIES_COUNT>;

EntityMap const& GetHtmlEntitiesMap();

std::string HtmlDecode(std::string const& html);

#endif //HTMLDECODE_H
