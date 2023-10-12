#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Animal.h"
#include "List.h"
#include "Appt.h"

/**
 * @brief represents an appointment schedule of veterinary clinic
 * 
 * @author Boris Zugic
 */
class Schedule{
    
    friend ostream& operator<<(ostream&, Schedule&);

    public:
        Schedule();
        ~Schedule();
        bool addAppt(Animal*, int, int, int, int, int);
        List<Appt*>& getAppointments();

    private:
        int numAppts;
        List<Appt*> appts;
        bool overlap(Appt*, Appt*);
        bool error(int, int, int, int, int);
};

#endif