#include <iostream>
#include <stdexcept>
#include "Board.hpp"

void ariel::Board::post(unsigned int row, unsigned int column,Direction d, string s){
    string e = "Invalid argument - row and column should be numbers greater than 0";
    if (row < 0 || column < 0){
        throw invalid_argument(e);
    }

}

string ariel::Board::read(unsigned int row, unsigned int column,Direction d,int length){
    string e = "Invalid argument - row and column should be numbers greater than 0";
    if (row < 0 || column < 0){
        throw invalid_argument(e);
    }

    return "ans";
}

ariel::Board& ariel::Board::show(){
    Board& b = *this;
    return b;
}

ariel::Board::~Board(){
    delete board;
}