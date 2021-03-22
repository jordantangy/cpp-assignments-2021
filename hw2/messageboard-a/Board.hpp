#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Direction.hpp"
namespace ariel{

class Board{
    public:
    vector<vector<char>>* board;
    Board(){
        board = {};
    }
    static void post(unsigned int row, unsigned int column,Direction d,const string &s);  
    static string read(unsigned int row, unsigned int column,Direction d,int length);
    Board& show();
    ~Board();
};

}
