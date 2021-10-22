#ifndef Historial_H
#define Historial_H
#include <string>
using namespace std;

class Historial
{
public:
    long ipNumber;
    string mes, hora, ipAddress, error, dia;

    Historial(string mes, string dia, string hora, string ipAddress, string error, long ipNumber)
    {
        this->mes = mes;
        this->dia = dia;
        this->hora = hora;
        this->ipAddress = ipAddress;
        this->error = error;
        this->ipNumber = ipNumber;
    }
    friend ostream& operator<<(ostream& os,const Historial& ll){
        os << ll.ipAddress.substr(0,ll.ipAddress.size()-5);
    return os;
}
    Historial(){}
};
#endif