/*
Alexis Gibrán Acosta Pánuco A01639818
Jorge Plasencia Ahm Jorgensen A01637493

Este Trabajo lo hice en conjunto con mi compañera Sofia del Pilar Batiz Martinez en las funciones setat, insertat y removeat por que se nos complico un poco el resto,
fue sacado del libro de texto y algunos videos que explicaban como insertar ya que el metodo insertlast del libro no funcionaba

Este Programa se encarga de manipular una lista apartir de punteros, cada funcion cumple un trabajo ya sea de insertar o remover un nodo,
asi como insertar en una posicion ya existente.
nota: el setAt lo interpretamos que el valor en esa posicion era remplazado por el nuevo en vez de agregar uno nuevo en esa posicion y se sume
*/
#include "MyLinkedList.h"
#include "Historial.h"
#include <iostream>
#include <limits>
using namespace std;

//Constructor
MyLinkedList::MyLinkedList()
{ //O(1)
    this->size = 0;
    this->first = this->last = nullptr;
}

//Destructor
MyLinkedList::~MyLinkedList()
{
}

int MyLinkedList::length()
{
    return this->size;
}

bool MyLinkedList::isEmpty()
{
    return this->size == 0;
    if (this->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//declara el objeto First
Historial MyLinkedList::First()
{
    return this->first->data;
}

//declara el objeto last
Historial MyLinkedList::Last()
{
    return this->last->data;
}

//Obtiene el valor en una posicion, complejidad O(n)
Historial MyLinkedList::getAt(int pos)
{
    if (pos >= 0 && pos < this->size)
    {
        MyNodeLL *current = this->first;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        return current->data;
    }
    else
    {
        throw invalid_argument("No se puede acceder a la posicion" + to_string(pos) + " en una lista de tamaño" + to_string(this->size));
    }
}

//sustituye un valor en una posicion, complejidad O(n)
void MyLinkedList::setAt(Historial data, int pos)
{
    if (pos >= 0 && pos < this->size)
    {
        MyNodeLL *tmp = this->first;
        MyNodeLL *elimina;
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        elimina = tmp->next;
        tmp->next = elimina->next;
        delete elimina;
        MyNodeLL *nuevo = new MyNodeLL(data, tmp->next);
        tmp->next = nuevo;
    }
    else
    {
        throw invalid_argument("No se puede acceder a la posicion" + to_string(pos) + " en una lista de tamaño" + to_string(this->size));
    }
}

//Funcion que inserta un nodo al principio, Complejidad O(1)
void MyLinkedList::insertFirst(Historial data)
{
    this->first = new MyNodeLL(data, this->first);
    if (this->size == 0)
    {
        this->last = this->first;
    }
    this->size++;
}

//Funcion que inserta un nodo al final, complejidad O(1)
void MyLinkedList::insertLast(Historial data)
{
    this->last->next = new MyNodeLL(data);
    if (this->size == 0)
    {
        this->last = this->first;
    }
    this->size++;
}

//Funcion que inserta en una posicion, complejidad O(log n)
void MyLinkedList::inserAt(Historial data, int pos)
{
    if (pos >= 0 && pos < this->size)
    {
        MyNodeLL *tmp = new MyNodeLL(data);
        MyNodeLL *next = new MyNodeLL(data);
        MyNodeLL *nuevo = new MyNodeLL(data);
        int tempos = 0;
        next = this->first;
        while (next->next != nullptr && tempos != pos)
        {
            tmp = next;
            next = next->next;
            tempos++;
        }
        if (pos == 0)
        {
            throw invalid_argument("Use la funcion de agregar al inicio");
        }
        else if (next->next != nullptr && pos == tempos + 1)
        {
            throw invalid_argument("Use la funcion de agregar al final");
        }
        else
        {
            tmp->next = nuevo;
            nuevo->next = next;
        }
    }
    else
    {
        throw invalid_argument("No se puede acceder a la posicion " + to_string(pos) + " en una lista de tamaño" + to_string(this->size));
    }
    this->size++;
}

//Funcion que remueve el primer nodo, complejidad O(n)
void MyLinkedList::removeFirst()
{
    if (this->size > 0)
    {
        MyNodeLL *tmp = this->first;
        this->first = this->first->next;
        delete tmp;
        if (this->size == 0)
        {
            this->last = nullptr;
        }
    }
    else
    {
        throw invalid_argument("No se puede borrar el primer elemento de una lista vacia");
    }
    this->size--;
}

//Funcion que remueve el nodo final, complejidad O(log n)
void MyLinkedList::removeLast()
{
    if (this->size > 0)
    {
        MyNodeLL *tmp = this->first;
        MyNodeLL *current;
        while (tmp->next->next != nullptr)
        { //segundo ultimo nodo
            tmp = tmp->next;
            current = tmp->next;
        }
        tmp->next = nullptr;
        delete (current);
        this->size--;
    }
    else
    {
        throw invalid_argument("No se puede acceder al último elemento");
    }
}

//Funcion que elimina un nodo en una posicion, complejidad O(n)
void MyLinkedList::removeAt(int pos)
{
    if (pos > 0 && pos < this->size)
    {
        MyNodeLL *tmp = this->first;
        MyNodeLL *elimina;
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        elimina = tmp->next;
        tmp->next = elimina->next;
        delete elimina;
    }
    else
    {
        throw invalid_argument("No se puede acceder a la posicion" + to_string(pos) + " en una lista de tamaño" + to_string(this->size));
    }
}

//INSERTAR SU MAIN AQUI:)
int main()
{
    /*
    MyLinkedList lista;
    lista.insertFirst(4);
    lista.insertFirst(2);
    lista.inserAt(3,1);
    lista.setAt(8,2);
    lista.insertLast(6);
    lista.removeFirst();
    lista.removeLast();
    cout<<lista;
    */
}