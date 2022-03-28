#include <iostream>
#include <string>

#include "../include/sistema.h"
#include "../include/Reserva.h"
#include "../include/Huesped.h"
#include "../include/Habitacion.h"
#include "../include/DTReserva.h"
#include "../include/DTHuesped.h"
#include "../include/DTHabitacion.h"
#include "../include/EstadoReserva.h"
#include "../include/constantes.h"

using namespace std;

//FUNCIONES AUXILIARES:
bool sistema::existeHuesped(string email){
    int i = 0;
    bool existe = false;
    while(i < huespedesActivos && !existe){
        if (arrHuesped[i]->getEmail() == email){
            existe = true;
        }
        i++;
    }
    return existe;
}

bool sistema::existeHabitacion(int num){
    int i = 0;
    bool existe = false;
    while(i < habitacionesActivas && !existe){
        if (arrHabitacion[i]->getNumero() == num){
           existe = true;
        }
        i++;
    }
    return existe;
}

// Controlar que el huesped exista 
Huesped* sistema::retornaHuesped(string email){
    int i = 0;

    while(i < huespedesActivos && arrHuesped[i]->getEmail() != email){
        i = i + 1;
    }

    if(i < huespedesActivos){
        return arrHuesped[i];
    } else {
        throw std::invalid_argument("El huesped no esta registrado");
    }
}

// Controlar que este la habitacion ingresada
Habitacion* sistema::retornaHabitacion(int numero){
    int i = 0;

    while (i < habitacionesActivas && arrHabitacion[i]->getNumero() != numero){
        i = i + 1;
    }

    if(i < habitacionesActivas){
        return arrHabitacion[i];
    } else {
        throw std::invalid_argument("La habitacion no existe");
    }
}

DTHuesped* sistema::getDTHuespedesFromHuespedes(Huesped** huespedes, int cantHuespedes){
    DTHuesped* arrDTHuesped = new DTHuesped[cantHuespedes];

    for(int i=0; i<cantHuespedes; i++){
        Huesped* huespedActual = huespedes[i];

        arrDTHuesped[i] = DTHuesped(huespedActual->getNombre(), huespedActual->getEmail(), huespedActual->getEsFinger());
    }

    return arrDTHuesped;
}

Huesped** sistema::getHuespedesFromDTHuespedes(DTHuesped* huespedes, int cantHuespedes){
    Huesped** arrHuesped = new Huesped*[cantHuespedes];

    for(int i=0; i<cantHuespedes; i++){
        DTHuesped DTHuespedActual = huespedes[i];
      

        arrHuesped[i] = new Huesped(DTHuespedActual.getNombre(), DTHuespedActual.getEmail(), DTHuespedActual.getEsFinger());
    }

    return arrHuesped;
}


//COMIENZA SISTEMA:

sistema::sistema(){
    arrReserva = new Reserva*[MAX_RESERVAS];
    reservasActivas = 0;

    arrHabitacion = new Habitacion*[MAX_HABITACIONES];
    habitacionesActivas = 0;

    arrHuesped = new Huesped*[MAX_HUESPEDES];
    huespedesActivos = 0;
}


void sistema::agregarHuesped(string nombre, string email, bool esFinger){
    if(!existeHuesped(email)){
        Huesped* huesp1 = new Huesped(nombre, email, esFinger);
        arrHuesped[huespedesActivos] = huesp1;
        huespedesActivos = huespedesActivos + 1;
    }else{
        throw std::invalid_argument("El huesped ya esta registrado");
    }
}

void sistema::agregarHabitacion(int numero, float precio, int capacidad){
    if(!existeHabitacion(numero)){
        Habitacion* hab1 = new Habitacion(numero, precio, capacidad);
        arrHabitacion[habitacionesActivas] = hab1;
        habitacionesActivas = habitacionesActivas + 1;  
    }else{
        throw std::invalid_argument("La habitacion ya esta registrada");
    }
}

