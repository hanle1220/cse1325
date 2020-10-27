#include "plant.h"

Plant::Plant(std::string name, double price, std::string description, std::string species, Exposure exposure)
    : Product(name, price, description), _species{species}, _exposure{exposure} { }
std::string Plant::to_string() const {
    return Product::to_string() + "\n  Species: " + _species + "\n  Exposure: " + ::to_string(_exposure);
}
std::ostream& operator<<(std::ostream& ost, const Exposure& exposure) {
    ost << to_string(exposure);
    return ost;
}
std::string to_string(Exposure exposure) {
    if(exposure == Exposure::SHADE) return "shade";
    else if(exposure == Exposure::PARTSUN) return "part sun";
    else if(exposure == Exposure::SUN) return "full sun";
    else throw std::out_of_range("Invalid Exposure value");
}

Exposure Plant::_string(std::string exposure) {
    if(exposure == "shade") return Exposure::SHADE;
    else if(exposure == "part sun") return Exposure::PARTSUN;
    else if(exposure == "full sun") return Exposure::SUN;
    else throw std::out_of_range("Invalid Exposure value");
}

Plant::Plant(std::istream& ist) : Product(ist){
    std::string expo;
    getline(ist, _species);
    getline(ist, expo); 
    _exposure = Plant::_string(expo);
}

void Plant::save(std::ostream& ost){
    ost << "plant"<< std::endl; 
    Product::save(ost);   
    ost << _species << std::endl;
    ost << ::to_string(_exposure) << std::endl;

}
