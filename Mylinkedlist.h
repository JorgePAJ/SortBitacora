#ifndef MyLinkedList_H
#define MyLinkedList_H
#include <iostream>
#include "Historial.h"
using namespace std;

struct MyNodeLL
{
    Historial data;
    MyNodeLL *next;

    MyNodeLL(Historial data, MyNodeLL *next)
    {
        this->data = data;
        this->next = next;
    }
    MyNodeLL(Historial data) : MyNodeLL(data, nullptr) {}
};

class MyLinkedList
{
private:
    MyNodeLL *first;
    MyNodeLL *last;
    int size;

public:
    MyLinkedList();
    ~MyLinkedList();
    int length();
    bool isEmpty();
    Historial First();
    Historial Last();
    Historial getAt(int pos);
    void setAt(Historial data, int pos);
    void insertFirst(Historial data);
    void insertLast(Historial data);
    void inserAt(Historial data, int pos); //pos:[0,size] Exc invalidad_argument
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    /*friend ostream& operator<<(ostream& os,const MyLinkedList& ll){
        MyNodeLL* current = ll.first;
        for(int i = 0; i <= ll.size;i++){
            os<<current->data<<",";
            current=current->next;
        }
        return os;
    }
};
*/
#endif