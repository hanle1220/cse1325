#include "store.h"
#include "customer.h"
#include <iostream>
#include <fstream>

Store::Store(std::string name) : _name{name} { }
void Store::add_product(const Tool& product) {_products.push_back(new Tool{product}); }
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
Product& Store:: product(int index) {return *_products.at(index);}

void Store::add_customer(const Customer& customer) {
    _customers.push_back(new Customer{customer}); 
    std::sort(_customers.begin(),_customers.end(), [ ](const Customer* c1, Customer* c2) -> bool {
            return c1->getName() < c2->getName();   });
}

int Store::customers() {return _customers.size();}
const Customer& Store::customer(int index) {return *_customers.at(index);}

std::string Store::name() {return _name;}

int Store::add_order( const Customer& customer){
    _orders.push_back(new Order{customer});
    i++;
    return i;
}

void Store::add_item(int order, Product& product, int quantity){
    _orders[order]->add_item( Item {product, quantity});
}

std::vector<Order*>::iterator Store::begin() {return _orders.begin();}
std::vector<Order*>::iterator Store::end() {return _orders.end();}

void Store::save(std::ostream& ost){
    ost << _name << std::endl;
    for(Product* p : _products) p->save(ost); 
    for(Customer* c: _customers) c->save(ost);
    for(Order* o: _orders) o->save(ost);
}

Store::Store(std::istream& ist){   
    std::getline(ist, _name);
    std::string type;
    while(std::getline(ist, type)){
        if (type == "tool") { add_product(*(new Tool{ist})); }
        if (type == "plant") { add_product(*(new Plant{ist}));}
        if (type == "mulch") { add_product(*(new Mulch{ist}));}     
        if (type == "customer") {add_customer(*(new Customer{ist}));} 
        if (type == "order") { std::getline(ist, type) ; _orders.push_back(new Order{ist});}
    }  
}

