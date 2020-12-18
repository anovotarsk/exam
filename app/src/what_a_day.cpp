#include "what_a_day.h"

std::string what_a_day(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month - 12 * a - 2;
    int week_day = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

    if (day < 1 || day > 31)
        throw "day";
    if (month < 1 || month > 12)
        throw "month";
    if (year < 1583)
        throw "year";

    switch (week_day){
        case 0:
            return "Sunday 0";
       case 1:
           return "Monday 1";
       case 2:
           return "Tuesday 2";
       case 3:
           return "Wednesday 3";
       case 4:
           return "Thursday 4";
       case 5:
           return "Friday 5";
       case 6:
           return "Saturday 6";
    }
    return "Error";
}
