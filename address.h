#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <string>
class Address {
private:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
public:
    Address() {}

    Address(std::string st, std::string c, std::string s, std::string z) {
        street = st;
        city = c;
        state = s;
        zip = z;
    }

    void print() {
        std::cout << street << std::endl;
        std::cout << city << " " << state << ", " << zip << std::endl;
    }
};
#endif
