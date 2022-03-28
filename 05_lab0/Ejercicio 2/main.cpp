#include "claseA.h"
#include "claseB.h"
#include "claseC.h" 
#include "iostream"

using namespace std;


int main(){
    
    //creamos objeto A, con todas las posibilidades
    A *objetoA = new A(10);
    B *objetoB = new B(12);
    C *objetoC = new C(14);

    objetoA->asignarPunteros(objetoB, objetoC);
    objetoB->asignarPunteros(objetoA, objetoC);
    objetoC->asignarPunteros(objetoB, objetoA);

    //imprimirmos objetos creados
    objetoA->printInt(); 
    objetoB->printInt(); 
    objetoC->printInt(); 

    //imprimimos objetos a traves de otro 
    objetoA->getObjC()->printInt(); 
    objetoA->getObjB()->printInt(); 

    objetoB->getObjA()->printInt(); 
    objetoB->getObjC()->printInt(); 

    objetoC->getObjA()->printInt(); 
    objetoC->getObjB()->printInt(); 
    

    return 0;

}
