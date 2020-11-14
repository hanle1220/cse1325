#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <iostream>

class Customer{
    public:
        Customer(std::string name, std::string phone, std::string email);
        friend std::ostream& operator<<(std::ostream& ost, const Customer& customers);
        Customer(std::istream& ist);
        virtual void save(std::ostream& ost);
        std::string to_string() const;
        std::string getName() const;
    private:
        std::string name;
        std::string phone;
        std::string email;
};

#endif 
