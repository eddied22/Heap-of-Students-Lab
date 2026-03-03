#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Student.h"

void loadStudents(std::vector<Student*>& students) {
    std::ifstream file("students.csv");
    std::string line;

    while (getline(file, line)) {
        Student* s = new Student(line);
        students.push_back(s);
    }

    file.close();
}

void printStudents(std::vector<Student*>& students) {
    for (auto s : students) {
        s->printFull();
    }
}

void showStudentNames(std::vector<Student*>& students) {
    for (auto s : students) {
        s->printName();
    }
}

void findStudent(std::vector<Student*>& students) {
    std::string search;
    std::cout << "Last name of student: ";
    std::cin >> search;

    for (auto s : students) {
        if (s->getLastName().find(search) != std::string::npos) {
            s->printFull();
        }
    }
}

void deleteStudents(std::vector<Student*>& students) {
    for (auto s : students) {
        delete s;
    }
    students.clear();
}

std::string menu() {
    std::string choice;
    std::cout << "\n0) quit\n";
    std::cout << "1) print all student names\n";
    std::cout << "2) print all student data\n";
    std::cout << "3) find a student\n";
    std::cout << "4) sort by last name\n";
    std::cout << "5) sort by first name\n";
    std::cout << "6) sort by credit hours (descending)\n";
    std::cout << "\nplease choose 0-6: ";
    std::cin >> choice;
    return choice;
}

int main() {
    std::vector<Student*> students;
    loadStudents(students);

    std::string choice;

    do {
        choice = menu();

        if (choice == "1") {
            showStudentNames(students);
        }
        else if (choice == "2") {
            printStudents(students);
        }
        else if (choice == "3") {
            findStudent(students);
        }
        else if (choice == "4") {
            std::sort(students.begin(), students.end(),
                [](Student* a, Student* b) {
                    return a->getLastName() < b->getLastName();
                });
        }
        else if (choice == "5") {
            std::sort(students.begin(), students.end(),
                [](Student* a, Student* b) {
                    return a->getFirstName() < b->getFirstName();
                });
        }
        else if (choice == "6") {
            std::sort(students.begin(), students.end(),
                [](Student* a, Student* b) {
                    return a->getCredits() > b->getCredits();
                });
        }

    } while (choice != "0");

    deleteStudents(students);

    return 0;
}
