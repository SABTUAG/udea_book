#ifndef TIME_H
#define TIME_H

#include <string>

class Date {
private:
    int _year; 
    int _months; 
    int _days; 
    int _hours; 
    int _minutes;
    std::string _current; 

public:
    //Constructor
    Date(); 

    //Getters
    std::string getCurrent() const {
        return _current;
    }
    int getYear() const {
        return _year; 
    }
    int getMonths() const {
        return _months;
    }
    int getDays() const {
        return _days;
    }
    int  getHours() const {
        return _hours;
    }
    int getMinutes() const {
        return _minutes;
    }
};

#endif
