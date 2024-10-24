#include"../node/node.cpp"

//para uso dato tipo Persona

template<class T>
class listC{ //class for a circular linked list
    private:
        NodeC<T>* head;
        NodeC<T>* tail;
        int length;
    public:  
        listC();//constructor
        bool isEmpty(); 
        void insertFirst(T);    
        void insertLast(T);     
        void insert(T);         
        void removeFirst(); //removes the first element (does not alter the order of the list)      
        void removeLast();  //removes tail (this does not alter the order of the list)              
        bool remove(T);  //confirma si lo removio      
        void print();   //una sola direccion       
        bool update(int, T);    //elimina dato en posicion int, haciendo head 0 y agrega dato T     

};