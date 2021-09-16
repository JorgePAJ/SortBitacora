#include  <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Historial{
    public:
        int  dia;
        long horaUnix, mesUnix, diaUnix;
        string mes, hora, ipAddress, error;
};

long getDia(string diaUnix){
    tm t;{};
    istringstream ss(diaUnix);

    ss >> get_time(&t,"%d");
    if (ss.fail()){
        throw runtime_error("Error al conseguir el dia");
    }
    time_t time_stamp = mktime(&t);
    return time_stamp;
}

long getMes(string mes){
    tm t;{};
    istringstream ss(mes);

    ss >> get_time(&t,"%m");
    if (ss.fail()){
        throw runtime_error("Error al conseguir el mes");
    }
    time_t time_stamp = mktime(&t);
    return time_stamp;
}

long getTime(string hora){
    tm t;{};
    istringstream ss(hora);

    ss >> get_time(&t,"%H:%M:%S");
    if (ss.fail()){
        throw runtime_error("Error al conseguir la hora");
    }
    time_t time_stamp = mktime(&t);
    return time_stamp;
}

string mesToNum (string mes){
    string mesInt = "";
    if (mes == "Jan"){
        mesInt = "1";
    }else if(mes == "Feb"){
        mesInt = "2";
    }else if(mes == "Mar"){
        mesInt = "3";
    }else if(mes == "Apr"){
        mesInt = "4";
    }else if(mes == "May"){
        mesInt = "5";
    }else if(mes == "Jun"){
        mesInt = "6";
    }else if(mes == "Jul"){
        mesInt = "7";
    }else if(mes == "Aug"){
        mesInt = "8";
    }else if(mes == "Sep"){
        mesInt = "9";
    }else if(mes == "Oct"){
        mesInt = "10";
    }else if(mes == "Nov"){
        mesInt = "11";
    }else if(mes == "Dic"){
        mesInt = "12";
    }
    return mesInt;
}

Historial Builder(string mes, int dia, string hora, long horaUnix,long mesUnix, long diaUnix,string ipAddress, string error){
    Historial Historial;
    Historial.mes = mes;
    Historial.dia = diaUnix;
    Historial.horaUnix = horaUnix;
    Historial.mesUnix = mesUnix;
    Historial.diaUnix = diaUnix;
    Historial.hora = hora;
    Historial.ipAddress = ipAddress;
    Historial.error = error;
return Historial;
}

vector<Historial> separador(ifstream &bitacora){
    string str;
    string strTemp;
    vector<string> vectorTemporal;
    vector<Historial> arregloObjetos;
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
        long mesUnix = getMes(mesToNum(vectorTemporal.at(0))) ;
        long diaUnix = getDia(mesToNum(vectorTemporal.at(1)));
        int dia = stoi(vectorTemporal.at(1));
        string hora = vectorTemporal.at(2);
        long horaUnix = getTime(hora);
        string ipAddress = vectorTemporal.at(3);
        string error = vectorTemporal.at(4);
        cout << mes <<endl;
        arregloObjetos.push_back(Builder(mes, dia, hora, horaUnix, mesUnix, diaUnix, ipAddress, error));
    }
    return arregloObjetos;
};

int main(){

    ifstream bitacora;
    bitacora.open("bitacora.txt"); // Cargamos el archivo que se encuentra en el mismo directorio.

    if(!bitacora) { // Sirve para decirnos cuando no se carga el archivo txt
        cout << "No se abrio el archivo correctamente" << endl;
        exit(1);
    }
    vector<Historial> arregloBitacora = separador(bitacora);
    return 0;
}
