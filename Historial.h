#ifndef Historial_H
#define Historial_H
#include <string>
using namespace std;

class Historial
{
public:
    long ipNumber;
    long cuadrante1,cuadrante2,cuadrante3,cuadrante4,cuadrante5;
    string mes, hora, ipAddress, error, dia;

    Historial(string mes, string dia, string hora, string ipAddress, string error, long ipNumber,long cuadrante1, long cuadrante2,long cuadrante3,long cuadrante4,long cuadrante5)
    {
        this->mes = mes;
        this->dia = dia;
        this->hora = hora;
        this->ipAddress = ipAddress;
        this->error = error;
        this->ipNumber = ipNumber;
        this->cuadrante1 = cuadrante1;
        this->cuadrante2 = cuadrante2;
        this->cuadrante3 = cuadrante3;
        this->cuadrante4 = cuadrante4;
        this->cuadrante5 = cuadrante5;

    }
    Historial(){}
};
#endif