//
// Created by abondar on 13.04.16.
//

#include "Employee.h"
#include <iostream>

using namespace std;

namespace Records {

    Employee::Employee() :
            firstName(""),
            lastName(""),
            employeeNumber(-1),
            salary(DefaultSalary),
            hired(false) { }

    void Employee::promote(int raiseAmout) {
        setSalary(getSalary() + raiseAmout);
    }

    void Employee::demote(int demeritAmout) {
        setSalary(getSalary() - demeritAmout);
    }

    void Employee::hire() {
        hired = true;
    }

    void Employee::fire() {
        hired = false;
    }

    void Employee::display() const {
        cout << "Employee: " << getLastName() << ", " << getFistName() << endl;
        cout << "-------------------" << endl;
        cout << (hired ? "Current employee" : "Former employee") << endl;
        cout << "Employee number: " << getEmployeeNumber() << endl;
        cout << "Employee salary: " << getSalary() << endl;
        cout << endl;
    }

    void Employee::setFirstName(std::string firstName) {
        this -> firstName = firstName;
    }

    std::string Employee::getFistName() const {
        return  firstName;
    }

    void Employee::setLastName(std::string lastName) {
        this -> lastName = lastName;
    }

    std::string Employee::getLastName() const {
        return lastName;
    }

    void Employee::setEmployeeNumber(int number) {
        this->employeeNumber = number;
    }

    int Employee::getEmployeeNumber() const {
        return employeeNumber;
    }

    void Employee::setSalary(int salary) {
        this->salary = salary;
    }

    int Employee::getSalary() const {
        return salary;
    }

    bool Employee::getIsHired() const {
        return hired;
    }


}