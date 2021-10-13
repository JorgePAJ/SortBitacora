#include "MyLinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Historial.h"
#include <iostream>
#include <algorithm>
#include <conio.h>
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
      cout << "fin:\t" << fin <<endl;
      cout << "centro:\t" << centro << endl;
      cout << "j:\t" << j << endl;
      cout << "k:\t" << k << endl;
      if(j <= centro && k <=fin){
        cout << "ll size: " << ll.length() << endl;
        
        cout << "J " << j << endl;
        cout << ll.getAt(j).ipNumber << endl;
        cout << "K " << k << endl;
        cout << ll.getAt(k).ipNumber << endl;

          if( ll.getAt(j).cuadrante1 < ll.getAt(k).cuadrante1){ 
            datostmp[i] = ll.getAt(j++);
            // ll.setAt(ll.getAt(j++), i);
            //new_list.insertLast(ll.getAt(j++));
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
              // datostmp[i] =  separador.setAt(data,k++);
            //new_list.insertLast(ll.getAt(k++));
              // ll.setAt(ll.getAt(k++), i);

          }
      }
      else if(j<=centro){
          //datostmp[i] =  separador.setAt(data,j++);
        datostmp[i] = ll.getAt(j++);
          // ll.setAt(ll.getAt(j++), i);

          
      }else{
          //datostmp[i] =  separador.setAt(data,j++);
        datostmp[i] = ll.getAt(k++);
        //new_list.insertLast(ll.getAt(k++));
          
      }
  }
  for (int m = 0; m < size; m++){
  
    ll.setAt(datostmp[m], m+ini);
    // ll.setAt(ll.getAt(m), m+ini);
      // separador.setAt(data,(m+ini))= datostmp[m];
    
  }


  // MyNodeLL *current = new_list.firstNode();

  // while (current->next != nullptr){
  //   cout << current->data.ipAddress << endl;
  //   current = current->next;
  // } 
  // ll = new_list;
}

void Ordenamerge(int ini,int fin, MyLinkedList &ll){
    if(ini<fin){
        cout <<"fin at ordena:\t"<< fin << endl;
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
                         /* 
                                if (!isalnum(ipPointless[i]) || ipPointless[i] == ' '){
                                ipPointless.erase(i,1);
                                len--;
                                break;

                        if(ipPointless.length()==14){    
                        ipPointless1 = ipPointless.substr(0,3);
                        ipPointless2 = ipPointless.substr(3,2);
                        ipPointless3 = ipPointless.substr(5,3);
                        ipPointless4 = ipPointless.substr(8,2);
                        ipPointless5 = ipPointless.substr(10,4);
                        }else
                              i++;
                                }                        
                        }  */
                    // ipPointless.erase(remove_if(ipPointless.begin(), ipPointless.end(), [](char c) { return !isalpha(c); } ), ipPointless.end());
                    // ipPointless.erase(std::remove_if(ipPointless.begin(), ipPointless.end(), (int(*)(int))isalpha), ipPointless.end());
                    // ipPointless.erase(remove(ipPointless.begin(), ipPointless.end(), '.'), ipPointless.end());
                    // ipPointless.erase(remove(ipPointless.begin(), ipPointless.end(), ':'), ipPointless.end());                  
                    // ipNumber = stol(ipPointless);
                    cuadrante1 = stol(ipPointless1);
                    cuadrante2 = stol(ipPointless2);
                    cuadrante3 = stol(ipPointless3);
                    cuadrante4 = stol(ipPointless4);
                    cuadrante5 = stol(ipPointless5);                                                                                
                    break;
                }
            }
            cout<< ipPointless.length()<<endl;
            cout<<"IP: " <<ipPointless1<<endl;
            cout<<"IP: " <<ipPointless2<<endl;
            cout<<"IP: " <<ipPointless3<<endl;
            cout<<"IP: " <<ipPointless4<<endl;
            cout<<"IP: " <<ipPointless5<<endl;
            // Sin delimitador
            getline(buff, temp);
            error = temp;

            Historial data(mes, dia, hora, ipAddress, error, ipNumber,cuadrante1,cuadrante2,cuadrante3,cuadrante4,cuadrante5);    
            new_list.insertLast(data);
            // new_list.insertFirst(data);
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
    cout << "Hora:\t"  << bruh.First().hora << endl;
    cout << "IP:\t"    << bruh.First().ipAddress << endl;
    cout << "Error:\t" << bruh.First().error << endl;

    cout << endl << "LAST:" << endl;
    cout << "Dia:\t"   << bruh.Last().dia << endl;
    cout << "Mes:\t"   << bruh.Last().mes << endl;
    cout << "IP:\t"    << bruh.Last().ipAddress << endl;
    cout << "Error:\t" << bruh.Last().error << endl;

    cout << endl << "bruh 3" << endl;

    ordenaMerge(bruh);

    cout << endl << "FIRST:" << endl;
    cout << "Dia:\t"   << bruh.First().dia << endl;
    cout << "Mes:\t"   << bruh.First().mes << endl;
    cout << "Hora:\t"  << bruh.First().hora << endl;
    cout << "IP:\t"    << bruh.First().ipAddress << endl;
    cout << "Error:\t" << bruh.First().error << endl;

    cout << endl << "LAST:" << endl;
    cout << "Dia:\t"   << bruh.Last().dia << endl;
    cout << "Mes:\t"   << bruh.Last().mes << endl;
    cout << "IP:\t"    << bruh.Last().ipAddress << endl;
    cout << "Error:\t" << bruh.Last().error << endl;

    cout << endl << "bruh 4" << endl;

    MyNodeLL *current = bruh.firstNode();

    cout << "Size:\t" << bruh.length()<<endl;
    while (current != nullptr){
      cout << current->data.error << endl;
      current = current->next;
    } 



    //cuantos ingenieros se necesitan para escribir length
    return 0;
}