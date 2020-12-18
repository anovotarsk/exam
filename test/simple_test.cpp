#include "../app/src/what_a_day.h"
#include <string>
#include <iostream>
#include <cassert>

int main() {
    std::string day = what_a_day(18, 12, 2020);

    assert(day == "Friday");
}
