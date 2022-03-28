#include "../include/Habitacion.h"
#include "../include/Huesped.h"
#include "../include/DTFecha.h"
#include "../include/EstadoReserva.h"
#include "../include/Reserva.h"
#include <iostream>

Reserva::Reserva(){

}

Reserva::Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, Huesped *huesped, Habitacion *habitacion){
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = Abierta;
    this->huesped = huesped;
    this->habitacion = habitacion;
}

int Reserva::getCodigo(){
    return codigo;
}

DTFecha Reserva::getCheckIn(){
    return checkIn;
}

DTFecha Reserva::getCheckOut(){
    return checkOut;
}

EstadoReserva Reserva::getEstadoReserva(){
    return estado;
}

Huesped* Reserva::getHuesped(){
    return huesped;
}

Habitacion* Reserva::getHabitacion(){
    return habitacion;
}

void Reserva::setEstadoReserva(EstadoReserva nuevoEstado){
    this->estado = nuevoEstado;
}

//RESERVA GRUPAL -------------------------------------

ReservaGrupal::ReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut,  Huesped* huesped, Habitacion *habitacion, Huesped** huespedes, int cantHuespedes) : Reserva(codigo, checkIn, checkOut, huesped, habitacion){
   this->huespedes = huespedes;
   this->cantHuespedes = cantHuespedes;
}

int ReservaGrupal::getCantHuespedes(){
    return this->cantHuespedes;
}

Huesped** ReservaGrupal::getHuespedes(){
    return this->huespedes;
}

float ReservaGrupal::calcularCosto(){
    Habitacion *habitacion = getHabitacion();
    float precio = habitacion->getPrecio();

    DTFecha checkOut = this->getCheckOut();
    DTFecha checkIn = this->getCheckIn();

    int dias = checkOut.diferencia(checkIn);

    Huesped** huespedes = this->getHuespedes();
    int cantHuespedes = this->getCantHuespedes();

    int cantFingers = 0;

    for(int i=0; i<cantHuespedes && cantFingers < 2; i++){
        if(huespedes[i]->getEsFinger()){
            cantFingers++;
        }
    }

    float precioTotal = precio * dias;

    if(cantFingers >= 2){
        return precioTotal*(0.7);
    } else {
        return precioTotal;
    }
}

//RESERVA INDIVIDUAL --------------------------------

ReservaIndividual::ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, Huesped *huesped, Habitacion *habitacion, bool pagado) : Reserva(codigo, checkIn, checkOut, huesped, habitacion){
    this->pagado = pagado;
}

bool ReservaIndividual::getPagado(){
    return this->pagado;
}

void ReservaIndividual::setPagado(bool pagado){
    this->pagado = pagado;
}

float ReservaIndividual::calcularCosto(){
    Habitacion *habitacion = getHabitacion();
    float precio = habitacion->getPrecio();

    DTFecha checkOut = this->getCheckOut();
    DTFecha checkIn = this->getCheckIn();

    int dias = checkOut.diferencia(checkIn);

    return precio * dias;
}


//MAIN

// int main(){
//     DTFecha checkIn = DTFecha(1, 1, 2022);
//     DTFecha checkOut = DTFecha(7, 1, 2022);

//     Huesped* h1 = new Huesped("Gaetano", "gaetano@email.com", true);
//     Huesped* h2 = new Huesped("Joaquin", "joaquin@email.com", true);
//     Huesped* h3 = new Huesped("Matias", "matias@email.com", false);

//     Huesped** arrHuespedes = new Huesped*[3];

//     arrHuespedes[0] = h1;
//     arrHuespedes[1] = h2;
//     arrHuespedes[2] = h3;

//     Habitacion* hab1 = new Habitacion(1, 500, 5);

//     ReservaGrupal* r1 = new ReservaGrupal(1000, checkIn, checkOut, h1, hab1, arrHuespedes, 3);


//     cout << r1->calcularCosto() << endl;    // 3000
//     cout << r1->getHuesped()->getNombre() << endl;  //Gaetano

//     return 0;
// }