#ifndef __ORDER_H
#define __ORDER_H
   
#include "item.h"
#include "customer.h"
#include <vector>
class Order{
    public:
        Order( const Customer& customer);
        virtual ~Order();
        friend std::ostream& operator<<(std::ostream& ost, const Order& order);
        std::string to_string() const;
        Order(std::istream& ist);
        void save(std::ostream& ost);
        void add_item( Item& item);
        double total() ;
    private:
        std::vector<Item*> items;
        Customer customer;
        double _total;
};

#endif
