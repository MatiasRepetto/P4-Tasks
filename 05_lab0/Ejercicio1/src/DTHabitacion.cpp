#include "../include/DTHabitacion.h"
#include <stdio.h>

// #include <iostream>
// using namespace std;

DTHabitacion::DTHabitacion(){

}
DTHabitacion::DTHabitacion(int numero, float precio, int capacidad){
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}

int DTHabitacion::getNumero(){
    return this->numero;
}

float DTHabitacion::getPrecio(){
    return this->precio;
}

int DTHabitacion::getCapacidad(){
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

//     DTHabitacion h1 = DTHabitacion(num, precio, capacidad);

//     cout << h1.getPrecio();

//     return 0;
// }


