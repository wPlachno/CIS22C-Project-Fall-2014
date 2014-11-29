#include "util.h"
#include <cctype>


/** Make a copy of a string in all lower case characters.
@param s The string to convert
@return A copy of the input string in lower case characters.
*/

std::string string_to_lower(const std::string& s)
{
    std::string newString = s;

    for (int i = 0; i < newString.length(); i++)
        newString[i] = tolower(newString[i]);
    return newString;
}
