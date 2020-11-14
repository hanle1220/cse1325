#ifndef __ORDER_H
#define __ORDER_H
   
#include "item.h"
#include "customer.h"
#include <vector>
class Order{
    public:
        Order(Customer customer);
        friend std::ostream& operator<<(std::ostream& ost, const Order& order);
        Order(std::istream& ist);
        void save(std::ostream& ost);
        void add_item(Item item);
        double total() const;
    private:
        std::vector<Item> _items;
        Customer _customer;
};

#endif
