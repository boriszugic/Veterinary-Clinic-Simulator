#ifndef TIME_H
#define TIME_H

/**
 * @brief This class represents a time object, a clock. A clock has hours and minutes. Basic functionality is provided.
 * 
 * @author Boris Zugic
 */
class Time
{
  friend std::ostream& operator<<(std::ostream&, Time&);
  
  public:
    Time(int=0, int=0);
    void add(int, int);

    bool operator==(const Time&) const;
    bool operator<(const Time&) const;

  private:
    int hours;
    int minutes;
};

#endif
