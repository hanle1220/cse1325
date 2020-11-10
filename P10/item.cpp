 #include "item.h"

Item::Item(const Product& product, int quantity) : quantity{quantity}{  }

Item::~Item(){ }

double Item::subtotal(){ return _product->price() * quantity;}

std::string Item::to_string() const {
    return std::to_string(quantity) ;
}
std::ostream& operator<<(std::ostream& ost, const Item& item) {
    ost << item.to_string();
    return ost;
}

Item::Item(std::istream ist){
    ist >> quantity;
    ist.ignore(32767,'\n');
}

void Item::save(std::ostream ost){
    ost << quantity << std::endl;
    _product->save(ost);
}

