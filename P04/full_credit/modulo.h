#ifndef __MODULO_H 
#define __MODULO_H
#include <ostream>

class Modulo{
  private:
    int _value;
    int _modulo;
    int _offset;
    Modulo* _nmsd;
    int compare(const int rhs);
  
  public:
    Modulo(int modulo=10, int value=0, int offset=0);
    void set_nmsd(Modulo* nmsd);
    int value();
    Modulo& operator+=(int rhs);
    Modulo operator+(int rhs);
    Modulo& operator++();
    Modulo operator++(int);
    inline bool operator==(int rhs) {return (compare(rhs) == 0);}
    inline bool operator!=(int rhs) {return (compare(rhs) != 0);}
    inline bool operator< (int rhs) {return (compare(rhs) <  0);}
    inline bool operator<=(int rhs) {return (compare(rhs) <= 0);}
    inline bool operator> (int rhs) {return (compare(rhs) >  0);}
    inline bool operator>=(int rhs) {return (compare(rhs) >= 0);}
    friend std::ostream& operator<<(std::ostream& ost, Modulo& m);
    friend std::istream& operator>>(std::istream& ist, Modulo& m);
};

#endif
