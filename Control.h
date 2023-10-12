#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"
#include "Schedule.h"
#include "List.h"

/**
 * @brief controls control flow of program
 * 
 * @author Boris Zugic
 */
class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    void initSchedule();
    void initAnimals();
    bool addAppt(int, int, int, int, int, int);
    View view;
    Schedule* schedule;
    List<Animal*> animals;
};

#endif
