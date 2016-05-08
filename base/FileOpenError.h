//
// Created by abondar on 08.05.16.
//

#ifndef SOMECPP_FILEOPENERROR_H
#define SOMECPP_FILEOPENERROR_H


#include "FileError.h"

class FileOpenError : public FileError{
public:
    FileOpenError(const string& fileNameIn);

};


#endif //SOMECPP_FILEOPENERROR_H
