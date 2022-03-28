#ifndef DTRESERVA
#define DTRESERVA

#include "DTFecha.h"
#include "DTHuesped.h"
#include "EstadoReserva.h"

#include <string>

#include <iostream>
using namespace std;



class DTReserva{
    private:
        int codigo, habitacion;
        DTFecha checkIn, checkOut;
        EstadoReserva estado;
        float costo;
    public:
        DTReserva();
        DTReserva(int, DTFecha, DTFecha, EstadoReserva, float, int);
        int getCodigo();
        int getHabitacion();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        EstadoReserva getEstadoReserva();
        float getCosto();

        virtual void operacionAbstracta() const{}
};

class DTReservaGrupal : public DTReserva{
    private:
        DTHuesped* huespedes;
        int cantHuespedes;

    public:
        DTReservaGrupal(int, DTFecha, DTFecha, EstadoReserva, float, int, DTHuesped*, int);
        DTHuesped* getHuespedes();
        int getCantHuespedes();
        // friend ostream& operator<<(ostream& out, const DTReservaGrupal &reservaGrupal); 
};

class DTReservaIndividual : public DTReserva{
    private:
        bool pagado;
    public:
        DTReservaIndividual(int, DTFecha, DTFecha, EstadoReserva, float, int, bool);
        bool getPagado();
        // friend ostream& operator<<(ostream& out, DTReservaIndividual &reservaIndividual); 

};
// ostream &operator<<(ostream &out, const DTReservaIndividual &reservaIndividual);
// ostream &operator<<(ostream &out, const DTReservaGrupal &reservaGrupal);



// ostream &operator<<(ostream &out, DTReservaIndividual &reservaIndividual){
//     // DTFecha checkIn = reservaIndividual.getCheckIn();
//     // DTFecha checkOut = reservaIndividual.getCheckOut();

//     // out << "TipoReserva: Individual" << endl;
//     // out << "FechaCheckIn: " << checkIn.getDia() << "/" << checkIn.getMes() << "/" << checkIn.getAnio() << endl;
//     // out << "FechaCheckOut: " << checkOut.getDia() << "/" << checkOut.getMes() << "/" << checkOut.getAnio() << endl;
//     // out << "Habitacion: " << reservaIndividual.getHabitacion() << endl;
//     // out << "Costo: " << reservaIndividual.getCosto() << endl;
//     // out << "Pagado: ";

//     // if(reservaIndividual.getPagado()){
//     //     out << "Si";
//     // } else {
//     //     out << "No";
//     // }

//     // out << endl;

//     out << "Prueba" << endl;

//     return out;
// }

// ostream &operator<<(ostream &out, DTReservaGrupal &reservaGrupal){
//     // DTFecha checkIn = reservaGrupal.getCheckIn();
//     // DTFecha checkOut = reservaGrupal.getCheckOut();

//     // out << "TipoReserva: Grupal" << endl;
//     // out << "FechaCheckIn: " << checkIn.getDia() << "/" << checkIn.getMes() << "/" << checkIn.getAnio() << endl;
//     // out << "FechaCheckOut: " << checkOut.getDia() << "/" << checkOut.getMes() << "/" << checkOut.getAnio() << endl;
//     // out << "Habitacion: " << reservaGrupal.getHabitacion() << endl;
//     // out << "Costo: " << reservaGrupal.getCosto() << endl;
    
//     // for(int i = 0; i < reservaGrupal.getCantHuespedes(); i++) {
//     //     DTHuesped huesp = reservaGrupal.getHuespedes()[i];
//     //     out << huesp.getNombre() << "-";
//     //     out << huesp.getEmail();
        
//     //     if(huesp.getEsFinger()){
//     //         out << "-" << "esFinger,";
//     //     } else {
//     //         out << ",";
//     //     }

//     //     out << endl;
//     // }

//     out << "Prueba DTReservaIndividual Prueba" << endl;

//     return out;
// }

#endif