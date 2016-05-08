//
// Created by abondar on 08.05.16.
//

#include <sstream>
#include "FileReadError.h"

FileReadError::FileReadError(const string &fileNameIn, int lineNumIn) :FileError(fileNameIn),
                                                                       lineNum(lineNumIn){
    ostringstream ostr;
    ostr << "Error reading" << fileNameIn << " at line "<<lineNumIn;
    msg = ostr.str();
}