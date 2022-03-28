#ifndef CLASEA
#define CLASEA

#include "claseB.h"
#include "claseC.h"


class A {
    private: 
        B *objB;
        C *objC;
        int a;
    public:
        A();
        A(int);
        int getA();
        void asignarPunteros(B*, C*);
        B* getObjB();
        C* getObjC();
        void printInt();
};

#endif