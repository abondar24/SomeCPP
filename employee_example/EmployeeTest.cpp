//
// Created by abondar on 19.04.16.
//


#include "Employee.h"
#include <iostream>
using namespace std;
using namespace Records;

int main(){
    cout << "Employee test class" << endl;

    Employee employee;
    employee.setFirstName("Alex");
    employee.setLastName("Bondar");
    employee.setEmployeeNumber(217644);
    employee.setSalary(1000000);
    employee.promote();
    employee.promote(7);
    employee.hire();
    employee.display();
    return 0;
}