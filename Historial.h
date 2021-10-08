#ifndef Historial_H
#define Historial_H
#include <string>
using namespace std;

class Historial
{
public:
    string mes, hora, ipAddress, error, dia;

    Historial(string mes, string dia, string hora, string ipAddress, string error)
    {
        this->mes = mes;
        this->dia = dia;
        this->hora = hora;
        this->ipAddress = ipAddress;
        this->error = error;
    }
};
#endif