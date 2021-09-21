/*
Autores:
Alexis Gibrán Acosta Pánuco - A01639818
Jorge Plasencia Ahm Jorgensen - A01637493
Emmanuel Humberto Solórzano Cabrera - A01640284

Descripción:
Programa que recibe un archivo de texto con diversas líneas de datos compuestos por mes, día, hora, ip y un error. Dichos datos son separados y acomodados dentro de un vector de
clase "Historial", los cuales son ordenados por fecha y mostrados en un archivo de texto delimitado por el usuario.
*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Historial{
    public:
        long unix;
        string mes, hora, ipAddress, error, dia;
};

long getTime(string hora){
    tm t;{};
    istringstream ss(hora);
    ss >> get_time(&t,"%b%d%H:%M:%S%Y");
    if (ss.fail()){
        throw runtime_error("Error al conseguir la hora");
    }
    time_t time_stamp = mktime(&t);
    return time_stamp;
}

Historial Builder(string mes, string dia, string hora, long unix, string ipAddress, string error){
    Historial Historial;
    Historial.mes = mes;
    Historial.dia = dia;
    Historial.unix = unix;
    Historial.hora = hora;
    Historial.ipAddress = ipAddress;
    Historial.error = error;
    
return Historial;
}

int busqSecuencial(vector<Historial> &valoresFinal, long unix){
    for(int i=0; i < valoresFinal.size() ;i++){
        if(valoresFinal.at(i).unix == unix){
            return i;
        }
    }
    return -1;
}


void swap(vector<Historial> &valoresFin, int i,int  j){
    Historial aux;
    aux = valoresFin.at(i);
    valoresFin.at(i) = valoresFin.at(j);
    valoresFin.at(j) = aux;
}

long particionar(vector<Historial> &valoresFin,int ini, int fin){
    long pivote = valoresFin.at(ini).unix;
    long i = ini + 1;
    for(long j = i;j<=fin;j++){
        if(valoresFin.at(j).unix < pivote){
            swap(valoresFin,i++,j);
        }
    }
    swap(valoresFin,ini,i-1);
    return i-1;
}
void quicksort(vector<Historial> &valoresFin,int ini,int fin){
    if(ini<fin){
        long pospiv = particionar(valoresFin,ini,fin);
        quicksort(valoresFin,ini,pospiv-1);
        quicksort(valoresFin,pospiv+1,fin);
    }
}

void Quicksort(vector<Historial> &valoresFin){
    quicksort(valoresFin,0,valoresFin.size()-1);
}


void getValues(vector<string> &vectorTemporal, vector<Historial> &valoresFin){

        vector<Historial> arregloObjetos;
        string mes = vectorTemporal.at(0);
        string dia = vectorTemporal.at(1);
        string hora = vectorTemporal.at(2);
        string timestamp = mes + dia + hora + "2020";
        long unix = getTime(timestamp);
        string ipAddress = vectorTemporal.at(3);
        string error = vectorTemporal.at(4);
        valoresFin.push_back(Builder(mes, dia, hora, unix,ipAddress, error));
        

}

vector<Historial> separador(ifstream &bitacora){
    string str;
    string strTemp;
    vector<string> vectorTemporal(5,"0");
    vector<Historial> valoresFin;


    int counter = 0;
    int i = 0;
 
    while(getline(bitacora, str)){
      counter = 0;
        while(counter < 4){
            if(str[i] !=' '){
                strTemp += str[i];
            }else{
              switch (counter){
                case 0:
                vectorTemporal.at(0)=strTemp;
                strTemp = "";
                case 1:
                vectorTemporal.at(1) = strTemp;
                strTemp = "";
                case 2:
                vectorTemporal.at(2)=strTemp;
                strTemp = "";
                case 3:
                vectorTemporal.at(3)=strTemp;
                strTemp = "";
              }
                counter++;
                
            }
            i++;
        }
        if (vectorTemporal.at(1).size() == 1){
          
          vectorTemporal.at(1) = "0" + vectorTemporal.at(1);
          
        }
        for (int j = i; j < str.length(); j++)
        {
            strTemp += str[j];
        }


        
        vectorTemporal.at(4) = strTemp;
        strTemp = "";
     
        i = 0;
        getValues(vectorTemporal,valoresFin);
        
    }

  Quicksort(valoresFin);
  return valoresFin;
}


void escribirTxt(vector<Historial> &arreglo,long primerUnix, long ultimoUnix,ofstream &resultados){
    for (int i =0;i < arreglo.size(); i++){
        if(arreglo.at(i).unix >= primerUnix && arreglo.at(i).unix <= ultimoUnix){
            resultados << arreglo.at(i).mes << " " << arreglo.at(i).dia << " " << arreglo.at(i).hora << " " << arreglo.at(i).ipAddress << " " << arreglo.at(i).error << endl;
        }
    }
}

int main(){
    ofstream resultados("Resultados.txt");
    ifstream bitacora;
    string junto,ultijunto,dia,mes,tiempo;
    vector<Historial> arreglo;
    int primaunix, ultimaunix;
    int index,index2;
    bitacora.open("bitacora.txt"); // Cargamos el archivo que se encuentra en el mismo directorio.

    if(!bitacora) { // Sirve para decirnos cuando no se carga el archivo txt
        cout << "No se abrio el archivo correctamente" << endl;
        exit(1);
    }
    arreglo = separador(bitacora);

    cout << "Ingresa el dia (dd) de busqueda inicial: " << endl;
    cin >> dia;
    cout << "Ingresa el mes (Aug,Sep,Oct...) de busqueda inicial: " << endl;
    cin >> mes;
    cout << "Ingresa el tiempo (HH:MM:SS) de busqueda inicial: " << endl;
    cin >> tiempo;

    junto = mes + dia + tiempo+"2020";
    primaunix = getTime(junto);
   
    cout << "Ingresa el dia (dd) de busqueda final: " << endl;
    cin >> dia;
    cout << "Ingresa el mes (mm) de busqueda final: " << endl;
    cin >> mes;
    cout << "Ingresa el tiempo (HH:MM:SS) de busqueda final: " << endl;
    cin >> tiempo;

    ultijunto = mes + dia + tiempo+"2020";

    ultimaunix = getTime(ultijunto);

    ultimaunix = getTime(ultijunto);


    escribirTxt(arreglo,primaunix,ultimaunix,resultados);
    resultados.close();
    return 0;
}
