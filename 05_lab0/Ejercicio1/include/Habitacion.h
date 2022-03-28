#ifndef HABITACION
#define HABITACION


class Habitacion{
    private:
        int numero, capacidad;
        float precio;
    public:
        Habitacion();
        Habitacion(int, float, int);
        int getNumero();
        int getCapacidad();
        float getPrecio();
};

#endif