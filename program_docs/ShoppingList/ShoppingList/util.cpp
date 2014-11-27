#include "util.h"
#include <cctype>


std::string string_to_lower(const std::string& s)
{
    std::string newString = s;

    for (int i = 0; i < newString.length(); i++)
        newString[i] = tolower(newString[i]);
    return newString;
}
