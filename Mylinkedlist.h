#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
using namespace std;

struct MyNodeLL{
    int data;
    MyNodeLL* next;

    MyNodeLL(int data,MyNodeLL* next){
        this->data = data;
        this->next = next;
    }
    MyNodeLL(int data):MyNodeLL(data,nullptr){}
};

class Mylinkedlist{
private:
    MyNodeLL* first;
    MyNodeLL* last;
    int size;
public:
    Mylinkedlist();
    ~Mylinkedlist();
    int length();
    bool isEmpty();
    int First();
    int Last();
    int getAt(int pos);
    void setAt(int data, int pos);
    void insertFirst(int data);
    void insertLast(int data);
    void inserAt(int data, int pos);//pos:[0,size] Exc invalidad_argument
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    friend ostream& operator<<(ostream& os,const Mylinkedlist& ll){
        MyNodeLL* current = ll.first;
        for(int i = 0; i <= ll.size;i++){
            os<<current->data<<",";
            current=current->next;
        }
        return os;
    }
};
#endif