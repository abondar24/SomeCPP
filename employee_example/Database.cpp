//
// Created by abondar on 19.04.16.
//

#include <iostream>
#include "Database.h"

using namespace std;

namespace Records {

    Database::Database() {
        nextEmployeesNum = firstEmployeeNumber;
    }

    Database::~Database() { }

    Employee& Database::addEmployee(std::string firstName, std::string lastName) {
        Employee employee;
        employee.setFirstName(firstName);
        employee.setLastName(lastName);
        employee.setEmployeeNumber(nextEmployeesNum++);
        employee.hire();
        employees.push_back(employee);

        return employees[employees.size() - 1];
    }

    Employee& Database::getEmployee(int employeeNumber) {
        for (auto iter = employees.begin(); iter != employees.end(); ++iter) {
            if (iter->getEmployeeNumber() == employeeNumber)
                return *iter;
        }

        cerr << "No employee with number" << endl;
    }

    Employee& Database::getEmployee(std::string fistName, std::string lastName) {
        for (auto iter = employees.begin(); iter != employees.end(); ++iter) {
            if (iter->getFistName() == fistName && iter->getLastName() == lastName)
                return *iter;
        }

        cerr << "No such employee with number" << endl;
    }

    void Database::displayAll() {
        for (auto iter = employees.begin(); iter != employees.end(); ++iter) {
            iter->display();
        }
    }

    void Database::displayCurrent() const {
        for (auto iter = employees.begin(); iter != employees.end(); ++iter) {
            if (iter->getIsHired())
                iter->display();
        }
    }

    void Database::displayFormer() const {
        for (auto iter = employees.begin(); iter != employees.end(); ++iter) {
            if (!iter->getIsHired())
                iter->display();
        }
    }
}