 #include<vector>
#include<string>
#ifndef __BOARD_H 
#define __BOARD_H

class Board{    
    std::vector<Tile> _tiles;
  public:
    Board(int tiles);
    std::string attempt(int tile1, int tile2);
    bool solved();
    std::string to_string();
};    

#endif
