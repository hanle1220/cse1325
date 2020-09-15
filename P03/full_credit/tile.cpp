#include <iostream> 
#include<string>
#include "tile.h"
#include "board.h"

Tile::Tile(std::string word) : _word{word}{for(int i=0; i<width(); i++) {_blank += '-';}}

bool Tile::match(Tile& tile){    
    if(_word == tile._word) {_matched = true;}
    return _matched;
}

std::string Tile::word() {return _word;}

int Tile::width() {_width = _word.length(); return _width;}

std::string Tile::to_string(){ 
    if(_matched == true) {return _word;}
    else {        
        return _blank;
    }
}

















