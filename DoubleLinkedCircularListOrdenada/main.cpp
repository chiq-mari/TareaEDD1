#include".\list\list.cpp"
#include"..\classPerson\Person.cpp"
Persona person1("Luis", "Alavarez", 20,1733177);
Persona person2("Luisa", "Corps", 15, 193187);
Persona person3("Faber", "Guerro", 12, 222193);
Persona person4("Tadeas", "Purvis", 30, 51102);
Persona person5("Freeman", "Stringman",20, 98715 );
Persona person6("Bella", "Surgood", 10, 30182);
Persona person7("Lizabeth", "Rapp",30, 244208 );
Persona person8("Holt", "Gomery", 32, 244301 );
Persona person9("Jose", "Louis", 30, 240100);


listCDouble<Persona> myList(nullptr);

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

    myList.insert(person5);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(person6);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;
    
    myList.insert(person7);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    myList.insert(person8);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    cout<<myList.remove(person9);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    cout<<myList.remove(person8);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    cout<<myList.remove(person6);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    cout<<myList.remove(person2);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    cout<<myList.update(13, person1);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    cout<<myList.update(3, person3);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;

    cout<<myList.update(4, person9);
    cout<<"printing the list: "<<endl;
    myList.print();
    cout<<endl<<endl;
    

}