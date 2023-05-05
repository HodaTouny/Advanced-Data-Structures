
#ifndef DS_ASSIGMENT3_FILEDATA_H
#define DS_ASSIGMENT3_FILEDATA_H


#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

class FileData {
private:
    string filename;
    vector<Student> students;
    int num_students;

public:
    FileData(string filename) : filename(filename), num_students(0) {}
    vector<Student> readData();
    void writeData();
    void setStudentVector(std::vector<Student> students);
};
#endif //DS_ASSIGMENT3_FILEDATA_H
