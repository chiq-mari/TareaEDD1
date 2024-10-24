#include".\list\list.cpp"

int main(){
    NodeCDouble<int>* hi =new NodeCDouble<int>(9, nullptr, nullptr);
    listCDouble<int> myList(hi);

    myList.insert(8);
    cout<<"Printing the list \n";
    myList.print();
    cout<<"\n";


    myList.insert(4);
    cout<<"Printing the list \n";
    myList.print();
    cout<<"\n";

    myList.insert(11);
    cout<<"Printing the list \n";
    myList.print();
    cout<<"\n";

    myList.insert(10);
    cout<<"Printing the list \n";
    myList.print();
    cout<<"\n";

    myList.remove(10);
    cout<<"Printing the list \n";
    myList.print();
    cout<<"\n";

    myList.remove(4);
    cout<<"Printing the list \n";
    myList.print();
    cout<<"\n";

    cout<<myList.update(0, 10);
    cout<<"Printing the list \n";
    myList.print();
    cout<<"\n";

    cout<<myList.update(1, 5);
    cout<<"Printing the list \n";
    myList.print();
    cout<<"\n";

    cout<<myList.update(2, 7);
    cout<<"Printing the list \n";
    myList.print();
    cout<<"\n";

    cout<<"Printing reverse"<<endl;
    myList.printReverse();

}

