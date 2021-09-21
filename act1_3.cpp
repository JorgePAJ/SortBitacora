/*
Autores:
Alexis Gibrán Acosta Pánuco - A01639818
Jorge Plasencia Ahm Jorgensen - A01637493
Emmanuel Humberto Solórzano Cabrera - A01640284

Descripción:
Programa que recibe un archivo de texto con diversas líneas de datos compuestos por mes, día, hora, ip y un error. Dichos datos son separados y acomodados dentro de un vector de
clase "Historial", los cuales son ordenados por fecha de mas reciente a mas antiguo y mostrados en un archivo de texto delimitado por el usuario.
*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
// Definimos la clase Historial con los atributos del archivo de texto
class Historial{ 
    public:
        long unix; // la unix timestamp es el valor que usaremos para las comparaciones.
        string mes, hora, ipAddress, error, dia; //Estos valores solo sirven para ser impresos y definir la unix timestamp
};

//Esta funcion transforma un string a la hora en unix timestamp
//Nos apoyamos en el comentario de Joanna para entender la libreria.
//https://stackoverflow.com/questions/17681439/convert-string-time-to-unix-timestamp
long getTime(string hora){ 
    tm t;{};
    istringstream ss(hora);
    ss >> get_time(&t,"%b%d%H:%M:%S%Y"); // Se define el formato que leera la funcion.
    if (ss.fail()){
        throw runtime_error("Error al conseguir la hora"); //En caso error lanzar msj.
    }
    time_t time_stamp = mktime(&t);
    return time_stamp;
}
// Constructor de la clase
Historial Builder(string mes, string dia, string hora, long unix, string ipAddress, string error){ 
    Historial Historial;
    Historial.mes = mes;
    Historial.dia = dia;
    Historial.unix = unix;
    Historial.hora = hora;
    Historial.ipAddress = ipAddress;
    Historial.error = error;
    
return Historial; // Regresamos el nuevo objeto
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
        if(valoresFin.at(j).unix > pivote){ // el > es inverso, el cual nos dara los resultados de manera descendente.
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

//O(n^2).
// Utilizamos el metodo quick sort para manipular los datos.
void Quicksort(vector<Historial> &valoresFin){ 
    quicksort(valoresFin,0,valoresFin.size()-1);
}

// Esta funcion arma el vector por acomodar.
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

// Esta funcion separa y divide el archivo de texto en un formato trabajable.
vector<Historial> separador(ifstream &bitacora){ 
    string str; // Variable donde se guardara cada linea del archivo
    string strTemp; // Variable que va re armando las palabras para ser guardadas.
    vector<string> vectorTemporal(5,"0");// Vector donde se guardara la informacion para la creacion de objetos.
    vector<Historial> valoresFin; // Vector donde se guardaran al fin los elementos del archivo de txt en objetos.


    int counter = 0;
    int i = 0;
 
    while(getline(bitacora, str)){ // Getline lo utilizamos para leer las lineas del archivo original.
      counter = 0;
        while(counter < 4){
            if(str[i] !=' '){
                strTemp += str[i];
            }else{ 
              switch (counter){ // En caso de encontrar un espacio, el switch lo acomodara en su posicion correspondiente.
                case 0: // Caso 0: Mes
                vectorTemporal.at(0)=strTemp;
                strTemp = "";
                case 1:// Caso 1: Dia
                vectorTemporal.at(1) = strTemp;
                strTemp = "";
                case 2:// Caso 2: Hora
                vectorTemporal.at(2)=strTemp;
                strTemp = "";
                case 3:// Caso 3: Ip
                vectorTemporal.at(3)=strTemp;
                strTemp = "";
              }
                counter++;
                
            }
            i++;
        }
        if (vectorTemporal.at(1).size() == 1){ // La funcion get_time necesita tener el dia con dos valores, si es uno, agregar 0 al inicio
          
          vectorTemporal.at(1) = "0" + vectorTemporal.at(1);
          
        }
        for (int j = i; j < str.length(); j++)
        {
            strTemp += str[j]; // Se vuelve a armar el string del error.
        }


        
        vectorTemporal.at(4) = strTemp;
        strTemp = "";
     
        i = 0;
        getValues(vectorTemporal,valoresFin);
        
    }

  Quicksort(valoresFin); // Se ordena el vector valoresFin base a su valor de unix timestamp
  return valoresFin;
}

//Orden O(n).
// Esta funcion escribe el archivo de texto final
void escribirTxt(vector<Historial> &arreglo,long primerUnix, long ultimoUnix,ofstream &resultados){ 
    for (int i =0;i < arreglo.size(); i++){
        if(arreglo.at(i).unix >= primerUnix && arreglo.at(i).unix <= ultimoUnix){
            resultados << arreglo.at(i).mes << " " << arreglo.at(i).dia << " " << arreglo.at(i).hora << " " << arreglo.at(i).ipAddress << " " << arreglo.at(i).error << endl; // Aqui escribe sobre el archivo
        }
    }
}

int main(){
    ofstream resultados("Resultados.txt"); // Se crea el archivo de texto de salida
    ifstream bitacora; // Se crea la variable del archivo de texto de entrada
    string junto,ultiJunto,dia,mes,tiempo; // Se crean las variables necesarias para definir la busqueda
    vector<Historial> arreglo; // Se crea la variable donde esta el vector final
    int primaUnix, ultimaUnix;// Valor unix del primer y segundo delimitante
    bitacora.open("bitacora.txt"); // Cargamos el archivo que se encuentra en el mismo directorio.

    if(!bitacora) { // Sirve para decirnos cuando no se carga el archivo txt
        cout << "No se abrio el archivo correctamente" << endl;
        exit(1);
    }
    arreglo = separador(bitacora);

    cout << "Ingresa el dia (01,10,31...) de busqueda inicial: " << endl;
    cin >> dia;
    if (dia.size() == 1){ // La funcion get_time necesita tener el dia con dos valores, si es uno, agregar 0 al inicio
          
        dia = "0" + dia;
          
    }
    cout << "Ingresa el mes (Aug,Sep,Oct...) de busqueda inicial: " << endl;
    cin >> mes;
    cout << "Ingresa el tiempo (HH:MM:SS) de busqueda inicial: " << endl;
    cin >> tiempo;

    junto = mes + dia + tiempo+"2020";
    primaUnix = getTime(junto); // Se consigue el valor de unix timestamp
   
    cout << "Ingresa el dia (dd) de busqueda final: " << endl;
    cin >> dia;
    cout << "Ingresa el mes (mm) de busqueda final: " << endl;
    cin >> mes;
    cout << "Ingresa el tiempo (HH:MM:SS) de busqueda final: " << endl;
    cin >> tiempo;

    ultiJunto = mes + dia + tiempo+"2020";
    ultimaUnix = getTime(ultiJunto);// Se consigue el valor de unix timestamp

    escribirTxt(arreglo,primaUnix,ultimaUnix,resultados); // Llama la funcion para escribir el archivo final
    resultados.close(); // Termina con el archivo
    return 0;
}
