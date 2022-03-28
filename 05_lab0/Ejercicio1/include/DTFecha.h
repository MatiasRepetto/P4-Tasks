#ifndef DTFECHA 
#define DTFECHA

class DTFecha{ 
    private: 
        int dia, mes, anio; 
    public: 
        DTFecha();
        DTFecha(int, int, int);
        int getDia();
        int getMes();
        int getAnio();  
        DTFecha avanzar(int); 
        DTFecha retroceder(int); 
        int diferencia(DTFecha); 
        bool igual(DTFecha);
}; 

#endif