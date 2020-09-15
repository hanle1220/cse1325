#include <iostream>
#include<vector>
#include "tile.h"
#include "board.h"

int main(){
    int num, tile1, tile2, i=1;
    std::vector<std::string> tiles;
    std::cout <<"Number of tiles? ";
    std::cin >> num;
    
    Board b{num};
    
    while(b.solved()== false){
        std::cout << b.to_string();
        std::cout <<"Guest " << i << ", select 2 unmatched tiles: ";
        std::cin >> tile1 >> tile2;
        std::cout << b.attempt(tile1, tile2);
        
        i++;
    }
    std::cout << "You win!";
    
}
