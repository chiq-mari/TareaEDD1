#include".\list.h"

template<class T>
listC<T>::listC(){
    head=nullptr;
    tail=nullptr;
    length=0;
}

template<class T>
bool listC<T> ::isEmpty(){
    return head==nullptr;
}
template<class T>
void listC<T>:: insertFirst(T data){
    NodeC<T>* newNode= new NodeC<T>(data, nullptr);
    if(isEmpty()){ //insercion de primero si la lista esta vacia
        head=newNode;
        tail=newNode;
        head->setNext(tail);    //hace que el siguiente de head sea tail y viceversa
    }
    else{       //insercion de primero si la lista no esta vacia
        newNode->setNext(head);
        tail->setNext(newNode);
        head=newNode;
    }
    length++;
}
template<class T>
void listC<T> :: insertLast(T data){
    NodeC<T>* newNode= new NodeC<T>(data, nullptr);
    if(isEmpty()){  //insercion de ultimo si la lista esta vacia
        head=newNode;
        tail=newNode;
        head->setNext(tail);    //hace que el siguiente de head sea tail y viceversa
    }
    else{           //insercion de ultimo si la lista no esta vacia
        newNode->setNext(head);
        tail->setNext(newNode);
        tail=newNode;
    }
    length++;
}

template<class T>
void listC<T> :: insert(T data){

    NodeC<T>* newNode= new NodeC<T>(data, nullptr); // crea el dato apuntando a null

    if(isEmpty() || data < head->getData()){ // de estar vacio o si el dato  a insertar es menor que el de head
        insertFirst(data);                   //insertFirst
        return;
    }

    if(data > tail->getData()){ //si el dato insertar es mayor que la cola 
        insertLast(data);       //insertLast
        return;
    }

    NodeC<T>* actual=head;   //crea nodos de busqueda
    NodeC<T>* prev=tail;

    do{     // busqueda: mientras actual sea menor que data(salta el primer caso)
        prev=actual;
        actual=actual->getNext();
    }while(actual->getData() <data);

    prev->setNext(newNode); //rearrange links
    newNode->setNext(actual);
    length++;
}

template <class T>
void listC<T>:: print(){

    if(isEmpty()){
        return;
    }
    NodeC<T>* actual=head;
    cout<<head<<endl;
    do{
        actual->print();
        actual=actual->getNext();
    }while(actual!=head);
    cout<<"length: "<<length<<endl;
}

template<class T>
bool listC<T> :: remove(T data){

}

