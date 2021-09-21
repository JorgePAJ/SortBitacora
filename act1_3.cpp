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

void cambiarTxt(vector<Historial> &valoresFin, ofstream &resultados, int i){
    resultados << valoresFin.at(i).mes + " " + valoresFin.at(i).dia;
}

long getTime(string hora){
    tm t;{};
    istringstream ss(hora);
<<<<<<< Updated upstream
    //cout << hora << endl;
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
        //cout <<"mes: " <<mes << endl;
        //cout <<"dia: "<< dia << endl;
        //cout <<"Hora: "<< hora << endl;
        cout <<"timestamp" <<timestamp << endl;
=======
>>>>>>> Stashed changes
        long unix = getTime(timestamp);
        cout <<"unix: " << unix << endl;
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
    cout << "Ingresa el mes (mm) de busqueda inicial: " << endl;
    cin >> mes;
    cout << "Ingresa el tiempo (HH:MM:SS) de busqueda inicial: " << endl;
    cin >> tiempo;

    junto = mes + dia + tiempo+"2020";
    primaunix = getTime(junto);
    index = busqSecuencial(arreglo,primaunix);

    cout << "Ingresa el dia (dd) de busqueda final: " << endl;
    cin >> dia;
    cout << "Ingresa el mes (mm) de busqueda final: " << endl;
    cin >> mes;
    cout << "Ingresa el tiempo (HH:MM:SS) de busqueda final: " << endl;
    cin >> tiempo;

    ultijunto = mes + dia + tiempo+"2020";
<<<<<<< Updated upstream
   //cout<< junto <<endl;
    ultimaunix = getTime(ultijunto);
    //i = busqSecuencial(arreglo,)
    index2 = busqSecuencial(arreglo,ultimaunix);
    //cout<<primaunix<<endl;
    //cout<<ultimaunix<<endl;
    for(int i = index;index <= index2;i++){
        cout<< "" <<endl;
    }
=======
    ultimaunix = getTime(ultijunto);

    index2 = busqSecuencial(arreglo,ultimaunix);

    for(int i = index; i <= index2; i++){
        cambiarTxt(arreglo, resultados,i);
    }
    resultados.close();
>>>>>>> Stashed changes
    return 0;
}