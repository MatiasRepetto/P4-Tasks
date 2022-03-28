#ifndef DTHABITACION
#define DTHABITACION


class DTHabitacion{
    private:
        int numero, capacidad;
        float precio;
    public:
        DTHabitacion();
        DTHabitacion(int, float, int);
        int getNumero();
        int getCapacidad();
        float getPrecio();
};

#endif