#ifndef CLASEB
#define CLASEB

#include "claseA.h"
#include "claseC.h"

class A;

class B{
    private:
        A *objA;
        C *objC;
        int b;
    public:
        B();
        B(int);
        int getB();
        void asignarPunteros(A*, C*);
        A* getObjA();
        C* getObjC();
        void printInt();
};

#endif