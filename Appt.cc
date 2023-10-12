#include <iostream>
#include <iomanip>
using namespace std;

#include "Appt.h"
#include "defs.h"

int Appt::nextId = APPT_IDS;

Appt::Appt(Animal* a, Date* d) : animal(a), date(d){
    id = nextId;
    nextId++;
}

Appt::~Appt(){delete date;}

bool Appt::sameDay(Appt* other){return this->date->sameDay(*(other->date));}

int Appt::getId(){return id;}

Date* Appt::getDate(){return date;}

Animal* Appt::getAnimal(){return animal;}

ostream& operator<<(ostream& output, Appt& appt){
    
    output << appt.getId() << "   ";
    output << *(appt.getDate()) << " -- " << appt.getAnimal()->getName() << " with parent " << appt.getAnimal()->getParentName() << endl;

    return output;
}