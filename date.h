#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
private:
    std::string month;
    int day;
    int year;

public:
    Date() {}

    Date(std::string m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

    void print() {
        std::cout << month << " " << day << ", " << year;
    }
};

#endif
