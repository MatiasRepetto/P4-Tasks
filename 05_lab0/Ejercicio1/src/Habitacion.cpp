#include "../include/Habitacion.h"

// #include <iostream>
// using namespace std;

Habitacion::Habitacion(){

}

Habitacion::Habitacion(int numero, float precio, int capacidad){
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}

int Habitacion::getNumero(){
    return this->numero;
}

float Habitacion::getPrecio(){
    return this->precio;
}

int Habitacion::getCapacidad(){
    return this->capacidad;
}

// int main(){
//     cout << "Ingrese numero de Habitacion, precio, y capacidad";

//     int num;
//     float precio;
//     int capacidad;

//     cin >> num;
//     cin >> precio;
//     cin >> capacidad;

//     Habitacion *h1 = new Habitacion(num, precio, capacidad);

//     cout << h1->getPrecio();

//     delete h1;

//     return 0;
// }




