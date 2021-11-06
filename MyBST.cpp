/*Jorge Plasencia Ahm Jorgensen Ahm Jorgensen
    Implementacion de un arbol BST
*/
#include "MyBST.h"
#include <iostream>
#include <vector>
#include <queue>
#include "nodoData.h"
using namespace std;

int n_vals = 0;

// Constructord de el arbol
MyBST::MyBST(){
    this->size = 0;
    this->root = nullptr;
}

int MyBST::length(){
    return this->size;
}

//Complejidad O(n)
MyNodeBST*MyBST::minNode(MyNodeBST *current){
    while (current && current->left != nullptr){
        current = current->left;
    }
    return current;
}

bool MyBST::isEmpty(){
    return this->size == 0;
}

bool MyBST::search(MyNodeBST data){
    MyNodeBST *temp = this->root;
    while (temp != nullptr){
        if (temp->data.key == data.data.key){
            return true; //el dato si esta en el arbol
        }
        else if (temp->data.key > data.data.key){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

// Complejidad O(N)
//Elimina un nodo del arbol.
MyNodeBST* MyBST::remove(MyNodeBST* current, MyNodeBST data, bool &trigger){
    if (current == nullptr) {
        trigger= false;
        return current;
    }
    if (data.data.key < current->data.key) {
        current->left = remove(current->left, data, trigger);
    } else if (data.data.key > current->data.key) {
        current->right = remove(current->right, data, trigger);
    } else {
        if (current->left == nullptr) {
            MyNodeBST *temp = current->right;
            delete current;
            trigger = true;
            return temp;
        } else if (current->right == nullptr) {
            MyNodeBST *temp = current->left;
            delete current;
            trigger = true;
            return temp;
        }
        MyNodeBST *temp = minNode(current->right);
        current -> data = temp -> data;
        root -> right = remove(current->right,temp->data, trigger);
    }
    return current;
}
//Funcion de preparacion para remover nodos
bool MyBST::remove(MyNodeBST data){
    bool trigger = false;
    MyNodeBST* root = remove(this->root, data, trigger);
    if (root != nullptr){
        return true;
    }else{
        return false;
    }
}
 
 //Complejidad O(N)
 //Funcion que regresa el nivel donde el nodo esta localizado
int MyBST::whatLevelAmI(MyNodeBST* current, MyNodeBST data, int level)
{
    if (current == nullptr)
        return 0;
 
    if (current->data.key == data.data.key)
        return level;
 
    int levelInf = whatLevelAmI(current->left, data, level + 1);
    if (levelInf != 0)
        return levelInf;
 
    levelInf = whatLevelAmI(current->right, data, level + 1);
    return levelInf;
}
//Funcion de preparacion para conseguir el nivel
int MyBST::whatLevelAmI(MyNodeBST data)
{
    return whatLevelAmI(this->root, data, 0);
}

// Complejidad O(n)
// Funcion para insertar un nodo.
MyNodeBST* MyBST::insert(MyNodeBST *current, NodoData data){
    if (!current)
    {
        // Insert the first node, if root is NULL.

        return new MyNodeBST(data);
    }
 
    // Insert data.
    if (data.key > current->data.key)
    {
        
        
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        current->right = insert(current->right, data);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        current->left = insert(current->left, data);
    }
 
    // Return 'root' node, after insertion.
    return current;
}
//Funcion de preparacion para insertar la informacion,  solo pide la data
bool MyBST::insert(NodoData data){
    if (this->root == nullptr){
        this->root = new MyNodeBST(data);
        this->size++;
        return true;
    }
    else{
        MyNodeBST *nvo = insert(this->root, data);
        if (nvo != nullptr){
            this->size++;
            return true;
        }
        else{
            return false;
        }
    }

}
//Complejidad O(N)
//Esta funcion nos regresa la altura del arbol
int MyBST::height(MyNodeBST* root){
    if (root != nullptr){
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);
            if (leftHeight > rightHeight){
                return(leftHeight + 1);
            }else{
                return(rightHeight + 1);}
        }
    else{
        return 0;
        }
}
//Funcion de preparacion para conseguir la altura
int MyBST::height(){
    int altura = height(this->root);
    return altura;
}

// Complejidad O(n)
//Esta funcion imprime todos los ancestros de un nodo dado.
bool MyBST::ancestors(MyNodeBST data, MyNodeBST *current, string &ancestorsString){
    if (current == nullptr) {
            return false;
        }
        if (current->data.key == data.data.key) {
            return true;
        }
        if (ancestors(data, current->left, ancestorsString) || ancestors(data, current->right, ancestorsString)) {
            ancestorsString.insert(0, to_string(current->data.key) + ",");
            return true;
        } else {
            return false;
        }
}
//Funcion de preparacion para los ancestros
void MyBST::ancestors(MyNodeBST data){
    string ancestorsString;
    ancestors(data, this->root, ancestorsString);
    cout << ancestorsString << endl;
}
//Funcion para elegir el recorrido que quieres hacer,Type: 1->preorder,2->inorder.3->postorder,4->level
void MyBST::visit(int option){
    switch (option){
    case 1:
        preorder();
        break;
    case 2:
        inorder();
        break;
    case 3:
        postorder();
        break;
    case 4:
        level();
        break;
    case 5:
        inorderBack(5);
        break;
    }
}

// Complejidad O(n)
void MyBST::preorder(MyNodeBST* current){
    if (current != nullptr) {
    cout << current -> data.ipAddress << " Se repite :"<< current->data.key<<" veces"<<",\n";
        preorder(current -> left);
        preorder(current -> right);
    }
}
void MyBST::preorder(){
    preorder(this -> root);
    cout << endl;
}

// Complejidad O(n)
void MyBST::inorder(MyNodeBST* current){
    if (current != nullptr) {

        inorder(current -> left);
        cout << current -> data.ipAddress << " Se repite :"<< current->data.key<<" veces"<<",\n";
        inorder(current -> right);
    }
}
void MyBST::inorder(){
    inorder(this -> root);
    cout << endl;
}
//inverso
void MyBST::inorderBack(MyNodeBST* current,int b){
    if (current == nullptr) return;
    inorderBack(current -> right, b);
    if(n_vals++<b){
        cout << current -> data.ipAddress << " Se repite :"<< current->data.key<<" veces"<<"\n";
    }
    
    inorderBack(current -> left, b);
}
void MyBST::inorderBack(int b){
    n_vals = 0;
    inorderBack(this -> root, b);
    cout << endl;
}

// Complejidad O(n)
void MyBST::postorder(MyNodeBST* current){
    if (current != nullptr) {
        postorder(current -> left);
        postorder(current -> right);
        cout << current -> data.ipAddress << " Se repite :"<< current->data.key<<" veces"<<",\n";
    }
}
void MyBST::postorder(){
    postorder(this -> root);
    cout << endl;
}

// Complejidad O(n)
void MyBST::level(MyNodeBST* current){
    // Base Case
    if (current == nullptr)
        return;
 
    // Create an empty queue for level order traversal
    queue<MyNodeBST*> cola;
 
    // Enqueue Root and initialize height
    cola.push(current);
    while (cola.empty() == false) {
        // Print front of queue and remove it from queue
        MyNodeBST* nodo = cola.front();
        cout << nodo -> data.ipAddress << " Se repite :"<< nodo->data.key<<" veces"<<"\n";
        cola.pop();
 
        /* Enqueue left child */
        if (nodo->left != nullptr)
            cola.push(nodo->left);
 
        /*Enqueue right child */
        if (nodo->right != nullptr)
            cola.push(nodo->right);
    }
}
void MyBST::level(){
    level(this->root);
}

//Aqui poner el main :)