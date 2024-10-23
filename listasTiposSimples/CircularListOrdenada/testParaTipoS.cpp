#include".\list\list.cpp"

listC<int> myList;

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
    
    myList.insert(2);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(0);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.remove(9);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.update(2, 3);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;
    
}