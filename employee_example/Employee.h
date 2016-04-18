//
// Created by abondar on 13.04.16.
//

#ifndef SOMECPP_EMPLOYEE_H
#define SOMECPP_EMPLOYEE_H

#include <string>

namespace Records {
    const int DefaultSalary = 30000;

    class Employee {
      public:
        Employee();
        void promote(int raiseAmout =1000);
        void demote(int demeritAmout = 1000);
        void hire();
        void fire();
        void display() const;

        void setFirstName(std::string firstName);
        std::string getFistName() const;
        void setLastName(std::string lastName);
        std::string getLastName() const;
        void setEmployeeNumber(int number);
        int getEmployeeNumber() const;
        void setSalary(int salary);
        int getSalary() const;
        bool getIsHired() const;


    protected:
        std::string firstName;
        std::string lastName;
        int employeeNumber;
        int salary;
        bool hired;

    };
}


#endif //SOMECPP_EMPLOYEE_H
