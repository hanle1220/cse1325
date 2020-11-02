 #include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email)
    : name{name}, phone{phone}, email{email} { }

std::string Customer::to_string() const {
    return "Name: "+ name + "     Phone: " + phone + "     Email: " + email;
}

std::ostream& operator<<(std::ostream& ost, const Customer& customer) {
    ost << customer.to_string();
    return ost;
}

Customer::Customer(std::istream& ist){ 
    std::getline(ist, name);
    std::getline(ist, phone);
    std::getline(ist, email);
}

void Customer::save(std::ostream& ost){
    ost << name << std::endl;
    ost << phone << std::endl;
    ost << email << std::endl;
}

