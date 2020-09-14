#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "tile.h"
#include "board.h"
#include<string>

std::vector<std::string> words {"bang", "beam", "bear", "cafe", "came",
                                "cold", "come", "cool", "date", "diet",
                                "door", "doth", "echo", "exes", "exit",
                                "face", "fame", "feed", "fire", "five",
                                "four", "free", "frog", "from", "game",
                                "goes", "good", "grit", "have", "heal",
                                "hear", "here", "hide", "hole", "home",
                                "hope", "huge", "keep", "kill", "lace",
                                "lame", "leek", "life", "live", "maps",
                                "mass", "mate", "maze", "move", "near",
                                "need", "nine", "once", "quit", "ques",
                                "race", "read", "reed", "reef", "rice",
                                "roof", "sins", "stay", "tame", "teen",
                                "tens", "tide", "tied", "tree", "twin",
                                "zero", "zips",};

Board::Board(int tiles) {
    std::random_shuffle( words.begin(), words.end());
    for (int i=0; i<tiles/2; i++) {_tiles.push_back(words[i]); _tiles.push_back(words[i]);}
    std::random_shuffle( _tiles.begin(), _tiles.end());
}

std::string Board::attempt(int tile1, int tile2){
    Tile t1{_tiles[tile1]};
    Tile t2{_tiles[tile2]};
    if (t1.match(t2)){return _tiles[tile1].word()+ "MATCHES" +_tiles[tile2].word();}
    else {return _tiles[tile1].word() + " " +_tiles[tile2].word();}
}

bool Board::solved() {
    if(Board::to_string().find("-") != 0) return false;
    else return true;
}

std::string Board::to_string(){ 
    std::string s;    
    for(int i=0; i<_tiles.size(); i++) 
        s += std::to_string(i) + ") " + Tile::to_string() + "\n";
    return s;
}



    
    
















