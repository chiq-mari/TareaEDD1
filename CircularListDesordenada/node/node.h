#include<iostream>
using namespace std;

template<class T>
class NodeC{
    private: 
        T data;
        NodeC<T>* next=nullptr;
    public: 
        NodeC(T); // constructor solo para incializar dato
        NodeC(T, NodeC<T>*);    // constructor solo para inicializar dato y next
        ~NodeC();
        T getData();        //retorno dato
        void setData(T);     //sets the data
        NodeC<T>* getNext();    //retorna next
        void setNext(NodeC<T>*); //sets pointer to next
        void print();            // prints node 
};


