#include "MyLinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Historial.h"
#include <iostream>
using namespace std;


void mezcla(int ini, int fin, MyLinkedList &ll){
    cout << "entra a mezcla" << endl;
    Historial data;
    MyLinkedList new_list = MyLinkedList(); 
    int centro = (ini+fin)/2;
    int j = ini,
        k = centro +1,
        size = (fin - ini + 1);
    cout << "bruh 4.9" << endl;
    int datostmp[fin-1+1];
    
    for(int i = 0; i < size;i++){
        cout << "fooor" <<endl;
        if(j <= centro && k <=fin){
          cout<<"iiiiiiff" << endl;
            if( ll.getAt(j).ipAddress < ll.getAt(k).ipAddress){
                //datostmp[i] =  separador.setAt(data,j++);
              cout << "entra if" << endl;
              new_list.insertLast(ll.getAt(j++));
              cout << "sale if" << endl;
            }else{
               // datostmp[i] =  separador.setAt(data,k++);
               cout << "entra else" << endl;
               new_list.insertLast(ll.getAt(k++));
               cout << "sale else" << endl;
               

            }
        }
        else if(j<=centro){
            //datostmp[i] =  separador.setAt(data,j++);
            cout << "entra elseif" << endl;
            new_list.insertLast(ll.getAt(j++));
            cout << "sale elseif" << endl;
        }else{
            //datostmp[i] =  separador.setAt(data,j++);
            cout << "entra else2" << endl;
            new_list.insertLast(ll.getAt(j++));
            cout << "sale else2" << endl;
        }
    }
    for (int m = 0; m < size; m++){
      cout << "entra for" << endl;
      new_list.setAt(ll.getAt(m), m+ini);
      cout << "sale for" << endl;
        // separador.setAt(data,(m+ini))= datostmp[m];
      
    }
  cout << "bruh 5" << endl;

  MyNodeLL *current = new_list.firstNode();
  cout << "bruh 6" << endl;
  while (current->next != nullptr){
    cout << current->data.ipAddress << endl;
    current = current->next;
  } 
  ll = new_list;
}

void Ordenamerge(int ini,int fin,MyLinkedList &ll){//O(2log(n))
    if(ini<fin){
        cout << "entra a if de ordenamerge2" << endl;
        int centro = (ini+fin)/2;
        Ordenamerge(ini,centro,ll);
        Ordenamerge(centro+1,fin,ll);
        mezcla(ini,fin,ll);
    }
    cout << "no entro al if de ordenamerge 2" << endl;
}


void ordenaMerge(MyLinkedList &ll){ //O(n)
    cout << "entra a ordena merge 1" << endl;
    MyLinkedList fin;
    Ordenamerge(0,ll.length(),ll);
    return;

}

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

    ordenaMerge(bruh);

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

    cout << endl << "bruh 4" << endl;

    //cuantos ingenieros se necesitan para escribir length
    return 0;
}