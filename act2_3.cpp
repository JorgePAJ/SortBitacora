/*
Programa que ordena un archivo de texto a partir de las Ips proporcionadas por el usuario
Alexis Gibrán Acosta Pánuco A01639818
Jorge Plasencia Ahm Jorgensen A01637493
Fecha de creacion 5/10/2021
Fecha de ultima modificacion 14/10/2021
*/
#include "MyLinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Historial.h"
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
// Complejidad O(N)
//Funcion que obtiene las cuadrantes de las ips y regresa  una variable ipNumber
//La cual se usa para comparar en el merge
long ipToNumber(string ip){
  long ipNumber, cuadrante1, cuadrante2, cuadrante3, cuadrante4, cuadrante5;
  string ipPointless = ip, ipPointless1, ipPointless2, ipPointless3, ipPointless4, ipPointless5;
  char c = '.';
  char p = ':';
  int i = 1, len = ipPointless.length();
  stringstream bits(ipPointless);
  //While que guarda los cuadrantes mientras que i sea menor a la longitud de la Ip
  while (i < len){
    getline(bits, ipPointless1, c);
    getline(bits, ipPointless2, c);
    getline(bits, ipPointless3, c);
    getline(bits, ipPointless4, p);
    getline(bits, ipPointless5, c);
    i++;
  }

  cuadrante1 = stol(ipPointless1);
  cuadrante2 = stol(ipPointless2);
  cuadrante3 = stol(ipPointless3);
  cuadrante4 = stol(ipPointless4);
  cuadrante5 = stol(ipPointless5);
  ipNumber = (cuadrante1 * 16777216) + (cuadrante2 * 65536) + (cuadrante3 * 256) + (cuadrante4); //El valor utilizado para sortear las IPs.
  return ipNumber;
}

//Funcion mezcla, sortea todos los datos acomodandolo de manera descendente segun sus ips
void mezcla(int ini, int fin, MyLinkedList &ll){
  Historial data;
  int centro = (ini + fin) / 2;
  int j = ini,
      k = centro + 1,
      size = (fin - ini + 1);
  Historial datostmp[size];
  for (int i = 0; i < size; i++){
    if (j <= centro && k <= fin)
    {
      //If que guarda los datos en un arreglo temporal mientras los datos en j sean mayor a los de k si no se cumple guarda los datos en k
      if (ll.getAt(j).ipNumber > ll.getAt(k).ipNumber){
        datostmp[i] = ll.getAt(j++);
      }
      else{
        datostmp[i] = ll.getAt(k++);
      }
    }
    else if (j <= centro){
      datostmp[i] = ll.getAt(j++);
    }
    else{
      datostmp[i] = ll.getAt(k++);
    }
  }
  //Devuelve los datos a la lista enlazada de acuerdo a la posicion m
  for (int m = 0; m < size; m++){
    ll.setAt(datostmp[m], m + ini);
  }
}

//Funcion que parte por la mitad los datos proporcionados
void Ordenamerge(int ini, int fin, MyLinkedList &ll){
  if (ini < fin){
    int centro = (ini + fin) / 2;
    Ordenamerge(ini, centro, ll);
    Ordenamerge(centro + 1, fin, ll);
    mezcla(ini, fin, ll);
  }
}
// Complejidad O(n*Log n)
//Funcion que pide los datos a sortear
void ordenaMerge(MyLinkedList &ll){
  Ordenamerge(0, ll.length() - 1, ll);
  return;
}

// Complejidad O(N^2)
//Funcion que lee un archivo de texto y separa los datos de una linea guardandolos en una Lista enlazada.
MyLinkedList separador(ifstream &bitacora){
  string line, strTemp, mes, dia, hora, ipAddress, error, ipPointless1, ipPointless, ipPointless2, ipPointless3, ipPointless4, ipPointless5;
  int counter = 0, i = 0;
  long ipNumber;
  long cuadrante1, cuadrante2, cuadrante3, cuadrante4, cuadrante5;
  MyLinkedList new_list = MyLinkedList();
  //while que obtiene los datos mientas siga leyendo la bitacora
  while (getline(bitacora, line)){
    string temp;
    stringstream buff(line);
    //For que divide las variables de una sola linea de texto delimitado por espacios ' '
    for (int h = 0; h < 4; h++){
      temp = "";
      getline(buff, temp, ' ');
      //Switch que guarda las variables en un string temporal de acuerdo a los casos de h utilizado en el for
      switch (h){
      case 0: // Caso 0: Mes
        mes = temp;
        break;
      case 1: // Caso 1: Dia
        dia = temp;
        break;
      case 2: // Caso 2: Hora
        hora = temp;
        break;
      case 3: // Caso 3: Ip
        ipAddress = temp;
        ipPointless = ipAddress;
        ipNumber = ipToNumber(ipPointless);
      }
    }
    // Sin delimitador
    getline(buff, temp);
    error = temp;

    Historial data(mes, dia, hora, ipAddress, error, ipNumber);
    new_list.insertLast(data);
  }
  return new_list;
}

// Complejidad O(N)
//Guarda los datos de la lista enlazada y los imprime en un nuevo archivo de texto las veces que lo solicite el usuario
void escribirTxt(MyLinkedList &bruh, long primerIp, long ultimoIp, ofstream &resultados){
  for (int i = 0; i < bruh.length(); i++){
    //If que guarda los datos en un archivo de texto mientras esten en el rango proporcionado por el usuario
    if (bruh.getAt(i).ipNumber <= primerIp && bruh.getAt(i).ipNumber >= ultimoIp){
      resultados << bruh.getAt(i) << endl; // Aqui escribe sobre el archivo
    }
  }
}
// Complejidad O(2 N)

//Main del programa el cual pide los datos al usuario y crea un archivo de texto nuevo donde muestra los datos del archivo ya ordenados 
int main(){
  int counter = 1;
  string primerIp, ultimoIp;
  string pregunta;
  ifstream bitacora;
  ofstream ordenado("bitacoraOrdenada-Eq4.txt");
  bitacora.open("bitacora_head.txt");
  if (!bitacora){ // Sirve para decirnos cuando no se carga el archivo txt
    cout << "No se abrio el archivo correctamente" << endl;
    return 1;
  }
  MyLinkedList bruh = separador(bitacora);
  ordenaMerge(bruh);
  
  //Exporta los datos ordenados en un nuevo archivo
  //Complejidad O(N)
  ordenado << bruh << endl;
  

  ordenado.close();
  string name;
  while (pregunta != "s"){
    name = "Salida" + to_string(counter) + "-Eq4";
    name += ".txt";
    ofstream file(name.c_str());
    cout << "Ingresa la primera IP: " << endl;
    cin >> primerIp;
    cout << "Ingresa la segunda IP: " << endl;
    cin >> ultimoIp;
    escribirTxt(bruh, ipToNumber(primerIp), ipToNumber(ultimoIp), file);
    file.close();
    cout << "Ingrese s para salir, o cualquier otra letra para continuar: " << endl;
    cin >> pregunta;
    counter++;
  }
  return 0;
}