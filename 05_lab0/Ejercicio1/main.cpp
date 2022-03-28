#include <iostream>
#include <string>
#include <stdio.h>

#include "include/sistema.h"
#include "include/constantes.h"
#include "include/DTFecha.h"
#include "include/DTHabitacion.h"
#include "include/DTHuesped.h"
#include "include/DTReserva.h"
#include "include/EstadoReserva.h"
#include "include/Habitacion.h"
#include "include/Huesped.h"
#include "include/Reserva.h"

using namespace std;

ostream &operator<<(ostream &out, DTReservaIndividual &reservaIndividual){
  DTFecha checkIn = reservaIndividual.getCheckIn();
  DTFecha checkOut = reservaIndividual.getCheckOut();

  out << "TipoReserva: Individual" << endl;
  out << "FechaCheckIn: " << checkIn.getDia() << "/" << checkIn.getMes() << "/" << checkIn.getAnio() << endl;
  out << "FechaCheckOut: " << checkOut.getDia() << "/" << checkOut.getMes() << "/" << checkOut.getAnio() << endl;
  out << "Habitacion: " << reservaIndividual.getHabitacion() << endl;
  out << "Costo: " << reservaIndividual.getCosto() << endl;
  out << "Pagado: ";

  if(reservaIndividual.getPagado()){
      out << "Si";
  } else {
      out << "No";
  }

  out << endl;

  // out << "Prueba" << endl;


  return out;
}

ostream &operator<<(ostream &out, DTReservaGrupal &reservaGrupal){
  DTFecha checkIn = reservaGrupal.getCheckIn();
  DTFecha checkOut = reservaGrupal.getCheckOut();

  out << "TipoReserva: Grupal" << endl;
  out << "FechaCheckIn: " << checkIn.getDia() << "/" << checkIn.getMes() << "/" << checkIn.getAnio() << endl;
  out << "FechaCheckOut: " << checkOut.getDia() << "/" << checkOut.getMes() << "/" << checkOut.getAnio() << endl;
  out << "Habitacion: " << reservaGrupal.getHabitacion() << endl;
  out << "Costo: " << reservaGrupal.getCosto() << endl;
  
  for(int i = 0; i < reservaGrupal.getCantHuespedes(); i++) {
      DTHuesped huesp = reservaGrupal.getHuespedes()[i];
      out << huesp.getNombre() << "-";
      out << huesp.getEmail();
      
      if(huesp.getEsFinger()){
          out << "-" << "esFinger,";
      } else {
          out << ",";
      }

      out << endl;
  }

  // out << "Prueba" << endl;


  return out;
}

