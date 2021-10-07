#include "MyLinkedList.h"
#include <string>
#include <fstream>
using namespace std;

class Historial{ 
    public:
        string mes, hora, ipAddress, error, dia; 
};

// Constructor de la clase
Historial Builder(string mes, string dia, string hora, string ipAddress, string error){ 
    Historial Historial;
    Historial.mes = mes;
    Historial.dia = dia;
    Historial.hora = hora;
    Historial.ipAddress = ipAddress;
    Historial.error = error;
    
return Historial; // Regresamos el nuevo objeto
}

MyNodeLL separador(ifstream &bitacora){
    string str, strTemp;
    MyNodeLL* nodoRetorno;
    Historial data;
    int counter = 0;
    int i = 0;
    int builderCounter = 0;
    string mes, dia, hora, ipAddress, error;
    while(getline(bitacora, str)){
        counter = 0;
        while (counter < 4){
            if(str[i] !=' '){
                strTemp += str[i];
            }else{
                switch (counter){
                    case 0: // Caso 0: Mes
                    mes = strTemp;
                    strTemp = "";
                    case 1:// Caso 1: Dia
                    dia = strTemp;
                    strTemp = "";
                    case 2:// Caso 2: Hora
                    hora = strTemp;
                    strTemp = "";
                    case 3:// Caso 3: Ip
                    ipAddress = strTemp;
                    strTemp = "";
                }
            }
        }
        for (int j = i; j < str.length(); j++){
            strTemp += str[j]; // Se vuelve a armar el string del error.
        }
        error = strTemp;
        strTemp = "";
        data = Builder(mes,dia,hora,ipAddress,error);
    }
}
int main(){ 
    return 0;
}