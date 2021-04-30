#include <fmt/core.h>

#include "braceexpansion.h"
#include <iostream>
#include <string>

// Example input given is 
//    echo "{A,B,C}" | your_program
// Does not expect input in the form of an argument
int main()
{
    std::string input;
    std::cin >> input;
    std::cout << BraceExpansion::braceExpansion(input);
    return 0; // No specifications on exit code
}