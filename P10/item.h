#ifndef __ITEM_H
#define __ITEM_H

#include <iostream>
#include "product.h"

class Item{
    public:
        double subtotal();
        Item(const Product& product, int quantity);
        virtual ~Item();
        Item(std::istream ist);
        virtual void save(std::ostream ost);
        friend std::ostream& operator<<(std::ostream& ost, const Item& item);
        std::string to_string() const;
    private:
        Product* _product;
        int quantity;
};
 
#endif
