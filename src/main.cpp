#include <fmt/core.h>

#include "braceexpansion.h"
#include <iostream>
#include <string>


int main()
{
    std::string input;
    std::cin >> input;
    std::cout << BraceExpansion::braceExpansion(input);
    return 0; // No specifications on exit code
}