#include"../node/node.cpp"

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
        bool remove(T);  //confirma si lo removio
        void print();   //una sola direccion
        bool update(int, T);    //elimina dato en posision int, haciendo head 0 y agrega dato T

};