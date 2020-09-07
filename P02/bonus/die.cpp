#include <ctime>
#include <iostream>
#include "die.h"

Die::Die(int faces) {
    _faces = faces;
}

int Die::faces(){
    return _faces; 
}

int Die::value(){
    _value = rand()%_faces+1;
    return _value;
}

void Die::roll(){
    std::cout<< _value << " ";
}

