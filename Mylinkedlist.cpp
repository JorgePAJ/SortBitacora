#include "Mylinkedlist.h"
#include <iostream>
#include <limits>
using namespace std;

Mylinkedlist::Mylinkedlist(){
    this->size = 0;
    this->first = this->last = nullptr;
}
Mylinkedlist::~Mylinkedlist(){
    
}
int Mylinkedlist::First(){
    return this->first->data;
}

int Mylinkedlist::Last(){
    return this->last->data;
}

int Mylinkedlist::length(){
    return this->size;
}
/*
void Mylinkedlist::insertfirst(int data){
    MyNodeLL* nuevo = new MyNodeLL(data,this->first);
    this->first = nuevo;
    this->size++;
}
*/

void Mylinkedlist::insertfirst(int data){
    this->first = new MyNodeLL(data,this->first);
    if(this->size == 0){
        this->last = this->first;
    }
    this->size++;    
}

void Mylinkedlist::insertlast(int data){
    this->last = new MyNodeLL(data,this->last);
    if( last = nullptr){
        this->last = this->last;
    }
    this->size++;
}

void Mylinkedlist::insertat(int data, int pos){
    
}

bool Mylinkedlist::isEmpty(){
    return this->size == 0;
}

int Mylinkedlist::getat(int pos){
        if(pos>= 0 && pos<this->size){
            MyNodeLL* current = this->first;
            for(int i =0;i<pos;i++){
                current=current->next;
        }
        return current->data;
    }else{
        throw invalid_argument("No se puede acceder a la posicion" +to_string(pos)+" en una lista de tamaño"+to_string(this->size));
    }
}
void Mylinkedlist::removeFirst(){
    if(this->size > 0){
    MyNodeLL* tmp = this->first;
    this->first = this->first->next;
    delete tmp;
    this->size--;
    if(this->size == 0){
        this->last=nullptr;
    }
    }else{
        throw invalid_argument("No se puede borrar el primer elemento de una lista vacia");
    }
}
int main(){
    try{
    Mylinkedlist lista;
    lista.insertfirst(8);
    lista.insertfirst(7);
    lista.insertfirst(10);
    lista.insertfirst(24);
    lista.insertlast(4);
    for(int i = 0;i<lista.length();i++){
        cout<<lista.getat(i)<<",";
    }
    cout<<endl;
    cout<<lista<<endl;
    cout<<lista.getat(5)<<endl;
}catch(invalid_argument& ex){
    cout<<"Error: "<<ex.what()<<endl;
}
    return 0;
}