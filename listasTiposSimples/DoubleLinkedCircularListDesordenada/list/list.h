#include"..\node\node.cpp"

template<class T>
class listCDoubleDesord{
    private:
        NodeCDouble<T>* head=nullptr;
        NodeCDouble<T>* tail=nullptr;
        int length=0;
    public: 
        listCDoubleDesord(NodeCDouble<T>*);   //constructor por args
        bool isEmpty(); //retorna true si la lista esta vacia
        void insertFirst(T);    //inserta de primero( no toma orden)
        void insertLast(T); //inserta de ultimo( no toma orden) 
        void insert(T);     //insert tomando el orden
        void removeFirst(); //remueve el primero
        void removeLast();  //remueve el ultimo
        bool remove(T);     //remueve el dato dado
        bool removeP(int); //remueve el de posicion dada
        bool update(int, T);    //remueve el de la posicion int contando desde head->0, y agrega dato tipo T
        void print();   
        void printReverse();
};

//checked listCDouble, isEmpty, print