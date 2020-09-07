#include <ctime>
#include <iostream>
#include "die.h"

int main(){

	srand(time(NULL));
    Die d1(4);
    Die d2(6);
    Die d3(8);
    Die d4(12);
    Die d5(20);
	
    std::cout<< "d" << d1.faces()<<": ";
	for(int i=0; i<20; i++){ std::cout<< d1.value()<<" ";}

    std::cout<< "\nd6: ";
	for(int i=0; i<20; i++){ std::cout<< d2.value()<<" ";}

    std::cout<< "\nd8: ";
	for(int i=0; i<20; i++){ std::cout<< d3.value()<<" ";}

    std::cout<< "\nd12: ";
	for(int i=0; i<20; i++){ std::cout<< d4.value()<<" ";}

    std::cout<< "\nd20: ";
	for(int i=0; i<20; i++){ std::cout<< d5.value()<<" ";}

    std::cout<< std::endl;

}
