//
// Created by abondar on 19.04.16.
//

#include <iostream>
#include <stdexcept>
#include "Database.h"


using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);
void doDemote(Database& inDB);

int main() {
    Database employeeDB;
    bool done = false;

    while (!done) {
        int selection = displayMenu();
        switch (selection) {
            case 1:
                doHire(employeeDB);
                break;

            case 2:
                doFire(employeeDB);
                break;

            case 3:
                doPromote(employeeDB);
                break;

            case 4:
                employeeDB.displayAll();
                break;

            case 5:
                employeeDB.displayCurrent();
                break;

            case 6:
                employeeDB.displayFormer();
                break;

            case 0:
                done = true;

            default:
                cerr << "Unknown command" << endl;
        }
    }

    return 0;
}


int displayMenu() {
    int selection;
    cout << endl;
    cout << "Employee Database" << endl;
    cout << "---------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire a new employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) List all employees" << endl;
    cout << "5) List all current employees" << endl;
    cout << "6) List all previous employees" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    cin >> selection;
    return selection;
}

void doHire(Database& inDb) {
    string firstName;
    string lastName;

    cout << "First name ? ";
    cin >> firstName;

    cout << "Last name ? ";
    cin >> lastName;

    try {
        inDb.addEmployee(firstName, lastName);
    } catch (const std::exception) {
        cerr << "Unable to add a new employee" << endl;
    }

}


void doFire(Database& inDb) {
    int empNumber;

    cout << "Employee number?";
    cin >> empNumber;
    try {
        Employee &employee = inDb.getEmployee(empNumber);
        employee.fire();
        cout << "Employee " << empNumber << " terminated." << endl;
    } catch (const std::exception) {
        cerr << "Unable to terminate employee" << endl;
    }
}

void doPromote(Database& inDb){
    int empNumber;
    int raiseAmount;

    cout << "Employee number? ";
    cin >>empNumber;
    cout << "How much is a raise? ";
    cin >> raiseAmount;
    try {
        Employee &employee = inDb.getEmployee(empNumber);
        employee.promote(raiseAmount);

    } catch (const std::exception) {
        cerr << "Unable to promote employee" << endl;
    }

}