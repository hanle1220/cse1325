#include <ctime>
#include <iostream>
#include "die.h"

int main(){
    srand(time(NULL));
    int dice, face, roll;
   

    std::cout << "Number of dice? " ;
    std::cin >> dice;

    std::cout<< "Number of faces per dice? ";
    std::cin >> face;

    std::cout << "Number of rolls? " ; 
    std::cin >> roll;

    Die d {face};

    for(int i=0; i<roll; i++){
         int sum=0;         
         std::cout << "Roll " << i << ": ";
         for(int j=0; j<dice; j++){
            sum += d.value();
            d.roll();
          } std::cout << "Sum: "<< sum << std::endl;

    }

}  
