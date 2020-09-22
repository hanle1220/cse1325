#include<iostream>
#include<iomanip>
#include"modulo.h" 
#include<string>

Modulo::Modulo(int modulo, int value, int offset): _modulo{modulo}, _value{value}, _offset{offset}{ }

void Modulo::set_nmsd(Modulo* nmsd) {_nmsd = nmsd;}

int Modulo::value() {return _value;}

Modulo Modulo::operator+(int rhs) {
    Modulo m(*this); 
    return m;
}

Modulo& Modulo::operator+=(int rhs){
    for ( ; rhs>0; --rhs) ++(*this);
    return *this;
}

Modulo& Modulo::operator++(){
    ++_value;
    if (_value>=_modulo){
        _value-=_modulo;  
        _nmsd->_value++; 
        if(_nmsd->_value >_nmsd->_modulo){
            _nmsd->_value-=_nmsd->_modulo;
            _nmsd->_nmsd->_value++;
                if( _nmsd->_nmsd->_value >_nmsd->_nmsd->_modulo){
                       _nmsd->_nmsd->_value-=_nmsd->_nmsd->_modulo;
                }
        }
     }           
    
    return *this;    
}
Modulo Modulo::operator++(int){
    Modulo modulo(*this);
    ++*this;
    return modulo;
}

int Modulo::compare(const int rhs) {
    if(_value<rhs) return -1;
    if(_value>rhs) return  1;
    return 0;   
}

std::ostream& operator<<(std::ostream& ost, Modulo& m){    
    ost << m._value+m._offset;
    return ost;
}

std::istream& operator>>(std::istream& ist, Modulo& m){
    int input;
    ist >> input;
    m._value = (input-m._offset)%m._modulo;
    return ist;
}

