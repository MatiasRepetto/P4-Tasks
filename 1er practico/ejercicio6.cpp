// Las presentes implementaciones no estan 100% bien TENER CUIDADO esta hecho solo para bajar a tierra conceptos.

class string{
	private:
		char *c;
		int largo;
	public:
		deleteString();
		iniciarstring();
		string operator=(const string &s);
		string operator+(const string &s);
		bool operator==(const string &s);
		char operator[](int pos);
};

string::deleteString(){
	delete [] c;
}

string::iniciarstring(){
	c = char[1];
	c[0] = ´\0´;
	largo = 0;
}

string &string::operator=(const string &s){
	largo = s.largo;
	c = new char[largo];
	for(i=0, i=largo, i++){
		c[i] = s.c[i];
	}
	return *this;
}

string string::operator+(const string &s){
	string stringresult;
	stringresult.largo = largo + s.largo;
	stringresult.c = new char[stringresult.largo]
	for(i=0; i=largo; i++){
		stringresult.c[i] = this->c[i];
	}
	for(i=0; i=s.largo; i++){
		int aux = largo + i;
		stringresult.c[aux] = s.c[i];
	}
	return stringresult;
}

bool string::operator==(constant string &s){
	bool sondistintos = true;
	if(largo == s.largo){
		int i = 0;
		sondistintos = false;
		while(i <= largo && not(sondistintos)){
			if(c[i] != s.c[i]){
				sondistintos = true;
			}
			i++;
		}
	}
	return sondistintos;
}

char &string::operator[](int pos){
	return c[pos];
}


