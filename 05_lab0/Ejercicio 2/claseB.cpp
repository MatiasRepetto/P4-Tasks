#include "claseA.h"
#include "claseB.h"
#include "claseC.h" 
#include "iostream"

using namespace std;

B::B(){

}

B::B(int b1){
    this->b = b1;
}

void B::asignarPunteros(A* a, C* c){
    this->objA = a;
    this->objC = c;
}

int B::getB(){
    return this->b;
}

A* B::getObjA(){
    return this->objA;
}

C* B::getObjC(){
    return this->objC;
}

void B::printInt(){
   cout << getB() << "\n";
}