int main(){
    sistema* sis = new sistema();
    int mvar1;
    do{
      cout << "1. Agregar Huesped. \n";
      cout << "2. Agregar Habitacion. \n";
      cout << "3. Obtener Huespedes. \n";
      cout << "4. Obtener Habitaciones. \n";
      cout << "5. Registrar Reserva. \n";
      cout << "6. Obtener Reservas. \n";
      cout << "7. Salir. \n";
      cin >> mvar1;
      switch(mvar1){
        case 1:
        { 
          string nombre;
          string email;
          bool esFinger;
          cout << "Ingrese el nombre de el huesped. \n";
          cin >> nombre;
          cout << "Ingrese el email de el huesped. \n";
          cin >> email;
          if(sis->existeHuesped(email)){ 
            throw std::invalid_argument("Imposible el email ya esta ingresado. ");
            return main();
          }
          cout << "El huesped es Finger (1->SI, 0->No). \n";
          cin >> esFinger;
          sis->agregarHuesped(nombre, email, esFinger);
          break;
        }
        case 2:
        {
          int numero, capacidad;
          float precio;
          cout << "Ingrese el numero de la habitacion. \n";
          cin >> numero;
          if(sis->existeHabitacion(numero)){
            throw std::invalid_argument("Imposible el numero de habitacion ya esta ingresado. ");
            return main();
          }
          cout << "Ingrese el precio de la habitacion. \n";
          cin >> precio;
          cout << "Ingrese la capacidad de huespedes de la habitacion. \n";
          cin >> capacidad;
          sis->agregarHabitacion(numero, precio, capacidad);
          break;
        }
        case 3:
        {
          int cantHuespedes;
          DTHuesped** auxDTHuesp = sis->obtenerHuespedes(cantHuespedes);
          for(int i = 0; i < cantHuespedes; i++){
            cout << "El nombre del huesped es: " << auxDTHuesp[i]->getNombre() << endl;
            cout << "El email del huesped es: " << auxDTHuesp[i]->getEmail() << endl;
            cout << "El del huesped es Finger?: " << auxDTHuesp[i]->getEsFinger() << endl;
            delete auxDTHuesp[i];
          }
          delete auxDTHuesp;
          break;
        }
        case 4:
        {
          int cantHabitaciones;
          DTHabitacion** auxDTHabitacion = sis->obtenerHabitaciones(cantHabitaciones);
          for(int i = 0; i < cantHabitaciones; i++){
            cout << "El numero de la habitacion es: " << auxDTHabitacion[i]->getNumero() << endl;
            cout << "El precio de la habitacion es: " << auxDTHabitacion[i]->getPrecio() << endl;
            cout << "La capacidad de la habitacion es: " << auxDTHabitacion[i]->getCapacidad() << endl;
            delete auxDTHabitacion[i];
          }
          delete auxDTHabitacion;
          break;
        }
        case 5:
        {
          string email;
          int menucas5;
          int codigoReserva, diaCheckin, mesCheckin, anioCheckin, diaCheckout, mesCheckout, anioCheckout ,codigoHabitacion;
          cout << "1- Reserva Individual. " << endl;
          cout << "2- Reserva Grupal. " << endl;
          cin >> menucas5;
          switch(menucas5){
            case 1:
            {
              bool estapago;
              cout << "Ingrese codigo de la reserva: " << endl;
              cin >> codigoReserva;
              cout << "Ingrese dia de checkin: " << endl;
              cin >> diaCheckin;
              cout << "Ingrese mes de checkin: " << endl;
              cin >> mesCheckin;
              cout << "Ingrese anio de checkin: " << endl;
              cin >> anioCheckin;
              cout << "Ingrese dia de checkout: " << endl;
              cin >> diaCheckout;
              cout << "Ingrese mes de checkout: " << endl;
              cin >> mesCheckout;
              cout << "Ingrese anio de checkout: " << endl;
              cin >> anioCheckout;
              cout << "Ingrese email del huesped a cargo de la reserva: " << endl;
              cin >> email;
              if(!sis->existeHuesped(email)){ 
                throw std::invalid_argument("Imposible el email no coincide con ningun huesped ingresado. ");
                return main();
              }
              cout << "Ingrese numero de la habitacion: " << endl;
              cin >> codigoHabitacion;
              if(!sis->existeHabitacion(codigoHabitacion)){ 
                throw std::invalid_argument("Imposible el numero de habitacion no coincide con ninguna habitacion ingresada. ");
                return main();
              }
              Habitacion* habitacionSol = sis->retornaHabitacion(codigoHabitacion);
              cout << "Ingrese si el huesped ya pago o no (1- Si, 0- No): " << endl;
              cin >> estapago;
              EstadoReserva estadoReserv = Abierta;
              DTFecha auxcheckIn = DTFecha(diaCheckin, mesCheckin, anioCheckin);
              DTFecha auxcheckOut = DTFecha(diaCheckout, mesCheckout, anioCheckout);
              DTReserva* auxDTRind = new DTReservaIndividual(codigoReserva, auxcheckIn, auxcheckOut, estadoReserv, habitacionSol->getPrecio(), codigoHabitacion, estapago);
              sis->registrarReserva(email, auxDTRind);
              
              break;
            }
            case 2:
            {
              int canthuespedesaux;
              cout << "Ingrese codigo de la reserva: " << endl;
              cin >> codigoReserva;
              cout << "Ingrese dia de checkin: " << endl;
              cin >> diaCheckin;
              cout << "Ingrese mes de checkin: " << endl;
              cin >> mesCheckin;
              cout << "Ingrese anio de checkin: " << endl;
              cin >> anioCheckin;
              cout << "Ingrese dia de checkout: " << endl;
              cin >> diaCheckout;
              cout << "Ingrese mes de checkout: " << endl;
              cin >> mesCheckout;
              cout << "Ingrese anio de checkout: " << endl;
              cin >> anioCheckout;
              cout << "Ingrese email del huesped a cargo de la reserva: " << endl;
              cin >> email;
              if(!sis->existeHuesped(email)){ 
                throw std::invalid_argument("Imposible el email no coincide con ningun huesped ingresado. ");
                return main();
              }
              cout << "Ingrese numero de la habitacion: " << endl;
              cin >> codigoHabitacion;
              if(!sis->existeHabitacion(codigoHabitacion)){ 
                throw std::invalid_argument("Imposible el numero de habitacion no coincide con ninguna habitacion ingresada. ");
                return main();
              }
              Habitacion* habitacionSol = sis->retornaHabitacion(codigoHabitacion);
              cout << "Ingrese la cantidad de huespedes que reservan: " << endl;
              cin >> canthuespedesaux;
              DTHuesped* auxhuespedes = new DTHuesped[canthuespedesaux];
              string nombHuespArr, emailHuespArr;
              bool esFingerArr;
              DTHuesped dthuespedArr;
              for(int i = 0; i < canthuespedesaux; i++){
                cout << "Ingrese Nombre del huesped: " << i << endl;
                cin >> nombHuespArr;
                cout << "Ingrese email del huesped: " << i << endl;
                cin >> emailHuespArr;
                cout << "Ingrese es finger? (1- Si, 0- No): " << endl;
                cin >> esFingerArr;
                dthuespedArr = DTHuesped(nombHuespArr, emailHuespArr, esFingerArr);
                auxhuespedes[i] = dthuespedArr;
              }
              EstadoReserva estadoReserv = Abierta;
              DTFecha auxcheckIn = DTFecha(diaCheckin, mesCheckin, anioCheckin);
              DTFecha auxcheckOut = DTFecha(diaCheckout, mesCheckout, anioCheckout);
              DTReservaGrupal* auxDTRgrup = new DTReservaGrupal(codigoReserva, auxcheckIn, auxcheckOut, estadoReserv, habitacionSol->getPrecio(), codigoHabitacion, auxhuespedes, canthuespedesaux);
              sis->registrarReserva(email, auxDTRgrup);
              
              break;
            }
          }
          break;
        }
        case 6:
        {
          int dia, mes, anio;
          int cantReservas;
          cout << "Ingrese el dia de la reserva a obtener. \n";
          cin >> dia;
          cout << "Ingrese el mes de la reserva a obtener. \n";
          cin >> mes;
          cout << "Ingrese el aÃ±o de la reserva a obtener. \n";
          cin >> anio;
          DTFecha fecha = DTFecha(dia, mes, anio);
          DTReserva** auxDTReserva = sis->obtenerReservas(fecha, cantReservas);
          for(int i = 0; i < cantReservas; i++){
            DTReservaIndividual* resInd = dynamic_cast<DTReservaIndividual*>(auxDTReserva[i]);

            if(resInd != 0){  //ReservaIndividual
              DTReservaIndividual resActual = *resInd;
              cout << resActual << endl; // Se supone que debe usar la sobrecarga del << 
            } else {  //ReservaGrupal
              DTReservaGrupal* resGrupal = dynamic_cast<DTReservaGrupal*>(auxDTReserva[i]);
              DTReservaGrupal resActual = *resGrupal;
              cout << resActual << endl; // Se supone que debe usar la sobrecarga del << 
            }

          }
          delete auxDTReserva;
          break;
        }
        case 7:
        {
          int varsal;
          cout << "Seguro quiere salir ?. \n";
          cout << "1 -- Si, estoy seguro. \n";
          cout << "0 -- N0, volver al programa. \n";
          cin >> varsal;
          switch(varsal){
            case 0:
            {
              return main();
            }
            default:
            {
              return 0;
            }
          }
        }
        default:
        {
          return main();
        }
      }
    }while(mvar1 != 7);   
  return 0;
}
