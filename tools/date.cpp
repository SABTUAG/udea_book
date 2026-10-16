#include "date.h"
#include <ctime>

Date Date::today(){
    std::time_t k = std::time(nullptr);
    std::tm* now = std::localtime(&k);
    return Date(
        now->tm_year + 1900, 
        now->tm_mon+1, 
        now->tm_mday
    ); 
}