//
// Created by abondar on 08.05.16.
//

#include "FileOpenError.h"


FileOpenError::FileOpenError(const string &fileNameIn):FileError(fileNameIn) {
    msg = "Unable to open " + fileNameIn;
}