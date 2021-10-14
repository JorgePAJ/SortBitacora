#include "MyLinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Historial.h"
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

void mezcla(int ini, int fin, MyLinkedList &ll){
  Historial data;
  int centro = (ini+fin)/2;
  int j = ini,
      k = centro + 1,
      size = (fin - ini + 1);
  Historial datostmp[size];
  
  for(int i = 0; i < size;i++){
      if(j <= centro && k <=fin){
          if( ll.getAt(j).cuadrante1 < ll.getAt(k).cuadrante1){ 
            datostmp[i] = ll.getAt(j++);
          //if 1
          }else if(ll.getAt(j).cuadrante1 == ll.getAt(k).cuadrante1){
            if(ll.getAt(j).cuadrante2 < ll.getAt(k).cuadrante2){
              datostmp[i] = ll.getAt(j++);
            }else if(ll.getAt(j).cuadrante2 == ll.getAt(k).cuadrante2){
                //if 2
                if(ll.getAt(j).cuadrante2 < ll.getAt(k).cuadrante2){
                  datostmp[i] = ll.getAt(j++);
                }else if(ll.getAt(j).cuadrante3 == ll.getAt(k).cuadrante3){
                  //if 3
                  if(ll.getAt(j).cuadrante3 < ll.getAt(k).cuadrante3){
                    datostmp[i] = ll.getAt(j++);
                  }else if(ll.getAt(j).cuadrante3 == ll.getAt(k).cuadrante3){
                    //if 4
                    if(ll.getAt(j).cuadrante4 < ll.getAt(k).cuadrante4){
                      datostmp[i] = ll.getAt(j++);
                    }else if(ll.getAt(j).cuadrante4 == ll.getAt(k).cuadrante4){
                      //if 5
                      if(ll.getAt(j).cuadrante5 < ll.getAt(k).cuadrante5){
                        datostmp[i] = ll.getAt(j++);
                      }else if(ll.getAt(j).cuadrante5 == ll.getAt(k).cuadrante5){
                        datostmp[i] = ll.getAt(j++);

                      }else{
                      datostmp[i] = ll.getAt(k++);
              
            }
                    }else{
                      datostmp[i] = ll.getAt(k++);
            }
                  }else{
                    datostmp[i] = ll.getAt(k++);
            }
                }else{
                  datostmp[i] = ll.getAt(k++);
            }
            }else{
              datostmp[i] = ll.getAt(k++);
              
            }
          }
          else{
            datostmp[i] = ll.getAt(k++);
          }
      }
      else if(j<=centro){
        datostmp[i] = ll.getAt(j++);
    
      }else{
        datostmp[i] = ll.getAt(k++);

      }
  }
  for (int m = 0; m < size; m++){
    ll.setAt(datostmp[m], m+ini);
  }
}

void Ordenamerge(int ini,int fin, MyLinkedList &ll){
    if(ini<fin){
        int centro = (ini+fin)/2;
        Ordenamerge(ini,centro,ll);
        Ordenamerge(centro+1,fin,ll);
        mezcla(ini,fin,ll);
    }
}


void ordenaMerge(MyLinkedList &ll){ 
    Ordenamerge(0, ll.length()-1, ll);
    return;

}

string ipAdress = {};

MyLinkedList separador(ifstream &bitacora)
{
    string line, strTemp, mes, dia, hora, ipAddress, error, ipPointless1,ipPointless,ipPointless2,ipPointless3,ipPointless4,ipPointless5;
    int counter = 0, i = 0;
    long ipNumber;
    long cuadrante1, cuadrante2, cuadrante3, cuadrante4, cuadrante5;
    MyLinkedList new_list = MyLinkedList();
        while (getline(bitacora, line))
        {
            string temp;
            stringstream buff(line);

            for (int h=0; h<4; h++){
                temp = "";
                getline(buff, temp, ' ');
                switch (h)
                {
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
                        char c = '.';
                        char p = ':';
                        int i = 1, len = ipPointless.length();
                        stringstream bits(ipPointless);
              
                        while(i < len){
                          getline(bits,ipPointless1,c);
                          getline(bits,ipPointless2,c);
                          getline(bits,ipPointless3,c);
                          getline(bits,ipPointless4,p);
                          getline(bits,ipPointless5,c);
                          i++;
                        
                        }

                    cuadrante1 = stol(ipPointless1);
                    cuadrante2 = stol(ipPointless2);
                    cuadrante3 = stol(ipPointless3);
                    cuadrante4 = stol(ipPointless4);
                    cuadrante5 = stol(ipPointless5);                                                                                
                    break;
                }
            }

            // Sin delimitador
            getline(buff, temp);
            error = temp;

            Historial data(mes, dia, hora, ipAddress, error, ipNumber,cuadrante1,cuadrante2,cuadrante3,cuadrante4,cuadrante5);    
            new_list.insertLast(data);
            // new_list.insertFirst(data);
        }
  return new_list;
}
void escribirTxt(MyLinkedList &bruh,long primerIp, long ultimoIp,ofstream &resultados){ 
    for (int i =0;i < bruh.length(); i++){
        if(bruh.getAt(i).ipAddress == to_string(primerIp) && bruh.getAt(i).ipAddress == to_string(ultimoIp)){
            resultados << bruh.getAt(i).mes << " " << bruh.getAt(i).dia << " " << bruh.getAt(i).hora << " " << bruh.getAt(i).ipAddress << " " << bruh.getAt(i).error << endl; // Aqui escribe sobre el archivo
        }
    }
}


int main()
{   
    long primerIp, ultimoIp;
    ofstream resultados("Resultados.txt");
    ifstream bitacora;
    bitacora.open("bitacora_head.txt");
    if(!bitacora) { // Sirve para decirnos cuando no se carga el archivo txt
        cout << "No se abrio el archivo correctamente" << endl;
        return 1;
    }   
    MyLinkedList bruh = separador(bitacora);
    ordenaMerge(bruh);
    MyNodeLL *current = bruh.firstNode();

    while (current != nullptr){
      cout << current->data.ipAddress << endl;
      current = current->next;
    } 
    cout << "Ingresa la primera IP: ";
    cin >> primerIp;
    cout << "Ingresa la segunda IP: ";
    cin >> ultimoIp;
    escribirTxt(bruh,primerIp,ultimoIp,resultados);
    resultados.close();

    //cuantos ingenieros se necesitan para escribir length
    return 0;
}