#include <string>
#include <vector>
#include "nodoData.h"
using namespace std;
#ifndef MYBST_H
#define MYBST_H
 

struct MyNodeBST{
    NodoData data;
    MyNodeBST *left,
              *right;
    MyNodeBST(NodoData data){
        this->data=data;
        this->left=this->right=nullptr;
    }
};
 

class MyBST{
    private:
        int size;
        MyNodeBST* root;
        bool search(MyNodeBST data,MyNodeBST* current); // Listo
        bool ancestors(MyNodeBST data, MyNodeBST* current, string &ancestorsString); // Listo
        void preorder(MyNodeBST* current); // Listo
        void inorder(MyNodeBST* current); // Listo
        void postorder(MyNodeBST* current); // Listo
        void level(MyNodeBST* current); // Listo
        MyNodeBST* insert(MyNodeBST* current, NodoData data); // Listo
        void inorderBack(MyNodeBST* current, int b);
        int height(MyNodeBST* root); // Listoe
        int whatLevelAmI(MyNodeBST* current, MyNodeBST data, int level); // Listo
        MyNodeBST* remove(MyNodeBST* current, MyNodeBST data, bool &trigger); // Listo
        MyNodeBST* minNode(MyNodeBST *current);// Listo
        //En caso de hacer alguno de los métodos recursivos y necesiten
        //otro método que haga la recursión deben de colocarlo como privado
        //sólo la función de preparación sería pública
    public:
        MyBST();
        void inorderBack(int b);
        int length(); // Listo
        bool isEmpty(); // Listo
        bool search(MyNodeBST data); // Listo
        bool insert(NodoData data);//true si lo inserto o no // Listo
        bool remove(MyNodeBST data);//si el valor estaba en el árbol lo borra // 
                              //y regresa true, caso contrario sólo regresa false
        //Estudiar borrado en BST
        //Estudiar AVL
        void preorder(); // Listo
        void inorder(); // Listo
        void postorder(); // Listo
        void level(); // Listo
        void visit(int type);//Type: 1->preorder,2->inorder.3->postorder,4->level // Listo
        int height();//regresa la altura del BST. // Listo
        void ancestors(MyNodeBST data);//imprime los ancestros del valor pasado. // Listo
                                 //el orden de impresión debe ser de la raíz
                                 //hacía abajo.
                                //Si valor no se localiza en el árbol no imprime nada
        int whatLevelAmI(MyNodeBST data);//regresa el nivel en que se encuentra el valor / //Listo
                                   //dentro del árbol. Si el valor no está en árbol imprime -1
};
#endif