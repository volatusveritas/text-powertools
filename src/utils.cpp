#include "utils.hpp"

#include <cctype>
#include <string>

#include "shortcuts.hpp"


namespace TextPowertools {


bool 
isWord(const std::string &sourceStr)
{
    for (char character : sourceStr)
    {
        if (!isAlphabetic(character)) return false;
    }

    return true;
}


bool 
isWordExtended(const std::string &sourceStr)
{
    for (char character : sourceStr)
    {
        if (!isGraphical(character)) return false;
    }

    return true;
}


bool 
isNumber(const std::string &sourceStr)
{
    for (char character : sourceStr)
    {
        if (!isDigit(character)) return false;
    }

    return true;
}


strSize
getWordEnd(const std::string &sourceStr, strSize startIndex)
{
    strSize endIndex {startIndex};
    for (strSize i {startIndex + 1}; i < sourceStr.length(); i++)
    {
        if (!isAlphabetic(sourceStr[i])) break;
        endIndex++;
    }

    if (
        endIndex < sourceStr.length() - 1
        && isPunctuation(sourceStr[endIndex + 1])
    ) endIndex++;

    return endIndex;
}


}  // namespace TextPowertools
