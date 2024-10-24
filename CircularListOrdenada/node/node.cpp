#include ".\node.h"

//para uso dato tipo Persona

template<class T>
NodeC<T>:: NodeC(T data){
    this->data=data;
}

template<class T>
NodeC<T>:: NodeC(T data, NodeC<T>* next){
    this->data=data;
    this->next=next;
}

template<class T>
NodeC<T>::~NodeC(){
    next=nullptr;
}

template<class T>
T NodeC<T> :: getData(){
    return data;
}

template<class T>
void NodeC<T> :: setData(T data){
    this->data=data;
} 

template<class T>
NodeC<T>* NodeC<T> :: getNext(){
    return this->next;
}

template<class T>
void NodeC<T> :: setNext(NodeC<T>* next){
    this->next=next;
}

template<class T>
void NodeC<T> ::print(){    //al imprimir el dato generico se modifica
    cout<<"Dato: "<<endl;
    cout<<"Nombre: "<<data.getName()<<endl;
    cout<<"Apellido: "<<data.getLastName()<<endl;
    cout<<"Age: "<<data.getAge()<<endl;
    cout<<"ID: "<<data.getID()<<endl;
    cout<<"Next: "<<next<<endl;
}