#include "scanner.h"
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {

    cout << "ingresa el nombre del archivo, asegurese de añadir la extrensión del mismo (ejemplo: archivo.txt):" << endl;
    string nArchivo;
    cin >> nArchivo;
    scanner f(nArchivo);
    cout << "Iniciando analisis..." << endl;
    //scanner f("hola.txt");

    scanner::token t;
    
    do {

        t = f.scan();

        switch (t) {
        case scanner::_id:
            cout << f.lexema << "\tid" << endl;
            break;

        case scanner::_true:
            cout << f.lexema << "\ttrue" << endl;
            break;

        case scanner::_false:
            cout << f.lexema << "\tfalse" << endl;
            break;

        case scanner::_print:
            cout << f.lexema << "\tprint" << endl;
            break;

        case scanner::_octal:
            cout << f.lexema << "\toctal" << endl;
            break;

        case scanner::_entero:
            cout << f.lexema << "\tentero" << endl;
            break;

        case scanner::_hex:
            cout << f.lexema << "\thexadecimal" << endl;
            break;

        case scanner::_real:
            cout << f.lexema << "\treal" << endl;
            break;

        case scanner::_parder:
            cout << f.lexema << "\tparentesis derecho" << endl;
            break;

        case scanner::_parizq:
            cout << f.lexema << "\tparentesis izquierdo" << endl;
            break;

        case scanner::_corchder:
            cout << f.lexema << "\tcorchete derecho" << endl;
            break;

        case scanner::_corchizq:
            cout << f.lexema << "\tcorchete izquierdo" << endl;
            break;

        case scanner::_punto:
            cout << f.lexema << "\tpunto" << endl;
            break;

        case scanner::_coma:
            cout << f.lexema << "\tcoma" << endl;
            break;

        case scanner::_puntocoma:
            cout << f.lexema << "\tpunto y coma" << endl;
            break;

        case scanner::_def:
            cout << f.lexema << "\tdefinicion" << endl;
            break;

        case scanner::_conj:
            cout << f.lexema <<"\tconjuncion" << endl;
            break;

        case scanner::_disy:
            f.lexema += "\tdisyuncion";
            cout << f.lexema << endl;
            break;

        case scanner::_neg:
            f.lexema += "\tnegacion";
            cout << f.lexema << endl;
            break;

        case scanner::_impl:
            f.lexema += "\timplicacion";
            cout << f.lexema << endl;
            break;

        case scanner::_err:
            cout << "\nerror en la linea: "<<f.linea<< endl;
            break;

        case scanner::_eof:
            cout << "eof\n" << endl;
            break;
        }

    } while (t != scanner::_eof && t != scanner::_err);
    cout << "\nFin del analisis" << endl;
    cout << "Se leyeron: "<<f.linea<<" lineas"<< endl;

}