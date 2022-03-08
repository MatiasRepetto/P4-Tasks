// Ejemplo de minisitema aplicando lo dado hasta el momento ne el curso

#include <iostream>
#include <string>

// Clase de empresa

class empresa{
    private:
        string nombre;
    public:
        empresa(string empresa);
        string getNombreEmpresa();
};

// Metodos de empresa

empresa::empresa(string empresa){
    this->empresa = empresa;
}

string empresa::getNombreEmpresa(){
    return this->nombre;
}

// Clase de empleado

class empleado : public empresa{
    private:
        string nombre;
    public:
        empleado(string nombre);
        string getNombre();
        virtual float getTotal() = 0;
};

// Metodos de empleados

empleado::empleado(string nombre){
    this->nombre = nombre;
}

string empleado::getNombre(){
    return this->nombre;
}

// Clase de empleado comun

class empleadoComun : public empleado{
    private:
        float sueldo;
    public:
        empleadoComun(string nombre, float sueldo);
        float getSueldo();
        virtual float getTotal();
};

// Metodos de empleado comun

empleadoComun::empleadoComun(string nombre, float sueldo){
    empleado(nombre);
    this->sueldo = sueldo;
}

float empleadoComun::getSueldo(){
    return this->sueldo;
}

float empleadoComun::getTotal(){
    return getSueldo();
}

// Clase de empleado jornalero

class empleadoJornalero : public empleado{
    private:
        int horas;
        float precio;
    public:
        empleadoJornalero(string nombre, int horas, floar precio);
        int getHoras();
        float getPrecio();
        virtual float getTotal();
};

// Metodos de empleado jornalero

int empleadoJornalero::getHoras(){
    return this->horas;
}

int empleadoJornalero::getHoras(){
    return this->precio;
}

empleadoJornalero::empleadoJornalero(string nombre, int horas, floar precio){
    empleado(nombre);
    this->horas = horas;
    this->precio = precio;
}

float empleadoJornalero::getTotal(){
    float aux = getHoras() * getPrecio();
    return aux;
}

class colecccionempleado{
    private:
        empleado *emple[MAX_EMPLEADOS];
        int tope;
    public:
        inciarcoleccion();
        empleado getEmpleado(int pos);
        void ingresarEmpleado(empleado emp);
        int getCantEmpleado();
        void liberarEmp();
};

colecccionempleado::getEmpleado(){
    this->tope = 0;
}

empleado colecccionempleado::getEmpleado(int pos){
    return this->emple[pos];
}

void colecccionempleado::ingresarEmpleado(empleado emp){
    this->tope = this->tope + 1;
    this->emple[this->tope] = emp;
}

int colecccionempleado::getCantEmpleado(){
    return this->tope;
}

void colecccionempleado::liberarEmp(){
    for(i = 0; i = this->tope; i++){
        delete this->emple[i];
    }
    this->tope = 0;
}

int main(){
    colecccionempleado empleado.inciarcoleccion();
    int opcion = 0;
    do{
        cout << "Ingrese una opcion (0-salir, 1-Ingresar Empleado, 2-Calcular Liquidacion)" << endl;
        cin >> opcion;
        switch(opcion){
            case 0:
                break;
            case 1:
                cout << "Ingrese que tipo de empleado es (1- Comun, 2- Jornalero)" << endl;
                cin >> opcion2;
                switch(opcion 2){
                    case 1:
                        string empleadonomb;
                        empleado *empleado;
                        cout << "Ingrese nombre de empleado: " << endl;
                        cin >> empleadonomb;
                        cout << "Ingrese el suelo del empleado: " << endl;
                        cin >> empleadosueld;
                        empleado = new empleadoComun(empleadonomb, empleadosueld);
                    case 2:
                        string empleadonomb;
                        empleado *empleado;
                        cout << "Ingrese nombre de empleado: " << endl;
                        cin >> empleadonomb;
                        cout << "Ingrese el valor de cada hora: " << endl;
                        cin >> empleadovalor;
                        cout << "Ingrese la cantidad de horas trabajadas" << endl;
                        cin >> empleadohoras;
                        empleado = new empleadoJornalero(empleadonomb, empleadovalor, empleadohoras);
                    default:
                        break
                }
                empleado.ingresarEmpleado(empleado);
            case 2:
                float aux = 0;
                for(i=0; i=empleado.getCantEmpleado(); i++){
                    aux = aux + empleado.getEmpleado(i)->getTotal();
                }
                cout << "Sueldo total de todos los funcionarios a pagar es : " << aux << endl;
        }       
    }while(opcion != 0){
        return 0;
    }
}