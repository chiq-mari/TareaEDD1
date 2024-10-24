#include<iostream>
using namespace std;

template<class T>
class NodeCDouble{
    private:
        T data;
        NodeCDouble<T>* next=nullptr;
        NodeCDouble<T>* prev=nullptr;
    public :
       //constructores por default y con args
        NodeCDouble(T, NodeCDouble<T>*, NodeCDouble<T>*);  
        ~NodeCDouble();  //destructor
        T getData();    //get y set data
        void setData(T);
        NodeCDouble<T>* getNext();   //get y set Next
        void setNext(NodeCDouble<T>*);   
        NodeCDouble<T>* getPrev();   //get y set Prev
        void setPrev(NodeCDouble<T>*);
        void print();   //print the Node
};