#ifndef Historial_H
#define Historial_H
#include <string>
using namespace std;

class Historial
{
public:
    int ipNumber;
    string mes, hora, ipAddress, error, dia;

    Historial(string mes, string dia, string hora, string ipAddress, string error, int ipNumber)
    {
        this->mes = mes;
        this->dia = dia;
        this->hora = hora;
        this->ipAddress = ipAddress;
        this->error = error;
        this->ipNumber = ipNumber;
    }
    Historial(){}
};
#endif