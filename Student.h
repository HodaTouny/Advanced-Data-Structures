#ifndef DS_ASSIGMENT3_STUDENT_H
#define DS_ASSIGMENT3_STUDENT_H


#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    int id;
    string name;
    string department;
    float gpa;
public:
    Student(int id, string name, float gpa, string department);
    Student();
    int getID();
    string getName();
    string getDepartment();
    float getGPA();

    void setID(int id);
    void setName(string name);
    void setDepartment(string department);
    void setGPA(float gpa);

    bool operator<(Student& other);
    bool operator>(Student& other);
    bool operator==(Student& other) ;
};


#endif //DS_ASSIGMENT3_STUDENT_H
