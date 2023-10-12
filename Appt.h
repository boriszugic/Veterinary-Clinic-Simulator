#ifndef APPT_H
#define APPT_H

#include "Animal.h"
#include "Date.h"

/**
 * @brief represents an appointment of the veterinary clinic
 *
 * @author Boris Zugic 
 */
class Appt{

    friend ostream& operator<<(ostream&, Appt&);

    public:
        Appt(Animal*, Date*);
        ~Appt();
        bool sameDay(Appt*);
        int getId();
        Date* getDate();
        Animal* getAnimal();

    private:
        static int nextId;
        int id;
        Animal* animal;
        Date* date;
};

#endif