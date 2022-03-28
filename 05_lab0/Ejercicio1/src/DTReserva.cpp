#include "../include/DTReserva.h"
#include "../include/DTFecha.h"
#include "../include/DTHuesped.h"
#include "../include/EstadoReserva.h"
#include <string>

#include <iostream>
using namespace std;

DTReserva::DTReserva(){

}

DTReserva::DTReserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, int habitacion){
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->costo = costo;
    this->habitacion = habitacion;
}

int DTReserva::getCodigo(){
    return this->codigo;
}

int DTReserva::getHabitacion(){
    return this->habitacion;
}

DTFecha DTReserva::getCheckIn(){
    return this->checkIn;
}

DTFecha DTReserva::getCheckOut(){
    return this->checkOut;
}

EstadoReserva DTReserva::getEstadoReserva(){
    return this->estado;
}

float DTReserva::getCosto(){
    return this->costo;
}

DTReservaGrupal::DTReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, int Habitacion, DTHuesped* huespedes, int cantHuespedes) : DTReserva(codigo, checkIn, checkOut, estado, costo, Habitacion){
    this->huespedes = huespedes;
    this->cantHuespedes = cantHuespedes;
}

DTHuesped* DTReservaGrupal::getHuespedes(){
    return this->huespedes;
}

int DTReservaGrupal::getCantHuespedes(){
    return this->cantHuespedes;
}

DTReservaIndividual::DTReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, int Habitacion, bool pagado) : DTReserva(codigo, checkIn, checkOut, estado, costo, Habitacion){
    this->pagado = pagado;
}

bool DTReservaIndividual::getPagado(){
    return this->pagado;
}

// ostream &operator<<(ostream &out, DTReservaIndividual &reservaIndividual){
//     DTFecha checkIn = reservaIndividual.getCheckIn();
//     DTFecha checkOut = reservaIndividual.getCheckOut();

//     out << "TipoReserva: Individual" << endl;
//     out << "FechaCheckIn: " << checkIn.getDia() << "/" << checkIn.getMes() << "/" << checkIn.getAnio() << endl;
//     out << "FechaCheckOut: " << checkOut.getDia() << "/" << checkOut.getMes() << "/" << checkOut.getAnio() << endl;
//     out << "Habitacion: " << reservaIndividual.getHabitacion() << endl;
//     out << "Costo: " << reservaIndividual.getCosto() << endl;
//     out << "Pagado: ";

//     if(reservaIndividual.getPagado()){
//         out << "Si";
//     } else {
//         out << "No";
//     }

//     out << endl;

//     // out << "Prueba" << endl;


//     return out;
// }

// ostream &operator<<(ostream &out, DTReservaGrupal &reservaGrupal){
//     DTFecha checkIn = reservaGrupal.getCheckIn();
//     DTFecha checkOut = reservaGrupal.getCheckOut();

//     out << "TipoReserva: Grupal" << endl;
//     out << "FechaCheckIn: " << checkIn.getDia() << "/" << checkIn.getMes() << "/" << checkIn.getAnio() << endl;
//     out << "FechaCheckOut: " << checkOut.getDia() << "/" << checkOut.getMes() << "/" << checkOut.getAnio() << endl;
//     out << "Habitacion: " << reservaGrupal.getHabitacion() << endl;
//     out << "Costo: " << reservaGrupal.getCosto() << endl;
    
//     for(int i = 0; i < reservaGrupal.getCantHuespedes(); i++) {
//         DTHuesped huesp = reservaGrupal.getHuespedes()[i];
//         out << huesp.getNombre() << "-";
//         out << huesp.getEmail();
        
//         if(huesp.getEsFinger()){
//             out << "-" << "esFinger,";
//         } else {
//             out << ",";
//         }

//         out << endl;
//     }

//     // out << "Prueba" << endl;


//     return out;
// }


// int main(){
//     DTFecha checkIn = DTFecha(1, 1, 2022);
//     DTFecha checkOut = DTFecha(7, 1, 2022);

//     DTReservaIndividual r1 = DTReservaIndividual(1000, checkIn, checkOut, Cancelada, 500, 1, true);

//     cout << r1 << endl;

//     return 0;
// }