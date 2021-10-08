#include "MyLinkedList.h"
#include <string>
#include <fstream>
#include "Historial.h"
using namespace std;

MyNodeLL separador(ifstream &bitacora)
{
    string str, strTemp;
    int counter = 0;
    int i = 0;
    string mes, dia, hora, ipAddress, error;
    while (getline(bitacora, str))
    {
        counter = 0;
        while (counter < 4)
        {
            if (str[i] != ' ')
            {
                strTemp += str[i];
            }
            else
            {
                switch (counter)
                {
                case 0: // Caso 0: Mes
                    mes = strTemp;
                    strTemp = "";
                case 1: // Caso 1: Dia
                    dia = strTemp;
                    strTemp = "";
                case 2: // Caso 2: Hora
                    hora = strTemp;
                    strTemp = "";
                case 3: // Caso 3: Ip
                    ipAddress = strTemp;
                    strTemp = "";
                }
            }
        }
        for (int j = i; j < str.length(); j++)
        {
            strTemp += str[j]; // Se vuelve a armar el string del error.
        }
        error = strTemp;
        strTemp = "";
        Historial data(mes, dia, hora, ipAddress, error);
        MyNodeLL *nodoRetorno = new MyNodeLL(data, nodoRetorno->next);
    }
}

int main()
{

    return 0;
}