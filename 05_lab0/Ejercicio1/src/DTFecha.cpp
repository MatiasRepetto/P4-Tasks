#include "../include/DTFecha.h"
#include <string>
#include <stdio.h>

#include <iostream>
using namespace std;

DTFecha::DTFecha(){
    
}

DTFecha::DTFecha(int dia, int mes, int anio) { 
    if(dia < 1 || dia > 31){
        throw std::invalid_argument("El dia tiene que tener un formado de 1 <= dia <= 31 ");
    }

    if(mes < 1 || mes > 12){
        throw std::invalid_argument("El mes tiene que tener un formado de 1 <= mes <= 12 ");
    }

    if(anio < 1900){
        throw std::invalid_argument("El año tiene que ser mayor o igual a 1900");
    }

    this->dia = dia; 
    this->mes = mes; 
    this->anio = anio;
} 

int DTFecha::getDia(){
    return this->dia;
}

int DTFecha::getMes(){
    return this->mes;
}

int DTFecha::getAnio(){
    return this->anio;
}

DTFecha DTFecha::avanzar(int inc) { 
    int nDia = (this->dia + inc) % 31; 
    int nMes = (this->mes + (this->dia + inc) / 31) % 12; 
    int nAnio = (this->anio) + (this->mes + (this->dia + inc) / 31) / 12; 
    return DTFecha(nDia, nMes, nAnio);
} 

DTFecha DTFecha::retroceder(int dec){
    int nDia = (this->dia - dec) % 31; 
    int nMes = (this->mes - (this->dia + dec) / 31) % 12; 
    int nAnio = (this->anio) - (this->mes - (this->dia - dec) / 31) / 12; 
    return DTFecha(nDia, nMes, nAnio);
}

int DTFecha::diferencia(DTFecha f) { 
    long int f1 = f.dia + f.mes*31 + f.anio*12*31; 
    long int f2 = this->dia + this->mes*31 + this->anio*12*31; 
    return f2 - f1; 
} 
bool DTFecha::igual(DTFecha f) { 
    return this->dia==f.dia && this->mes==f.mes && this->anio==f.anio; 
}

