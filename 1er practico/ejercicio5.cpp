#define fecha

class fecha {
	private:
		int dia, mes, year;
	public:
		fecha(int dia, int mes, int year);
		fecha avanzar(int dias);
		fecha retroceder(int dias);
		int diferencia(fecha f1, fecha f2);
		bool comparacion(fecha f1, fecha f2);
};

fecha::fecha(){}

fecha::ingresar(int dia, int mes, int year){
	this->dia = dia;
	this->mes = mes;
	this->year = year;
}

fecha fecha::ingresar(int dias){
	int diaA = (this->dia + dias) % 30;
	int mesA = (this->mes + (this->dia + dias) / 30)) % 12;
	int yearA = (this->year) + (this->mes + (this->dia + dias) / 30) / 12;
	return fecha(diaA, mesA, yearA); 
}

fecha fecha::ingresar(int dias){
	int diaE = (this->dia - dias) % 30;
	int mesE = (this->mes - (this->dia - dias) / 30)) % 12;
	int yearE = (this->year) - (this->mes - (this->dia - dias) / 30) / 12;
	return fecha(diaE, mesE, yearE); 
}

int fecha::diferencia(fecha f1, fecha f2){
	int difD = sqrt(pow(f1.dia - f2.dia));
	int difM = sqrt(pow(f1.mes - f2.mes))*30;
	int difY = sqrt(pow(f1.year - f2.year))*12*30;
	return (difD + difM + difY);
}

bool fecha::comparacion(fecha f1, fecha f2){
	return ((f1.dia == f2.dia) && (f1.mes == f2.mes) && (f1.year == f2.year))
}

// sobrecarga del operador 

fecha& operator <<(fecha f1){
	cout << f1.year << "/" << f1.mes << "/" << f1.dia
}

