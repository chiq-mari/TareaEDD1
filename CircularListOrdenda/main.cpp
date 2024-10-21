#include".\list\list.cpp"
#include"..\classPerson\Person.cpp"
Persona person1("Luis", "Alavarez", 56,4);
Persona person2("Luisa", "Corps", 45, 5);
Persona person3("Faber", "Guerro", 53, 5);
Persona person4("Tadeas", "Purvis", 30, 5);


listC<Persona> myList;

main(){
    cout<<"printing the list: "<<endl;
    myList.print();

    myList.insert(person1);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(person2);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;
    
    myList.insert(person3);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(person4);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;
    
}