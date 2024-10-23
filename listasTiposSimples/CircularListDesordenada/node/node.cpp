#include ".\node.h"

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
void NodeC<T> ::print(){
    cout<<"Dato: "<<data<<endl;
    cout<<"Next: "<<next<<endl;
}