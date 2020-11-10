#include "order.h"
#include <fstream>

Order::Order(const Customer& customer) : customer{customer} { }

Order::~Order() { }

void Order::add_item(Item& item){
    items.push_back(new Item{item}); 
}

double Order::total(){
    for(int i =0; i< items.size(); i++)  _total += items[i]->subtotal();
    return _total;
}

std::string Order::to_string() const{
    std::string s;
    s = "For Customer " + customer.to_string() + "\t$" + std::to_string(_total);
         
    return s;
}

std::ostream& operator<<(std::ostream& ost,const Order& order) {
    ost << order.to_string() << "\n";
    return ost;
}





