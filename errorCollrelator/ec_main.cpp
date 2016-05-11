//
// Created by abondar on 12.05.16.
//

#include "ErrorCorrelator.h"

int main(){
    ErrorCorrelator ec;
    ec.addError(Error(3, "Can't read file"));
    ec.addError(Error(1, "Incorrect input"));
    ec.addError(Error(10, "Bad energy"));

    while (true) {
        try {
            Error e = ec.getError();
            cout << e << endl;
        } catch (const out_of_range &) {
            cout << "Finished processing errors" << endl;
            break;
        }
    }

    return 0;
}