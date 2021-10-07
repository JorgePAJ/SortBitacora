#include "MyLinkedList.h"
using namespace std;

class Historial{ 
    public:
        string mes, hora, ipAddress, error, dia; //Estos valores solo sirven para ser impresos y definir la unix timestamp
};

// Constructor de la clase
Historial Builder(string mes, string dia, string hora, long unix, string ipAddress, string error){ 
    Historial Historial;
    Historial.mes = mes;
    Historial.dia = dia;
    Historial.hora = hora;
    Historial.ipAddress = ipAddress;
    Historial.error = error;
    
return Historial; // Regresamos el nuevo objeto
}

int main(){
    
    return 0;
}