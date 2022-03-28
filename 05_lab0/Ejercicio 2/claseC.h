#ifndef CLASEC
#define CLASEC

#include "claseA.h"
#include "claseB.h"

class B;
class A;

class C {
    private: 
        B *objB;
        A *objA;
        int c;
    public:
        C();
        C(int);
        int getC();
        void asignarPunteros(B*, A*);
        A* getObjA();
        B* getObjB();
        void printInt();
};

#endif