DTHuesped** sistema::obtenerHuespedes(int& cantHuespedes){
    DTHuesped **auxArrayHuesp = new DTHuesped*[huespedesActivos];
    for(int i = 0; i < huespedesActivos; i++){
        auxArrayHuesp[i] = new DTHuesped(arrHuesped[i]->getNombre(), arrHuesped[i]->getEmail(), arrHuesped[i]->getEsFinger());
    }
    cantHuespedes = huespedesActivos;
    return auxArrayHuesp;
}

DTHabitacion** sistema::obtenerHabitaciones(int& cantHabitaciones){
    DTHabitacion **auxArrayHab = new DTHabitacion*[habitacionesActivas];
    for(int i = 0; i < habitacionesActivas; i++){
        auxArrayHab[i] = new DTHabitacion(arrHabitacion[i]->getNumero(), arrHabitacion[i]->getPrecio(), arrHabitacion[i]->getCapacidad());
    }
    cantHabitaciones = habitacionesActivas;
    return auxArrayHab;
}
//arreglo devuelve de la fecha -- NO MENORES 

DTReserva** sistema::obtenerReservas(DTFecha fecha, int& cantReservas){
    DTReserva **reservas = new DTReserva*[reservasActivas];
    int contador = 0;

    for(int i = 0; i < reservasActivas; i++){
        Reserva* reservaActual = arrReserva[i];
        DTFecha f = reservaActual->getCheckIn();
        if(f.igual(fecha)){ 
            contador++;

            ReservaIndividual* resIndividual = dynamic_cast<ReservaIndividual*>(reservaActual);

            if(resIndividual != 0){   //La reserva es Individual
                DTReservaIndividual* r1 = new DTReservaIndividual(resIndividual->getCodigo(), resIndividual->getCheckIn(), resIndividual->getCheckOut(), resIndividual->getEstadoReserva(), resIndividual->calcularCosto(), resIndividual->getHabitacion()->getNumero(), resIndividual->getPagado());
                reservas[i] = r1;
                
            } else {                //La reserva es Grupal
                ReservaGrupal* resGrupal = dynamic_cast<ReservaGrupal*>(reservaActual);

                int cantHuespedes = resGrupal->getCantHuespedes();
                DTHuesped* arrDTHuesped = getDTHuespedesFromHuespedes(resGrupal->getHuespedes(), cantHuespedes);

                DTReservaGrupal* r1 = new DTReservaGrupal(resGrupal->getCodigo(), resGrupal->getCheckIn(), resGrupal->getCheckOut(), resGrupal->getEstadoReserva(), resGrupal->calcularCosto(), resGrupal->getHabitacion()->getNumero(), arrDTHuesped, cantHuespedes);
                reservas[i] = r1;
            }

        }
    }

    cantReservas = contador;
    return reservas;
}


// Cuando usen esta funcion deben controlar que la habitacion y el huesped se encuentran ingresados 
void sistema::registrarReserva(string email, DTReserva* reserva){
    DTReservaIndividual* DTResInd = dynamic_cast<DTReservaIndividual*>(reserva);
    if(DTResInd != 0){   //Reserva Individual
        ReservaIndividual* pReserva = new ReservaIndividual(DTResInd->getCodigo(), DTResInd->getCheckIn(), DTResInd->getCheckOut(), retornaHuesped(email), retornaHabitacion(DTResInd->getHabitacion()), DTResInd->getPagado());

        pReserva->setEstadoReserva(DTResInd->getEstadoReserva());
        arrReserva[reservasActivas] = pReserva;
    } else {  //ReservaGrupal
        DTReservaGrupal* DTResGrupal = dynamic_cast<DTReservaGrupal*>(reserva);

        int cantHuespedes = DTResGrupal->getCantHuespedes();
        Huesped** arrHuespedes = getHuespedesFromDTHuespedes(DTResGrupal->getHuespedes(), cantHuespedes);

        ReservaGrupal* pReserva = new ReservaGrupal(DTResGrupal->getCodigo(), DTResGrupal->getCheckIn(), DTResGrupal->getCheckOut(), retornaHuesped(email), retornaHabitacion(DTResGrupal->getHabitacion()), arrHuespedes, cantHuespedes);

        pReserva->setEstadoReserva(DTResGrupal->getEstadoReserva());
        arrReserva[reservasActivas] = pReserva;
    }

    
    reservasActivas = reservasActivas + 1;
}