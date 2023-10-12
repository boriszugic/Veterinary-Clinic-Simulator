#include <iostream>
using namespace std;
#include <iomanip>

#include "Animal.h"
#include "defs.h"

int Animal::nextId = ANIMAL_IDS;

Animal::Animal(SpeciesType s, string n, string g, int y, int m, string pname){
    species = s;
    name = n;
    age = (y * 12) + m;
    parent = pname;
    id = nextId;
    nextId++;
}
Animal::~Animal(){}

int Animal::getId() const
{
    return this->id;
}

int Animal::getAge() const
{
    return this->age;
}


string Animal::getName() const
{
    return this->name;
}

string Animal::getParentName() const
{
    return this->parent;
}

SpeciesType Animal::getSpecies() const
{
    return species;
}


ostream& operator<<(ostream& output, Animal& a){

    output << a.getId() << ":  " << setw(9) << left << a.getName() << " :  "; 
    
    if (a.getSpecies() == C_CAT)
        output << setw(5) << left << "Cat";
    else if (a.getSpecies() == C_DOG)
        output << setw(5) << left << "Dog";
    else{
        output << setw(5) << left << "Other";
    }

    output << ";  Age: " << setw(2) << right << a.getAge()/12 << " yrs, " << setw(2) << left << a.getAge()%12 << " mths;  Parent: " << a.getParentName() << endl;
    
    return output;
}