#include"../node/node.cpp"

//para uso dato tipo Person

template<class T>
class listC{ //class for a circular linked list
    private:
        NodeC<T>* head;
        NodeC<T>* tail;
        int length;
    public:  
        listC();//constructor
        bool isEmpty(); //tested
        void insertFirst(T);    //tested
        void insertLast(T);     //tested
        void insert(T);         //tested
        void removeFirst(); //removes the first element (does not alter the order of the list)      //tested
        void removeLast();  //removes tail (this does not alter the order of the list)              //tested
        bool remove(T);  //confirma si lo removio       //tested
        void print();   //una sola direccion       //tested 
        bool update(int, T);    //elimina dato en posicion int, haciendo head 0 y agrega dato T     //tested

};