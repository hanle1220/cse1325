#ifndef __DIE_H
#define __DIE_H

class Die {
	int _faces;
	int _value;
   public:
    Die(int faces);
    int faces();
    int value();
    void roll();
};

#endif
