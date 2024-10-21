#include".\list\list.cpp"

listC<int> myList;

main(){
    cout<<"printing the list: "<<endl;
    myList.print();

    myList.insert(10);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(15);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;
    
    myList.insert(5);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(1);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(18);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(9);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(9);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;
    
}