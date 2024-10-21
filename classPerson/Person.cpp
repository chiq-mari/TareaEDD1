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