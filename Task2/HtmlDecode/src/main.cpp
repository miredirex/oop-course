#include <iostream>
#include <string>
#include "htmldecode.h"

int main()
{
    std::string input;
    while (std::getline(std::cin, input))
    {
        std::string decodedString = HtmlDecode(input);
        std::cout << decodedString << std::endl;
    }

    return 0;
}
