#include "../app/src/what_a_day.h"
#include <string>
#include <iostream>
#include <cassert>

int main() {
    std::string day;
    try {
        day = what_a_day(35, 12, 2020);
    }
    catch (const char * str) {
        day = str;
    }

    assert(day == "day");
}
