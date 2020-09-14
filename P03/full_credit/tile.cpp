#include <iostream> 
#include<string>
#include "tile.h"
#include "board.h"

Tile::Tile(std::string word) : _word{word}{ 
    _matched = false;
    for(int i=0; i<Tile::width(); i++) {_blank = '-';}
    if(word.length() > _width){
        _width = word.length();
        for(int i=0; i<_width; i++) {_blank = '-';}
    }
}

bool Tile::match(Tile& tile){    
    if(_word == tile._word) {_matched = true;}
    return _matched;
}

std::string Tile::word() {return Tile::_word;}

int Tile::width() {_width = _word.length(); return _width;}

std::string Tile::to_string(){ 
    if(_matched == true) {return Tile::_word;}
    else {return _blank;}
}

















