//
// Created by abondar on 08.05.16.
//

#ifndef SOMECPP_FILEREADERROR_H
#define SOMECPP_FILEREADERROR_H


#include "FileError.h"

class FileReadError : public FileError{
public:
    FileReadError(const string& fileNameIn, int lineNumIn);
    int getLineNum(){ return lineNum;};
protected:

    int lineNum;
};


#endif //SOMECPP_FILEREADERROR_H
