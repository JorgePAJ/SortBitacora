#include  <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Historial{
    public:
        int  dia;
        long hora;
        string mes, ipAddress, error;
};

long getTime(string hora){
    tm t{};
    istringstream ss(hora);

    ss >> get_time(&t,"%H:%M:%S");
    if (ss.fail()){
        throw runtime_error{"Error al conseguir la hora"};
    }
    time_t time_stamp = mktime(&t);
    return time_stamp;
}

Historial Builder(string mes, int dia, long hora, string ipAddress, string error){
    Historial Historial;
    Historial.mes = mes;
    Historial.dia = dia;
    Historial.hora = hora;
    Historial.ipAddress = ipAddress;
    Historial.error = error;
return Historial;
}

vector<Historial> separador(ifstream &bitacora){
    string str;
    string strTemp;
    vector<string> vectorTemporal;
    int counter = 0;
    while(getline(bitacora, str)){
        while(counter < 4){
            for (int i = 0; i < str.length();i++ ){
                if(str[i] !=' '){
                    strTemp += str[i];
                }else{
                    vectorTemporal.push_back(strTemp);
                    strTemp = "";
                }
            }
        }
        string mes = vectorTemporal.at(0);
        int dia = stoi(vectorTemporal.at(1));
        long hora = getTime(vectorTemporal.at(2));
        string ipAddress = vectorTemporal.at(3);
        string error = vectorTemporal.at(4);
        Builder(mes, dia, hora, ipAddress, error);
    }
};

int main(){

    ifstream bitacora;
    bitacora.open("bitacora.txt"); // Cargamos el archivo que se encuentra en el mismo directorio.

    if(!bitacora) { // Sirve para decirnos cuando no se carga el archivo txt
        cout << "No se abrio el archivo correctamente" << endl;
        exit(1);
    }

    separador(bitacora);
    return 0;
}
