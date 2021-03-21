/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Jordan Tangy
 * 
 * Date: 10-03-2021
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */

string nospaces(string input) {
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	input.erase(std::remove(input.begin(), input.end(), '\t'), input.end());
	input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
	input.erase(std::remove(input.begin(), input.end(), '\r'), input.end());
	return input;
}



TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(33232124)) == nospaces("_\n/_\\\n\\(o_O)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(41442214)) == nospaces("___\n(_*_)\n\\(-,-)/\n( : )\n(   )"));
    CHECK(nospaces(snowman(11442214)) == nospaces("_===_\n(_*_)\n\\(-,-)/\n( : )\n(   )"));
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41114411)) == nospaces("(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n( ] [ )\n( : )"));
    CHECK(nospaces(snowman(11114422)) == nospaces("_===_\n(.,.)\n( ] [ )\n( " " )"));
    CHECK(nospaces(snowman(11114423)) == nospaces("_===_\n(.,.)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21114423)) == nospaces("___\n.....\n(.,.)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21224423)) == nospaces("___\n.....\n(o,o)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21234423)) == nospaces("___\n.....\n(o,O)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21324423)) == nospaces("___\n.....\n(O,o)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21334423)) == nospaces("___\n.....\n(O,O)\n( ] [ )\n( __ )"));
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(4561));
    CHECK_THROWS(snowman(45617));
    CHECK_THROWS(snowman(6));
    CHECK_THROWS(snowman(21334425));
    CHECK_THROWS(snowman(110100000));
    CHECK_THROWS(snowman(-21334423));
    CHECK_THROWS(snowman(0000000000));
    
}


TEST_CASE("No armed snowmans") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(31114411)) == nospaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41114411)) == nospaces("(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n( ] [ )\n( : )"));
    CHECK(nospaces(snowman(11114422)) == nospaces("_===_\n(.,.)\n( ] [ )\n( " " )"));
    CHECK(nospaces(snowman(11114423)) == nospaces("_===_\n(.,.)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(11224423)) == nospaces("_===_\n(o,o)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(112314423)) == nospaces("_===_\n(o,O)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(11324423)) == nospaces("_===_\n(O,o)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(13114423)) == nospaces("_===_\n(._.)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21114423)) == nospaces("___\n.....\n(.,.)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21224423)) == nospaces("___\n.....\n(o,o)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21234423)) == nospaces("___\n.....\n(o,O)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21324423)) == nospaces("___\n.....\n(O,o)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21334423)) == nospaces("___\n.....\n(O,O)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(21234413)) == nospaces("___\n.....\n(o,O)\n( : )\n( __ )"));
    CHECK(nospaces(snowman(21324413)) == nospaces("___\n.....\n(O,o)\n( : )\n( __ )"));
}

TEST_CASE("snowmans not corresponding"){

CHECK(nospaces(snowman(11114411)) != nospaces("___\n.....\n(O,o)\n( ] [ )\n( __ )"));
CHECK(nospaces(snowman(31114411)) != nospaces("___\n.....\n(O,O)\n( ] [ )\n( __ )"));
CHECK(nospaces(snowman(11114421)) != nospaces("_===_\n(._.)\n( ] [ )\n( __ )"));
CHECK(nospaces(snowman(112314423)) !=  nospaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
CHECK(nospaces(snowman(21234423)) != nospaces("_===_\n(O,o)\n( ] [ )\n( __ )"));
CHECK(nospaces(snowman(11324423)) !=  nospaces("___\n.....\n(O,O)\n( ] [ )\n( __ )"));
CHECK(nospaces(snowman(21114423)) !=  nospaces("___\n.....\n(O,o)\n( : )\n( __ )"));

}

TEST_CASE("No headed snowman"){


    CHECK(nospaces(snowman(41114411)) == nospaces("(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(43232124)) == nospaces("\\(o_O)\n(] [)>\n(   )"));
    CHECK(nospaces(snowman(41442214)) == nospaces("(_*_)\n\\(-,-)/\n( : )\n(   )"));
    CHECK(nospaces(snowman(41442214)) == nospaces("(_*_)\n\\(-,-)/\n( : )\n(   )"));
    CHECK(nospaces(snowman(43114411)) == nospaces("(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41114411)) == nospaces("(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41114421)) == nospaces("(.,.)\n( ] [ )\n( : )"));
    CHECK(nospaces(snowman(41114422)) == nospaces("(.,.)\n( ] [ )\n( " " )"));
    CHECK(nospaces(snowman(41114423)) == nospaces("(.,.)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(41114423)) == nospaces("(.,.)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(41224423)) == nospaces("(o,o)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(41234423)) == nospaces("(o,O)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(41324423)) == nospaces("(O,o)\n( ] [ )\n( __ )"));
    CHECK(nospaces(snowman(41334423)) == nospaces("(O,O)\n( ] [ )\n( __ )"));



}
