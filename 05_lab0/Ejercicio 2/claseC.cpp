#include "claseA.h"
#include "claseB.h"
#include "claseC.h" 
#include "iostream"

using namespace std;

C::C(){

}

C::C(int c){
    this->c = c;
}

void C::asignarPunteros(B* b, A* a){
    this->objB= b;
    this->objA = a;
}

int C::getC(){
    return this->c;
}

A* C::getObjA(){
    return this->objA;
}

B* C::getObjB(){
    return this->objB;
}

void C::printInt(){
   cout << getC() << "\n";
}



