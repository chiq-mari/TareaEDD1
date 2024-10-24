#include".\list.h"

template<class T>
listCDoubleDesord<T>:: listCDoubleDesord(NodeCDouble<T>* newNode){  //pasa ptr al que sera el 1er elemento
    this->head=newNode;     //it'll will head as well as tail
    this->tail=newNode;
    if(head!=nullptr){
        newNode->setNext(newNode);     //lo hace apuntar a si mismo en next y prev
        newNode->setPrev(newNode);
        length++;
    }
}

template<class T>
bool listCDoubleDesord<T>:: isEmpty(){
    return head==nullptr;   //vacia <=> head==nullptr
}

template<class T>
void listCDoubleDesord<T> :: print(){
    if(isEmpty()){
        cout<<"List is empty.\n";
        return;
    }
    NodeCDouble<T>* actual= head;
    int i=0;    // can be removed
    cout<<head<<endl;
    do{
        cout<<"Nodo "<<i<<": \n"; // can be removed
        actual->print();
        i++;    //can be removed
        actual=actual->getNext();
    }while(actual!=head);
    cout<<"Lenght: "<<length<<endl;
}

template<class T>
void listCDoubleDesord<T>:: insert(T data){ //inserta dato en la posicion que caiga, es decir de ultimo
    NodeCDouble<T>* newNode= new NodeCDouble<T>(data, nullptr, nullptr); //creates node with both ref's to null
    if(isEmpty()){
        newNode->setNext(newNode);  //make its ref's to itself
        newNode->setPrev(newNode);
        head=newNode;   // set it as both, head and tail
        tail=newNode;
    }
    else{
        newNode->setNext(head); //ref's of newNode
        newNode->setPrev(tail);
        head->setPrev(newNode);    //ref's of the prev and next
        tail->setNext(newNode);
        tail= newNode;  // set it as tail only
    }
    length++;
}

template<class T>
void listCDoubleDesord<T> :: removeFirst(){
    if(isEmpty()){  //Case 1: si la lista esta vacia
        return;
    }
    //case 2: si la lista tiene un solo elemento
    if(head==tail){
        delete head;    //all are null
        head=nullptr;
        tail=nullptr;
    }//Case 3: si la lista tiene mas de uno
    else{
        NodeCDouble<T>* temp=head;
        head=temp->getNext();
        tail->setNext(head);
        head->setPrev(tail);
        delete temp;
    }
    length--;
    return;
}

template<class T>
void listCDoubleDesord<T> :: removeLast(){
    if(isEmpty()){  //Case 1: si la lista esta vacia
        return;
    }
    //case 2: si la lista tiene un solo elemento
    if(head==tail){
        delete head;    //all are null
        head=nullptr;
        tail=nullptr;
    }//Case 3: si la lista tiene mas de uno
    else{
        NodeCDouble<T>* temp=tail;  //temp a tail
        tail=temp->getPrev();       //tail como su previo
        tail->setNext(head);        //rearrange links
        head->setPrev(tail);
        delete temp;
    }
    length--;
    return;
}

template<class T>
bool listCDoubleDesord<T> :: remove(T data){
    if(isEmpty()){  //case 1: list is empty
        return false;
    }
    if(data.isEqual(head->getData())){ //case 2: data is the one of head
        removeFirst();
        return true;
    }
    if(data.isEqual(tail->getData())){  //case 3: data is the one of tail
        removeLast();
        return true;
    }
    //case 4: data is between nodes
    NodeCDouble<T>* NodeToDelete=head;
    NodeCDouble<T>* last;
    NodeCDouble<T>* next;
    do{ //search
        NodeToDelete=NodeToDelete->getNext();
    }while(NodeToDelete!=head && data.isDifferent(NodeToDelete->getData()));

    if (NodeToDelete==head){
        return false;   //reached end of list
    }else{
        last=NodeToDelete->getPrev();   //obtiene nodos contiguos
        next=NodeToDelete->getNext();
        last->setNext(next);             //acomoda ref's
        next->setPrev(last);
    }
    length--;
    return true;
}

template<class T>
bool listCDoubleDesord<T>:: removeP(int n){
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
    NodeCDouble<T>* last=tail;
    NodeCDouble<T>* actual=head; // node in position to delete
    NodeCDouble<T>* next;
    //gets position in actual 
    for(int i=0; i<n; i++){
        last=actual;
        actual=actual->getNext();
    }
    next=actual->getNext();
    last->setNext(next);
    next->setPrev(last);
    delete actual;
    length--;
    return true;
}

template<class T>
bool listCDoubleDesord<T>:: update(int n, T data){  //remueve en posicion n+1 (n contando desde 0) y agrega data
    //case: Not possible
    if(n>=length){ // max indice= length-1
        return false;
    }
    //case Possible
    NodeCDouble<T>* actual=head; // node in position to delete
    //gets position in actual 
    for(int i=0; i<n; i++){
        actual=actual->getNext();
    }
    // cases--> //not needed to think if it's tail, head, or between nodes
    actual->setData(data);  
    return true;
    
}

template<class T>
void listCDoubleDesord<T>:: printReverse(){
    if(isEmpty()){
        cout<<"List is empty.\n";
        return;
    }
    NodeCDouble<T>* actual= tail;
    int i=length-1;    // can be removed
    cout<<tail<<endl;
    do{
        cout<<"Nodo "<<i<<": \n"; // can be removed
        actual->print();
        i--;    //can be removed
        actual=actual->getPrev();
    }while(actual!=tail);
    cout<<"Lenght: "<<length<<endl;
}