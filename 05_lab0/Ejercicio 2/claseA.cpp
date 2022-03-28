#include "claseA.h"
#include "claseB.h"
#include "claseC.h" 
#include "iostream"

using namespace std;

A::A(){

}

A::A(int a1){
    this->a = a1;
}

int A::getA(){
    return this->a;
}

void A::asignarPunteros(B* b, C* c){
    this->objB = b;
    this->objC = c;
}


B* A::getObjB(){
    return this->objB;
}

C* A::getObjC(){
    return this->objC;
}

void A::printInt(){
    cout << getA() << "\n";
}

