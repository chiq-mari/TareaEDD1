#include ".\Person.h"

Persona :: Persona(){
    name="";
    lastName="";
    age=0;
}
Persona::Persona(string name, string lastName, int age, int id){
    this->name=name;
    this->lastName=lastName;
    this->age=age;
    this->id=id;
}

string Persona:: getName(){
    return this->name;
}
string Persona::getLastName(){
    return this->lastName;
}
int Persona::getAge(){
    return this->age;
}
int Persona:: getID(){
    return this->id;
}

bool Persona:: isEqual(Persona p){
    return (this->name==p.getName() && this->lastName==p.getLastName() && this->age==p.getAge() && this->id==p.getID());
}

bool Persona:: isDifferent(Persona p){
    return (this->name!=p.getName() || this->lastName!=p.getLastName() || this->age!=p.getAge() || this->id!=p.getID());
}