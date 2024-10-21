#include".\list.h"

//Implementacion para uso dato tipo Person

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
void listC<T> :: removeFirst(){
    if(isEmpty()){  //si esta vacia-->  retornar
        return;
    }
    //no vacia--> just one element
    if(head->getNext()==head){ //head pointing to itself
        delete head;    //libera la unica memoria en uso
        head = nullptr;
        tail=nullptr;
        length=0;
        return;
    }

    //no vacia--> more than 1 element
    NodeC<T>* temp=head;
    tail->setNext(head->getNext()); // link tail-new head
    head=head->getNext(); //pointer to head
    delete temp;
    length--;
}

template<class T>
void listC<T> :: removeLast(){
    //si la lista esta vacia
    if(isEmpty()){
        return;
    }
    //if list isn't empty, but there is just one element
    if(head->getNext()==head){
        delete head;
        head=nullptr;
        tail=nullptr;
        length=0;
        return;
    }
    //no vacia --> more than one element
    // search for the second last Node
    NodeC<T>* temp=head; 
    while(temp->getNext()!= tail){
        temp=temp->getNext();
    }
    temp->setNext(head); //once found, set its next to head
    delete tail;        //delete tail
    tail=temp;          // update the new tail
    length--;
}

template<class T>
bool listC<T> :: remove(T data){
    //if list is empty
    if(isEmpty()){
        return false;
    }

    //list isn't empty
    if( data== head->getData()){    // Case1: if data= head->data
        removeFirst();
        return true;
    }
    if(data== tail->getData()){     //Case 2: if data= tail->data
        removeLast();
        return true;
    }
    //case 3: between nodes --->search
    NodeC<T>* prev=tail;
    NodeC<T>* NodeToDelete=head;  //works as actual
    do{
        prev=NodeToDelete;
        NodeToDelete=NodeToDelete->getNext();
    }while(NodeToDelete->getData()!=data && NodeToDelete!=head);

    //reached end of list without finding the data
    if(NodeToDelete==head){
        return false;
    }

    //data was found
    prev->setNext(NodeToDelete->getNext());
    delete NodeToDelete;
    length--;
    return true;
}

template<class T>
bool listC<T>:: update(int n, T data){  //remueve en posicion n+1 (n contando desde 0) y agrega data
    //case: Not possible
    if(n>=length){ // max indice= length-1
        return false;
    }
    //case Possible
    NodeC<T>* last=tail;
    NodeC<T>* actual=head; // node in position to delete
    //gets position in actual 
    for(int i=0; i<n; i++){
        last=actual;
        actual=actual->getNext();
    }
    // cases--> data matches their place

    // Possible 1. at head (actual)
    if(actual==head){
        if(data<=actual->getNext()->getData()){ //it preserves posistion if the new data smaller or equal than the data next to head
            actual->setData(data);
        }
        else{  
            removeFirst();
            insert(data);
        }
        return true;
    }   
    // Possible 2. at tail
    if(actual==tail){
        if(data>=last->getData()){  //preserves space in memory if the prev data is smaller or equal than the new Data
            actual->setData(data);  //just change the data
        }else{
            removeLast();       //otherwise, removeLast & insert
            insert(data);
        }
        return true;
    }
    //Possible 3. Between nodes
    if(data<=last->getData() && data>=actual->getNext()->getData()){    //preserves space in memory
        actual->setData(data);  
    }else{
        remove(actual->getData());
        insert(data);
    }
    return true;
}

