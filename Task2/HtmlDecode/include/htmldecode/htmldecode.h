#ifndef HTMLDECODE_H
#define HTMLDECODE_H

#include <string>
#include <unordered_map>

std::string HtmlDecode(std::string const& html);

std::unordered_map<std::string, char>& GetHtmlEntitiesMap();

const char ENTITY_IDENTIFIER = '&';

#endif //HTMLDECODE_H
