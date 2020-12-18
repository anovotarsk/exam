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
            return "Sunday";
       case 1:
           return "Monday";
       case 2:
           return "Tuesday";
       case 3:
           return "Wednesday";
       case 4:
           return "Thursday";
       case 5:
           return "Friday";
       case 6:
           return "Saturday";
    }
    return "Error";
}
