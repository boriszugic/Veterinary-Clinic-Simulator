#include <iostream>
#include <iomanip>
using namespace std;

#include "Schedule.h"
#include "CompareDate.h"
#include "List.h"

Schedule::Schedule(){
    appts.setComparison(new CompareDate<Appt*>(true));
}

Schedule::~Schedule(){
    appts.cleanupData();
}

bool Schedule::addAppt(Animal* animal, int year, int month, int day, int hours, int mins){

    if (error(day, month, year, hours, mins))
        return false;

    Date* date = new Date(day, month, year, hours, mins);
    Appt* appt = new Appt(animal, date);

    Appt** apptsArray = new Appt*[MAX_ARR];
    int size = 0;

    appts.convertToArray(apptsArray, size);

    for (int i = 0; i < size; i++){
        if (appt->sameDay(apptsArray[i])){
            if (overlap(appt, apptsArray[i])){
                cout << "ERROR: " << "Appointment " << appt->getId() << " on " << *(appt->getDate()) << " conflicts with " 
                << apptsArray[i]->getId() << " on " << *(apptsArray[i]->getDate()) << endl;
                
                delete appt;
                delete[] apptsArray;
                
                return false;
            }
        }
    }

    appts.add(appt);
    
    delete[] apptsArray;
    return true;
}

ostream& operator<<(ostream& output, Schedule& schedule){

    cout << schedule.getAppointments();

    return output;
}

List<Appt *>& Schedule::getAppointments()
{
    return appts;
}

bool Schedule::overlap(Appt *a1, Appt *a2)
{

    Time t1 = a1->getDate()->getTime();
    t1.add(0, APPT_DURATION);

    Time t2 = a2->getDate()->getTime();
    t2.add(0, APPT_DURATION);

    if (((a1->getDate()->getTime() < a2->getDate()->getTime()) && (t1 < a2->getDate()->getTime() || t1 == a2->getDate()->getTime())) || 
    ((a2->getDate()->getTime() < a1->getDate()->getTime()) && (t2 < a1->getDate()->getTime() || t2 == a1->getDate()->getTime()))){
        return false;
    }

    return true;
}

bool Schedule::error(int day, int month, int year, int hours, int mins){

    if (year != CURR_YEAR){
        cout << "ERROR:  " << "Year " << year << " is invalid" << endl;
        return true;
    }

    if (!Date::validate(day, month, year)){
        cout.fill('0');
        cout << "ERROR:  " << "Date " << setw(4) << year << "/" << setw(2) << month << "/" << setw(2) << day << " is invalid" << endl;
        return true;
    }

    if (hours < OPEN_HRS || hours > CLOSE_HRS){
        cout << "ERROR:  " << "Hour " << hours << " is invalid" << endl;
        return true;
    }

    if (mins < 0 || mins > 59 || mins % 15 != 0){
        cout << "ERROR:  " << "Minutes " << mins << " are invalid" << endl;
        return true;
    }

    return false;
}