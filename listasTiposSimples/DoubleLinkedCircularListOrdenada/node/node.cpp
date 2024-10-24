#include".\node.h"

template<class T>
NodeCDouble<T>:: NodeCDouble (T data, NodeCDouble<T>* next, NodeCDouble<T>* prev){
    this->data=data;
    this->next=next;
    this->prev=prev;
}

template<class T>
NodeCDouble<T>:: ~NodeCDouble(){
    this->next=nullptr;
    this->prev=nullptr;
}    
// data---------------------------
template<class T>
T NodeCDouble<T>:: getData(){
    return this->data;
}

template<class T>
void NodeCDouble<T>:: setData(T data){
    this->data= data;
}
// next---------------------------
template<class T>
NodeCDouble<T>* NodeCDouble<T>:: getNext(){
    return this->next;
}

template<class T>
void NodeCDouble<T>:: setNext(NodeCDouble<T>* next){
    this->next=next;
}
// Prev---------------------------
template<class T>
NodeCDouble<T>* NodeCDouble<T>:: getPrev(){
    return this->prev;
}

template<class T>
void NodeCDouble<T>:: setPrev(NodeCDouble<T>* prev){
    this->prev=prev;
}

template<class T>
void NodeCDouble<T> :: print(){
    cout<<"Data: "<<data<<endl;
    cout<<"Direccion del siguiente: "<<next<<endl;
    cout<<"Direccion del anterior: "<<prev<<endl;
}