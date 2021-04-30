#include <catch2/catch.hpp>

#include "braceexpansion.h"
#include <string>
#include <vector>
#include <utility>


TEST_CASE("Is char")
{
  REQUIRE(BraceExpansion::isAlphabetChar('a') == true);
  REQUIRE(BraceExpansion::isAlphabetChar('z') == true);
  REQUIRE(BraceExpansion::isAlphabetChar('A') == true);
  REQUIRE(BraceExpansion::isAlphabetChar('Z') == true);
  REQUIRE(BraceExpansion::isAlphabetChar('1') == false);
  REQUIRE(BraceExpansion::isAlphabetChar(' ') == false);
}


TEST_CASE("Valid brace expansion formatting")
{
    using namespace std;
    using TestEntry = pair<string,bool>;
    vector<TestEntry> testSet{TestEntry(string("}ABC"),false),
        TestEntry(string("}ABC"),false),
        TestEntry(string("{ABC"),false),
        TestEntry(string("}{"),false),
        TestEntry(string("{}"),false),
        TestEntry(string("a,B,c"),false),
        TestEntry(string("{A{B,C}"),false),
        TestEntry(string("{A,}"),false),
        TestEntry(string(""),false),
        TestEntry(string("{A}"),true),
        TestEntry(string("{A,B}"),true),
        TestEntry(string("{A,B{C}}"),true),
        TestEntry(string("{A,B{C{D{E{F}}}}}"),true)};
    
    for(auto it = testSet.begin(); it != testSet.end(); ++it) {
        INFO(it->first);
        REQUIRE(BraceExpansion::isValidInput(it->first) == it->second);
    }
}

TEST_CASE("Valid brace expansion")
{
    using namespace std;
    using TestEntry = pair<string,string>;
    vector<TestEntry> testSet{TestEntry(string(""),string("")),
        TestEntry(string("{}"),string("")),
        TestEntry(string("{"),string("")),
        TestEntry(string("{a}"),string("a\n")),
        TestEntry(string("{aA}"),string("aA\n")),
        TestEntry(string("{a{b}}"),string("ab\n")),
        TestEntry(string("a{b{d,c,b},c}"),string("abd abc abb ac\n")),
        TestEntry(string("a{z,b{d,c,b},c}"),string("az abd abc abb ac\n")),
        TestEntry(string("a{z,b{d,c,b}}"),string("az abd abc abb\n"))};
    
    for(auto it = testSet.begin(); it != testSet.end(); ++it) {
        INFO(it->first);
        REQUIRE(BraceExpansion::braceExpansion(it->first) == it->second);
    }
}