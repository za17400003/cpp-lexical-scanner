
#include "scanner.h"
#include <iostream>

int scanner::udef = -1;

scanner::scanner(string fname) : file(fname,ios::binary) { //constructor
    q = 0;
    linea = 1;
    lexema = "";

}

scanner::~scanner() {}//destructor

bool scanner::id() {
    
    int actual = 0, prior = 0;

    while (actual != udef) {

        prior = actual;
        char c = read();
        switch (actual) {

        case 0:
            if (isalpha(c)) actual = 2; 
            else if (c == '_') actual = 1; 
            else actual = udef;
            break;

        case 1:
            if (isdigit(c) || c == '_') actual = 1;
            else if (isalpha(c)) actual = 2; 
            else actual = udef;
            break;

        case 2:
            if (isalnum(c) || c == '_') actual = 2; 
            else actual = udef;
            break;

        }

        if (actual != udef) lexema += c;

    }

    if (prior == 2) {
        fback();
        success();
        return true;
    }

    fail();
    return false;
}



void scanner::wsp() {
    char c = ' ';
    while (isspace(c)) {
        c = read();
        if (c == '\n') {
            linea++;
        }

    };// Set position after the next character in file

    fback();
    success();
}

scanner::token scanner::scan() {

    lexema = "";

    if (eof()) { file.close(); return _eof; }//cierra el archivo y retorna el token eof

    wsp();

    if (comentario()) return _coment;

    else if (id()) {
        if (lexema == "true") {
            return  _true;
        }
        else if (lexema == "false") {
            return  _false;
        }
        else if (lexema == "print") {
            return  _print;
        }
        return _id;
        
    }
    switch (numeral())
    {
        case 1:
            return _octal;
            break;
        case 2:
            return _octal;
            break;
        case 5:
            return _hex;
            break;
        case 7:
            return _real;
            break;
        case 8:
            return _entero;
            break;
    }
    switch (delimitador()) {
        case 1:
            return _parizq;
            break;
        case 2:
            return _parder;
            break;
        case 3:
            return _corchizq;
            break;
        case 4:
            return _corchder;
            break;
        }

    switch (puntuador()) {
        case 1:
            return _punto;
            break;
        case 2:
            return _coma;
            break;
        case 3:
            return _puntocoma;
            break;
    }

    switch (operador()) {
        case 1:
            return _def;
            break;
        case 2:
            return _conj;
            break;
        case 3:
            return _disy;
            break;
        case 4:
            return _neg;
            break;
        case 6:
            return _impl;
            break;
    }

    return _err;
}

int scanner::comentario() {
    int actual = 0, prior = 0;

    while (actual != udef) {

        prior = actual;
        char c = read();

        switch (actual) {
        case 0:
            if (c == '#') actual = 1;
            else actual = udef;
            break;

        case 1:
            if (c == '\n') actual = 2;
            else if (isascii(c)) actual = 1;
            break;
        case 2:
            actual = udef;
            break;
        }

    }
    //cout << "hubo un comentario" << endl;
    if (prior == 2) {
        success();
        fback();
        linea++;
        return true;
    }
    fail();
    return false;
}

int scanner::delimitador() {
    int actual = 0, prior = 0;

    while (actual != udef) {

        prior = actual;
        char c = read();
        switch (actual) {

        case 0:
            if (c == '(') actual = 1;
            else if (c == ')') actual = 2;
            else if (c == '[') actual = 3;
            else if (c == ']') actual = 4;
            else actual = udef;
            break;

        case 1:
            actual = udef;
            break;
        case 2:
            actual = udef;
            break;
        case 3:
            actual = udef;
            break;
        case 4:
            actual = udef;
            break;
        }

        if (actual != udef) lexema += c;

    }

    if (prior == 1 || prior == 2 || prior == 3 || prior == 4) {
        fback();
        success();
        return prior;
    }

    fail();
    return false;
}


int scanner::puntuador() {
    int actual = 0, prior = 0;

    while (actual != udef) {

        prior = actual;
        char c = read();
        switch (actual) {

        case 0:
            if (c == '.') actual = 1;
            else if (c == ',') actual = 2;
            else if (c == ';') actual = 3;
            else actual = udef;
            break;

        case 1:
            actual = udef;
            break;

        case 2:
            actual = udef;
            break;

        case 3:
            actual = udef;
            break;
        }

        if (actual != udef) lexema += c;

    }

    if (prior == 1 || prior == 2 || prior == 3) {
        fback();
        success();
        return prior;
    }

    fail();
    return false;
}

int scanner::operador() {
    int actual = 0, prior = 0;

    while (actual != udef) {

        prior = actual;
        char c = read();
        switch (actual) {

        case 0:
            if (c == ':') actual = 1;
            else if (c == '&') actual = 2;
            else if (c == '|') actual = 3;
            else if (c == '!') actual = 4;
            else if (c == '-') actual = 5;
            else actual = udef;
            break;
        case 1:
            actual = udef;
            break;
        case 2:
            actual = udef;
            break;
        case 3:
            actual = udef;
            break;
        case 4:
            actual = udef;
            break;
        case 5:
            if (c == '>') actual = 6;
            else actual = udef;
            break;
        case 6:
            actual = udef;
            break;
            
        }

        if (actual != udef) lexema += c;

    }

    if (prior == 1 || prior == 2 || prior == 3 || prior == 4 || prior == 6) {
        fback();
        success();
        return prior;
    }

    fail();
    return false;
}

//
int scanner::numeral() {
    int actual = 0, prior = 0;

    while (actual != udef) {

        prior = actual;
        char c = read();

        switch (actual) {

        case 0:
            if (c == '0')  actual = 1; 
            else if (isdigit(c) && c != 0) actual = 8;
            else actual = udef;
            break;

        case 1:
            if (isdigit(c) && c != '8' && c != '9') actual = 2;
            else if (c == 'x' || c == 'X') actual = 3;
            else if (c == '.') actual = 6;
            else actual = udef;
            break;

        case 2:
            if (isdigit(c) && c != '8' && c != '9') actual = 2;
            else actual = udef;
            break;

        case 3:
            if (isdigit(c) || tolower(c) == 'a' || tolower(c) == 'b' || tolower(c) == 'c' || tolower(c) == 'd' || tolower(c) == 'e' || tolower(c) == 'f') actual = 4;
            else actual = udef;
            break;

        case 4:
            if (isdigit(c) || tolower(c) == 'a' || tolower(c) == 'b' || tolower(c) == 'c' || tolower(c) == 'd' || tolower(c) == 'e' || tolower(c) == 'f') actual = 5;
            else actual = udef;
            break;

        case 5:
            if (isdigit(c) || tolower(c) == 'a' || tolower(c) == 'b' || tolower(c) == 'c' || tolower(c) == 'd' || tolower(c) == 'e' || tolower(c) == 'f') actual = 4;
            else actual = udef;
            break;

        case 6:
            if (isdigit(c)) actual = 7;
            else actual = udef;
            break;

        case 7:
            if (isdigit(c)) actual = 7;
            else actual = udef;
            break;

        case 8:
            if (isdigit(c)) actual = 8;
            else if (c == '.') actual = 6;
            else actual = udef;
            break;
        }

        if (actual != udef) lexema += c;

    }

    if (prior == 1 || prior == 2 || prior == 5 || prior == 7 || prior == 8)
    {
        fback();
        success();
        return prior;
    }
    
    fail();
    return false;

}
