#ifndef SISTEMA
#define SISTEMA
#include "Reserva.h"
#include "DTReserva.h"
#include "DTHuesped.h"
#include "DTHabitacion.h"


class sistema{
    private:
        Reserva **arrReserva;
        int reservasActivas;
        Habitacion **arrHabitacion;
        int habitacionesActivas;
        Huesped **arrHuesped;
        int huespedesActivos;
    public:
        sistema();
        void agregarHuesped(string, string, bool);
        void agregarHabitacion(int, float, int);
        DTHuesped** obtenerHuespedes(int&);
        DTHabitacion** obtenerHabitaciones(int&);
        DTReserva** obtenerReservas(DTFecha, int&);
        void registrarReserva(string, DTReserva*);

        bool existeHuesped(string);
        bool existeHabitacion(int);

        Huesped* retornaHuesped(string);
        Habitacion* retornaHabitacion(int);

        DTHuesped* getDTHuespedesFromHuespedes(Huesped**, int);
        Huesped** getHuespedesFromDTHuespedes(DTHuesped*, int);
};


#endif