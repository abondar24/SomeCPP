//
// Created by abondar on 08.05.16.
//

#ifndef SOMECPP_FILEERROR_H
#define SOMECPP_FILEERROR_H

#include <string.h>
#include <array>

using namespace std;

class FileError :runtime_error{
public:

    FileError(const string& fileIn) : runtime_error(""),file(fileIn){} //integrate to standart exception lib
    virtual const char* what() const noexcept { return  msg.c_str();}
    string getFileName(){ return file;}

protected:
    string file;
    string msg;
};


#endif //SOMECPP_FILEERROR_H
