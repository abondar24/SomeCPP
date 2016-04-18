//
// Created by abondar on 19.04.16.
//

#ifndef SOMECPP_DATABASE_H
#define SOMECPP_DATABASE_H

#include <vector>
#include "Employee.h"

namespace Records {
    const int  firstEmployeeNumber  = 1000;
    class Database {
    public:
        Database();

        ~Database();

        Employee& addEmployee(std::string firstName,std::string lastName);
        Employee& getEmployee(int employeeNumber);
        Employee& getEmployee(std::string fistName,std::string lastName);
        void displayAll();
        void displayCurrent() const;
        void displayFormer() const;


    protected:
        std::vector<Employee> employees;
        int nextEmployeesNum;
    };


}

#endif //SOMECPP_DATABASE_H
