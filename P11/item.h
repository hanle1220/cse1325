#ifndef __ITEM_H
#define __ITEM_H

#include <iostream>
#include "product.h"

class Item{
    public:
        double subtotal();
        Item( Product& product, int quantity);
        Item(std::istream& ist);
        void save(std::ostream& ost);
        friend std::ostream& operator<<(std::ostream& ost, const Item& item);
    private:
        Product* _product;
        int _quantity;
};
 
#endif
