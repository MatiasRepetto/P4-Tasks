#ifndef RESERVA
#define RESERVA

#include "Habitacion.h"
#include "Huesped.h"
#include "DTFecha.h"
#include "EstadoReserva.h"

class Reserva{
    private:
        int codigo;
        DTFecha checkIn;
        DTFecha checkOut;
        EstadoReserva estado;
        Huesped *huesped;
        Habitacion *habitacion;
    public:
        Reserva();
        Reserva(int, DTFecha, DTFecha, Huesped*, Habitacion*);
        int getCodigo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        EstadoReserva getEstadoReserva();
        Huesped* getHuesped();
        Habitacion* getHabitacion();
        void setEstadoReserva(EstadoReserva estado);
        virtual float calcularCosto() = 0;
};


class ReservaGrupal : public Reserva {
    private:
        Huesped **huespedes;
        int cantHuespedes;
    public:
        ReservaGrupal(int, DTFecha, DTFecha, Huesped*, Habitacion*, Huesped**, int);
        virtual float calcularCosto();
        Huesped** getHuespedes();
        // Huesped** listaHuesped(); 
        int getCantHuespedes();
};


class ReservaIndividual: public Reserva {
    private:
        bool pagado;
    public:
        ReservaIndividual(int, DTFecha, DTFecha, Huesped*, Habitacion*, bool);
        void setPagado(bool);
        bool getPagado();
        virtual float calcularCosto();
};

#endif