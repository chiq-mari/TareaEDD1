#include".\list.h"

template<class T>
listCDesord<T>::listCDesord(){  //modif
    head=nullptr;
    tail=nullptr;
    length=0;
}

template<class T>
bool listCDesord<T> ::isEmpty(){        //checked
    return head==nullptr;
}

template<class T> //modif
void listCDesord<T>:: insert(T data){      //inserta dato en la posicion que caiga, es decir de ultimo
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

template <class T>
void listCDesord<T>:: print(){  //checked

    if(isEmpty()){
        return;
    }
    NodeC<T>* actual=head;
    cout<<head<<endl;
    do{
        actual->print();
        cout<<endl;
        actual=actual->getNext();
    }while(actual!=head);
    cout<<"length: "<<length<<endl;
}

template<class T>
void listCDesord<T> :: removeFirst(){
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
void listCDesord<T> :: removeLast(){
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
bool listCDesord<T> :: remove(T data){
    //if list is empty
    if(isEmpty()){
        return false;
    }

    //list isn't empty
    if( data.isEqual(head->getData())){    // Case1: if data= head->data
        removeFirst();
        return true;
    }
    if(data.isEqual(tail->getData())){     //Case 2: if data= tail->data
        removeLast();
        return true;
    }
    //case 3: between nodes --->search
    NodeC<T>* prev=tail;
    NodeC<T>* NodeToDelete=head;  //works as actual
    do{
        prev=NodeToDelete;
        NodeToDelete=NodeToDelete->getNext();
    }while(data.isDifferent(NodeToDelete->getData()) && NodeToDelete!=head);

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
bool listCDesord<T>:: removeP(int n){
    //case: Not possible
    if(n>=length){ // max indice= length-1
        return false;
    }
    //case Possible
    //1. just one element
    if(length==1 || n==0){
        removeFirst();
        return true;
    }
    //2. two or more elements
    NodeC<T>* last=tail;
    NodeC<T>* actual=head; // node in position to delete
    //gets position in actual 
    for(int i=0; i<n; i++){
        last=actual;
        actual=actual->getNext();
    }
    last->setNext(actual->getNext());
    delete actual;
    length--;
    return true;

}

template<class T>
bool listCDesord<T>:: update(int n, T data){  //remueve en posicion n+1 (n contando desde 0) y agrega data
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
    // cases--> //not needed to think if it's tail, head, or between nodes
    actual->setData(data);  
    return true;
}