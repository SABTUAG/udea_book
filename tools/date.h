#ifndef DATE_H
#define DATE_H

#include "str.h"

class Date {

private:
    int _year; 
    int _months; 
    int _day;
    str _current; 

public:
    Date(); 
    Date(int year, int month, int day); 
    Date(const str& formatIso);
    
    static Date today(); 
};

#endif
