#ifndef nodoData_H
#define nodoData_H
#include <string>
using namespace std;

class NodoData{
public:
    int key;
    string ipAddress;

    NodoData(int key, string ipAddress){
        this->key = key;
        this->ipAddress = ipAddress;
    }
    friend ostream& operator<<(ostream& os,const NodoData& ll){
        os << ll.ipAddress.substr(0,ll.ipAddress.size()-5);
    return os;
}
    NodoData(){};
};
#endif