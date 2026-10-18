#include "date.h"
#include <ctime>


str Date::today(){
    std::time_t k = std::time(nullptr);
    std::tm* now = std::localtime(&k);
    
    // Convertimos los enteros a str para armar "YYYY-MM-DD"
    str yearStr = str::fromInt(now->tm_year + 1900);
    str monthStr = str::fromInt(now->tm_mon + 1);
    str dayStr = str::fromInt(now->tm_mday);
    
    // Agregamos ceros a la izquierda si es necesario (ej. mes 5 -> "05")
    if (monthStr.len() == 1) monthStr = str("0") + monthStr;
    if (dayStr.len() == 1) dayStr = str("0") + dayStr;
    
    return yearStr + "-" + monthStr + "-" + dayStr;
}
