#include <iostream>
#include "tile.h"
#include "board.h"

int main(){
    int num, tile1, tile2, i=1;
    char s;    //char sp =" ";
    std::cout <<"Number of tiles? ";
    std::cin >> num;
    
    Board b{num};
  
    
    while(b.solved()== false){
        std::cout << b.to_string();
        std::cout <<"Guest " << i << ", select 2 unmatched tiles: ";
        std::cin >> tile1 >> s >> tile2;
        b.attempt(tile1, tile2);

    }
    std::cout << "You win!";
    
}
