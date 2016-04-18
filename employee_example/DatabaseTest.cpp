//
// Created by abondar on 19.04.16.
//
#include<iostream>
#include "Database.h"
using namespace std;
using namespace Records;

int main(){

    Database myDB;

    Employee& emp1 = myDB.addEmployee("Rudolf","Steiner");
    emp1.fire();

    Employee& emp2 = myDB.addEmployee("Mirko","Kurkinnen");
    emp2.setSalary(100000);


    Employee& emp3 = myDB.addEmployee("Lukas","Heinzmann");
    emp3.setSalary(10000);
    emp3.promote();

    cout << "All employees: "<<endl;
    cout << endl;
    myDB.displayAll();

    cout << "Current employees: "<<endl;
    cout << endl;
    myDB.displayCurrent();

    cout << "Former employees: "<<endl;
    cout << endl;
    myDB.displayFormer();

    return  0;
}