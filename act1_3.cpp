#include  <vector>
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

    ss >> get_time(&t,"%b%d%H:%M:%S");
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
int particionar(int ini, int fin,vector<Historial> &valoresFin){
    int pivote = valoresFin[ini].unix;
    int i = ini + 1;
    for(int j = i;j<=fin;j++){
        if(valoresFin[j].unix < pivote){
            swap(valoresFin.at(i++),valoresFin.at(j));
        }
    }
    swap(valoresFin.at(ini),valoresFin.at(i-1));
    return i-1;
}
void quicksort(int ini,int fin,vector<Historial> &valoresFin){
    if(ini<fin){
        int pospiv = particionar(ini,fin,valoresFin);
        quicksort(ini,pospiv-1,valoresFin);
        quicksort(pospiv+1,fin,valoresFin);
    }
}

void Quicksort(vector<Historial> &valoresFin){
    quicksort(0,valoresFin.size()-1,valoresFin);
}
void getValues(vector<string> &vectorTemporal, vector<Historial> &valoresFin){

        vector<Historial> arregloObjetos;
        string mes = vectorTemporal.at(0);
        string dia = vectorTemporal.at(1);
        string hora = vectorTemporal.at(2);
        string timestamp = vectorTemporal.at(0) + vectorTemporal.at(1) + vectorTemporal.at(2);
        long unix = getTime(timestamp);
        string ipAddress = vectorTemporal.at(3);
        string error = vectorTemporal.at(4);
        /*
        cout << "Mes: " << vectorTemporal.at(0) << endl;
        cout << "Dia: " << vectorTemporal.at(1)<<endl;
        cout << "Hora: " << vectorTemporal.at(2)<< endl;
        cout << "iP: " << vectorTemporal.at(3) << endl;
        cout <<"Error: " << vectorTemporal.at(4) << endl;
        cout << "Tiempo unix: " << getTime(timestamp) << endl; 
    */
        valoresFin.push_back(Builder(mes, dia, hora, unix,ipAddress, error));
        

}

void separador(ifstream &bitacora){
    string str;
    string strTemp;
    vector<string> vectorTemporal{"0","0","0","0","0"};
    vector<Historial> valoresFin;


    int counter = 0;
    int i = 0;
 
    while(getline(bitacora, str)){
      //cout <<str<< endl;
      counter = 0;
        while(counter < 4){
            if(str[i] !=' '){
                strTemp += str[i];
            }else{
              //cout << strTemp << endl;
              
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
  cout << valoresFin[1].error << endl;
  Quicksort(valoresFin);
  for(int i = 0; i < 5;i++){
        cout << valoresFin[i].unix << endl;
  }
}


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
