#include <string>
#include <vector>
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
        bool search(NodoData data,MyNodeBST* current); // Listo
        bool ancestors(NodoData data, MyNodeBST* current, string &ancestorsString); // Listo
        void preorder(MyNodeBST* current); // Listo
        void inorder(MyNodeBST* current); // Listo
        void postorder(MyNodeBST* current); // Listo
        void level(MyNodeBST* current); // Listo
        MyNodeBST* insert(MyNodeBST* current, NodoData data); // Listo
        int height(MyNodeBST* root); // Listo
        int whatLevelAmI(MyNodeBST* current, NodoData data, int level); // Listo
        MyNodeBST* remove(MyNodeBST* current, NodoData data, bool &trigger); // Listo
        MyNodeBST* minNode(MyNodeBST *current);// Listo
        //En caso de hacer alguno de los métodos recursivos y necesiten
        //otro método que haga la recursión deben de colocarlo como privado
        //sólo la función de preparación sería pública
    public:
        MyBST();
        int length(); // Listo
        bool isEmpty(); // Listo
        bool search(NodoData data); // Listo
        bool insert(NodoData data);//true si lo inserto o no // Listo
        bool remove(NodoData data);//si el valor estaba en el árbol lo borra // 
                              //y regresa true, caso contrario sólo regresa false
        //Estudiar borrado en BST
        //Estudiar AVL
        void preorder(); // Listo
        void inorder(); // Listo
        void postorder(); // Listo
        void level(); // Listo
        void visit(int type);//Type: 1->preorder,2->inorder.3->postorder,4->level // Listo
        int height();//regresa la altura del BST. // Listo
        void ancestors(NodoData data);//imprime los ancestros del valor pasado. // Listo
                                 //el orden de impresión debe ser de la raíz
                                 //hacía abajo.
                                //Si valor no se localiza en el árbol no imprime nada
        int whatLevelAmI(NodoData data);//regresa el nivel en que se encuentra el valor / //Listo
                                   //dentro del árbol. Si el valor no está en árbol imprime -1
};
#endif