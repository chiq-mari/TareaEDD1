#include ".\node.h"

//para uso dato tipo Person

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
    cout<<"Nombre: "<<data->name<<endl;
    cout<<"Apellido: "<<data->lastName<<endl;
    cout<<"Age: "<<data->age<<endl;
    cout<<"ID: "<<data->id<<endl;
    cout<<"Next: "<<next<<endl;
}