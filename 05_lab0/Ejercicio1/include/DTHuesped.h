#ifndef DTHUESPED
#define DTHUESPED
#include <string>

using namespace std;

class DTHuesped{
private:
  string nombre, email;
  bool esFinger;
public:
  DTHuesped();
  DTHuesped(string,string,bool);
  bool getEsFinger();
  string getNombre();
  string getEmail();
};

#endif
