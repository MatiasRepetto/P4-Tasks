#include "../include/Huesped.h"
#include <string>

// #include <iostream>
using namespace std;

Huesped::Huesped(){

}

Huesped::Huesped(string name,string email,bool esF){
  this->nombre = name;
  this->email = email;
  this->esFinger = esF;
}


bool Huesped::getEsFinger(){
  return esFinger;
}

string Huesped::getNombre(){
  return nombre;
}

string Huesped::getEmail(){
  return email;
}

// int main(){
//     cout << "Ingrese nombre, email y si es Finger (1 = si, 0 = no): " << endl;

//     string name;
//     string email;
//     bool esFinger;

//     cin >> name;
//     cin >> email;
//     cin >> esFinger;

//     Huesped* h1 = new Huesped(name, email, esFinger);

//     cout << h1->getNombre() << endl;
//     cout << h1->getEsFinger() << endl;

//     return 0;
// }
