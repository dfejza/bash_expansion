#include "braceexpansion.h"

#include <iostream>
#include <sstream>
#include <vector>

// Is acii alphabet character
bool BraceExpansion::isAlphabetChar(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

/* Iterate through the input, ensures:
    1. # of brackets
    2. ',' placement
*/
bool BraceExpansion::isValidInput(std::string& input) {
    unsigned long strSize = static_cast<unsigned long>(input.size());
    bool isValid          = true;
    if (strSize <= 2) {
        isValid = false;
    }
    int braceCounter      = 0;
    bool braceEncountered = false;
    for (unsigned long i = 0; i < input.size(); ++i) {
        if (input[i] == '{') {
            ++braceCounter;
            braceEncountered = true;
        } else if (input[i] == '}') {
            if (braceCounter <= 0) {
                isValid = false;
                break;
            }
            --braceCounter;
        } else if (input[i] == ',') {
            if (i >= strSize - 1 || isAlphabetChar(input[i + 1]) == false || braceCounter <= 0) {
                isValid = false;
                break;
            }
        } else if (isAlphabetChar(input[i]) == false) {
            isValid = false;
            break;
        }
    }

    if (braceCounter != 0 || braceEncountered == false) {
        isValid = false;
    }

    return isValid;
}

// clear the buffer for given ostringstream
// https://stackoverflow.com/questions/5288036/how-to-clear-ostringstream
void clearBuffer(std::ostringstream& os) {
    os.str("");
    os.clear();
}

std::string BraceExpansion::braceExpansion(std::string& input) {
    unsigned long strSize = static_cast<unsigned long>(input.size());
    if (isValidInput(input) == false) {
        return std::string("");
    }
    // output buffer
    std::ostringstream resBuffer;
    // currect substring buffer
    std::ostringstream tmpBuffer;
    // Maintain the 'prefixes' encountered before each open brace
    std::vector<std::string> prefixStack;
    for (unsigned long i = 0; i < strSize; ++i) {
        if (input[i] == '{') {
            // If the current buffer isnt empty, allow it to be the 'prefix'
            // for upcomming inner buffers
            if (tmpBuffer.tellp() != 0) {
                prefixStack.push_back(tmpBuffer.str());
                clearBuffer(tmpBuffer);
            }
        } else if (input[i] == '}' || input[i] == ',') {
            // No characters inbetween case eg '{b{a}}'
            if (tmpBuffer.tellp() == 0) {
                continue;
            }
            // If the first buffer, do not preceed with a space
            if (resBuffer.tellp() != 0) {
                resBuffer << ' ';
            }
            // apply all prefixes to current buffer
            for (std::string& s : prefixStack) {
                resBuffer << s;
            }
            resBuffer << tmpBuffer.str();
            clearBuffer(tmpBuffer);
            if (input[i] == '}' && prefixStack.size() > 0) {
                prefixStack.pop_back();
            }
        } else {
            tmpBuffer << input[i];
        }
    }

    resBuffer << "\n"; // LF
    return resBuffer.str();
}