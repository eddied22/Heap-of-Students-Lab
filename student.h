#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Address.h"
#include "Date.h"

class Student {
private:
    std::string firstName;
    std::string lastName;
    Address* address;
    Date* dob;
    Date* grad;
    int credits;

public:
    Student() {
        address = nullptr;
        dob = nullptr;
        grad = nullptr;
    }

    Student(std::string line) {
        std::stringstream ss(line);
        std::string temp;
        std::vector<std::string> data;

        while (getline(ss, temp, ',')) {
            data.push_back(temp);
        }

        firstName = data[0];
        lastName = data[1];

        address = new Address(data[2], data[3], data[4], data[5]);
        dob = new Date(data[6], stoi(data[7]), stoi(data[8]));
        grad = new Date(data[9], stoi(data[10]), stoi(data[11]));
        credits = stoi(data[12]);
    }

    ~Student() {
        delete address;
        delete dob;
        delete grad;
    }

    void printFull() {
        std::cout << firstName << " " << lastName << std::endl;
        address->print();
        std::cout << "DOB: ";
        dob->print();
        std::cout << std::endl;
        std::cout << "Grad: ";
        grad->print();
        std::cout << std::endl;
        std::cout << "Credits: " << credits << std::endl;
        std::cout << "____________________________________" << std::endl;
    }

    void printName() {
        std::cout << lastName << ", " << firstName << std::endl;
    }

    std::string getLastName() { return lastName; }
    std::string getFirstName() { return firstName; }
    int getCredits() { return credits; }
};

#endif
