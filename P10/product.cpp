
#include "product.h"
#include <cmath>

Product::Product(std::string name, double price, std::string description)
    : _name{name}, _price{price}, _description{description}, _stocknum{++_nextsn} { }

std::string Product::to_string() const {
    return _name + " (Stock# " + std::to_string(_stocknum)
                 + ", $" + std::to_string(round(_price*100)/100) + ")\n  "
                 + _description;
}
std::ostream& operator<<(std::ostream& ost, const Product& product) {
    ost << product.to_string();
    return ost;
}
int Product::_nextsn = 0;

double Product::price() {return _price;}

Product::Product(std::istream& ist){
    ist >> _nextsn; 
    ist.ignore(32767,'\n');
    std::getline(ist, _name);
    ist >> _stocknum;
    ist.ignore(32767,'\n');
    ist >> _price; 
    ist.ignore(32767,'\n');
    std::getline(ist, _description);
}

void Product::save(std::ostream& ost){
    ost << _nextsn << std::endl;
    ost << _name << std::endl;   
    ost << _stocknum << std::endl;
    ost << _price << std::endl;
    ost << _description << std::endl;
}
