#include "../include/DTHuesped.h"
#include <string>

// #include <iostream>
// using namespace std;

DTHuesped::DTHuesped(){

}

DTHuesped::DTHuesped(string name,string email,bool esF){
  this->nombre = name;
  this->email = email;
  this->esFinger = esF;
}

bool DTHuesped::getEsFinger(){
  return this->esFinger;
}

string DTHuesped::getNombre(){
  return this->nombre;  
}

string DTHuesped::getEmail(){
  return this->email;  
}

// int main(){
//     cout << "Ingrese nombre, email y si es Finger (1 = si, 0 = no): " << endl;

//     string name;
//     string email;
//     bool esFinger;

//     cin >> name;
//     cin >> email;
//     cin >> esFinger;

//     DTHuesped h1 = DTHuesped(name, email, esFinger);

//     cout << h1.getNombre() << endl;
//     cout << h1.getEsFinger() << endl;

//     return 0;
// }