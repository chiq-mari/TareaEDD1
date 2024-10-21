#include<iostream>
using namespace std;

class Persona{
    private:
        string name;
        string lastName;
        int age;
        int id;
    public:
        Persona();
        Persona(string, string, int, int);
        string getName();
        string getLastName();
        int getAge();
        int getID();    
        bool isEqual(Persona);
        bool isDifferent(Persona);     
};