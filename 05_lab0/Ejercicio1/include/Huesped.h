#ifndef HUESPED
#define HUESPED
#include <string>
#include <iostream>

using namespace std;

class Huesped{
  private:
    string nombre, email;
    bool esFinger;
  public:
    Huesped();
    Huesped(string,string,bool);
    bool getEsFinger();
    string getNombre();
    string getEmail();
};

#endif
