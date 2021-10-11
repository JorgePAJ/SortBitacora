#include "MyLinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Historial.h"
using namespace std;

MyLinkedList separador(ifstream &bitacora)
{
    string line, strTemp, mes, dia, hora, ipAddress, error;
    int counter = 0, i = 0;
    MyLinkedList new_list = MyLinkedList();
        while (getline(bitacora, line))
        {
            string temp;
            stringstream buff(line);

            for (int h=0; h<4; h++){
                getline(buff, temp, ' ');
                switch (h)
                {
                case 0: // Caso 0: Mes
                    mes = temp;
                case 1: // Caso 1: Dia
                    dia = temp;
                case 2: // Caso 2: Hora
                    hora = temp;
                case 3: // Caso 3: Ip
                    ipAddress = temp;
                }
            }
            // Sin delimitador
            getline(buff, temp);
            error = temp;

            Historial data(mes, dia, hora, ipAddress, error);    
            new_list.insertLast(data);
        }
  return new_list;
}

int main()
{
    ifstream bitacora;
    bitacora.open("bitacora_head.txt");
    if(!bitacora) { // Sirve para decirnos cuando no se carga el archivo txt
        cout << "No se abrio el archivo correctamente" << endl;
        return 1;
    }   
    MyLinkedList bruh = separador(bitacora);
    cout << "Size " << bruh.length() << endl;

    cout << endl << "FIRST:" << endl;
    cout << "Dia:\t"   << bruh.First().dia << endl;
    cout << "Mes:\t"   << bruh.First().mes << endl;
    cout << "IP:\t"    << bruh.First().ipAddress << endl;
    cout << "Error:\t" << bruh.First().error << endl;

    cout << endl << "LAST:" << endl;
    cout << "Dia:\t"   << bruh.Last().dia << endl;
    cout << "Mes:\t"   << bruh.Last().mes << endl;
    cout << "IP:\t"    << bruh.Last().ipAddress << endl;
    cout << "Error:\t" << bruh.Last().error << endl;

    cout << endl << "bruh 3" << endl;

    
    //cuantos ingenieros se necesitan para escribir length
    return 0;
}