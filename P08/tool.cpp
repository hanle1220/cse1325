#include "tool.h"

Tool::Tool(std::string name, double price, std::string description)
    : Product(name, price, description) { }

Tool::Tool(std::istream& ist) : Product(ist){ }

void Tool::save(std::ostream& ost) { 
    ost << "tool";
    Product::save(ost);
}
