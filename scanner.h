//

#ifndef scanner_h
#define scanner_h


#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

class scanner {

	ifstream file; //p
	long q; //c

	char read() {
			return file.get();
	}
	void success() {
			q = file.tellg();
	}
	void fail() { 
		file.seekg(q); 
	}

	void fback() {
		file.seekg(-1, file.cur);
	}

	bool eof() {
		// Guardar la posición actual del puntero del archivo
		streampos currentPos = file.tellg();

		// Ir al final del archivo
		file.seekg(0, std::ios::end);
		streampos fileSize = file.tellg();

		// Volver a la posición original del puntero del archivo
		file.seekg(currentPos, std::ios::beg);

		// Comparar la posición actual con el tamaño del archivo
		return currentPos == fileSize;
	}


	int numeral();
	int delimitador();
	int puntuador();
	int operador();
	bool id();
	void wsp();
	int comentario();

	static int udef;

public:

	string lexema;
	int linea;

	typedef enum {_coment, _true, _false, _print, _id, _parizq, _parder, _corchizq, _corchder, _punto, _coma, _puntocoma, _def
				, _conj, _disy, _neg, _impl, _octal, _hex, _entero, _real, _err, _eof } token;

	scanner(std::string);
	~scanner();

	token scan();
};

#endif /*scanner_h*/
