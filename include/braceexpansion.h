#ifndef BRACEEXPANSION_H
#define BRACEEXPANSION_H

#include <string>

// Keep functions public for the sake of UT.
// Would realistically only expose braceExpansion, and perhaps
//     move other functions to a helper class
class BraceExpansion {
public:
    static bool isAlphabetChar(char c);
    static bool isValidInput(std::string& input);
    static std::string braceExpansion(std::string& input);
};

#endif // BRACEEXPANSION_H