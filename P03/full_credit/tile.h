#include<string>
#ifndef __TILE_H 
#define __TILE_H

class Tile { 
    std::string _word;
    bool _matched = false;
    int _width = -1;
    std::string _blank;
  public:
    Tile(std::string word);
    bool match(Tile& tile);
    std::string word();
    int width();
    std::string to_string();
};

#endif
