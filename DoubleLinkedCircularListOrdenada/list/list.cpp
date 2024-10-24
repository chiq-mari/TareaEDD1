#include".\list.h"

template<class T>
listCDouble<T>:: listCDouble(NodeCDouble<T>* newNode){  //pasa ptr al que sera el 1er elemento
    this->head=newNode;     //it'll will head as well as tail
    this->tail=newNode;
    if(head!=nullptr){
        newNode->setNext(newNode);     //lo hace apuntar a si mismo en next y prev
        newNode->setPrev(newNode);
        length++;
    }
}

template<class T>
bool listCDouble<T>:: isEmpty(){
    return head==nullptr;   //vacia <=> head==nullptr
}

template<class T>
void listCDouble<T> :: print(){
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
void listCDouble<T>:: insertFirst(T data){
    NodeCDouble<T>* newNode= new NodeCDouble<T>(data, nullptr, nullptr); //creates node with both ref's to null
    if(isEmpty()){  //if it's the very first one to be added
        newNode->setNext(newNode);  //make its ref's to itself
        newNode->setPrev(newNode);
        head=newNode;   // set it as both, head and tail
        tail=newNode;
    }
    else{   //not the very first one to be added
        newNode->setNext(head); //ref's of newNode
        newNode->setPrev(tail);
        head->setPrev(newNode); //ref's of the prev and next
        tail->setNext(newNode);
        head=newNode;   // set it as head only
    }
    length++;
}

template<class T>
void listCDouble<T>:: insertLast(T data){
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
void listCDouble<T>::insert(T data){
    //Case: Insert first<=> if list is Empty or newData smaller or equal than the one of head
    if (isEmpty() || data.getAge()<head->getData().getAge()){
        insertFirst(data);
        return;
    }
    //Case: InsertLast <=> if list newData is greater than the one of tail
    if(data.getAge()>tail->getData().getAge()){
        insertLast(data);
        return;
    }
    //Case: Insert between nodes
    NodeCDouble<T>* newNode= new NodeCDouble<T>(data, nullptr, nullptr); //creates node with both ref's to null
    NodeCDouble<T>* actual=head; // newNode will take the position of actual
    NodeCDouble<T>* last;
    //search
    do{
        actual=actual->getNext();
    }while(data.getAge()>actual->getData().getAge());
    last=actual->getPrev(); //adds the one before the node to insert
    //insertion
    newNode->setNext(actual);   //ref's of newNode
    newNode->setPrev(last);
    last->setNext(newNode);     //ref's of the prev and next
    actual->setPrev(newNode);
    length++;
}

template<class T>
void listCDouble<T> :: removeFirst(){
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
void listCDouble<T> :: removeLast(){
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
bool listCDouble<T> :: remove(T data){
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
    }while(data.isDifferent(NodeToDelete->getData()) && NodeToDelete!=head);

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
bool listCDouble<T>:: update(int n, T data){  //remueve en posicion n+1 (n contando desde 0) y agrega data
    //case: Not possible
    if(n>=length){ // max indice= length-1
        return false;
    }
    //case Possible
    NodeCDouble<T>* last=tail;
    NodeCDouble<T>* actual=head; // node in position to delete
    //gets position in actual 
    for(int i=0; i<n; i++){
        last=actual;
        actual=actual->getNext();
    }
    // cases--> data matches their place

    // Possible 1. at head (actual)
    if(actual==head){
        if(data.getAge()<=actual->getNext()->getData().getAge()){ //it preserves posistion if the new data smaller or equal than the data next to head
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
        if(data.getAge()>=last->getData().getAge()){  //preserves space in memory if the prev data is smaller or equal than the new Data
            actual->setData(data);  //just change the data
        }else{
            removeLast();       //otherwise, removeLast & insert
            insert(data);
        }
        return true;
    }
    //Possible 3. Between nodes
    if(data.getAge()<=last->getData().getAge() && data.getAge()>=actual->getNext()->getData().getAge()){    //preserves space in memory
        actual->setData(data);  
    }else{
        remove(actual->getData());
        insert(data);
    }
    return true;
}

template<class T>
void listCDouble<T>:: printReverse(){
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