#include <StringUtils.h>
#include <algorithm>

std::string stringutils::ToLowerCase(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
    {
        return std::tolower(c);
    });

    return str;
}