#define segmento // Deberia ir en .h
#define punto // Deberia ir en .h
#include <cmath> // Deberia ir en .cpp


// Primera parte
class punto { // Deberia ir en .h
	private:
		float x, y;
	public:
		float setX();
		float getX();
		float setY();
		float getY();
};

void punto::setX(float x){ // Deberia ir en .cpp
	this->x = x;
}

float  punto::getX(){ // Deberia ir en .cpp
	return this->x;
}

void punto::setY(float y){ // Deberia ir en .cpp
	this->y = y;
}

float  punto::getY(){ // Deberia ir en .cpp
	return this->y;
}

// Segunda parte

class segmento { // Deberia ir en .h
	private:
		punto p1, p2;
	public:
		segmento();
		segmento(punto p1, punto p2);
		float distanciaseg();
};

segmento::segmento(){} // Deberia ir en .cpp

segmento::segmento(punto p1, punto p2){ // Deberia ir en .cpp
	this->p1 = p1;
	this->p2 = p2;
}

float segmento::distanciaseg(){ // Deberia ir en .cpp
	return sqrt(pow(p2.getX() - p1.getX()) + pow(p2.getY() - p1.getY()))
}

