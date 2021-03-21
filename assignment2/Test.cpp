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
#include "Board.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;
using ariel::Direction;


/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */


TEST_CASE("post and read function") {

ariel::Board board;

CHECK_NOTHROW(board.post(50, 20, Direction::Horizontal, "hello"));
CHECK_NOTHROW(board.post(200, 200, Direction::Horizontal, "giving math classes"));
CHECK(board.read(49, 21, Direction::Vertical, 3) == "_h_");
CHECK_NOTHROW(board.post(10, 100, Direction::Horizontal, "selling my piano"));
CHECK_NOTHROW(board.post(9, 100, Direction::Horizontal, "selling my phone"));
CHECK(board.read(10, 100, Direction::Horizontal, 16) == "selling my piano");
CHECK(board.read(8, 100, Direction::Horizontal, 10) == "__selling my pi");
CHECK(board.read(10, 111, Direction::Horizontal, 10) == "piano");
CHECK(board.read(8, 100, Direction::Horizontal, 20) == "__selling my piano__");
CHECK(board.read(9, 109, Direction::Vertical, 2) == "mm");
CHECK(board.read(9, 109, Direction::Vertical, 4) == "_mm_");
CHECK(board.read(9, 109, Direction::Vertical, 5) == "_mm__");
CHECK(board.read(10, 110, Direction::Vertical, 2) == "yy");
CHECK(board.read(9, 110, Direction::Vertical, 4) == "_yy_");
CHECK(board.read(10, 112, Direction::Vertical, 2) == "pp");
CHECK(board.read(9, 112, Direction::Vertical, 4) == "_pp_");
CHECK(board.read(9, 112, Direction::Vertical, 5) == "_pp__");
CHECK(board.read(10, 111, Direction::Horizontal, 10) == "phone");
CHECK(board.read(10, 112, Direction::Horizontal, 10) == "hone");
CHECK(board.read(10, 113, Direction::Horizontal, 10) == "one");
CHECK(board.read(200, 200, Direction::Horizontal, 19) == "giving math classes");
CHECK(board.read(200, 207, Direction::Horizontal, 4) == "math");




}

