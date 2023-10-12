#ifndef ANIMAL_H
#define ANIMAL_H

#include <string.h>
#include "defs.h"

/**
 * @brief represents an animal client of the veterinary clinic
 *
 * @author Boris Zugic 
 */
class Animal{

    friend ostream& operator<<(ostream&, Animal&);

    public:
        Animal(SpeciesType, string, string, int, int, string);
        ~Animal();
        int getId() const;
        int getAge() const;
        string getName() const;
        string getParentName() const;
        SpeciesType getSpecies() const;

    private:
        static int nextId;
        int id;
        SpeciesType species;
        string name;
        string gender;
        int age;
        string parent;
};

#endif