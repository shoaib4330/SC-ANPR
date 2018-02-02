//
// Created by shoaib
//
#ifndef CLASSIFIERTESTING_CONSTANTS_H
#define CLASSIFIERTESTING_CONSTANTS_H

#include <string>
using namespace std;

class Constants {
public:
    static const string extracted_plates_dir_name;
    static const string project_dirs_abs_path;
};
const string Constants::extracted_plates_dir_name="extracted_plates";
const string Constants::project_dirs_abs_path="/home/abdul/CLionProjects/ClassifierTesting/detectorfiles";
#endif //CLASSIFIERTESTING_CONSTANTS_H
