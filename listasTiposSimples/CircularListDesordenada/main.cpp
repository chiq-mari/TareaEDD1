#include".\list\list.cpp"

listCDesord<int> myList;

main(){
    cout<<"printing the list: "<<endl;
    myList.print();

    myList.insert(8);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(9);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.removeP(0);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;
    
    myList.insert(2);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(0);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(9);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.remove(2);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.update(2, 5);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;
}