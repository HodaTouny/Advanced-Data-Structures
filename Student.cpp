#include "Student.h"

Student::Student(int id, string name, float gpa, string department){
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    this->department = department;
}

int Student::getID() {
    return id;
}

string Student::getName(){
    return name;
}

string Student::getDepartment(){
    return department;
}

float Student::getGPA(){
    return gpa;
}

void Student::setID(int id) {
    this->id = id;
}

void Student::setName(string name) {
    this->name = name;
}

void Student::setDepartment(string department) {
    this->department = department;
}

void Student::setGPA(float gpa) {
    this->gpa = gpa;
}

bool Student::operator<(Student& other){
    return id < other.id;
}

bool Student::operator>(Student& other){
    return id > other.id;
}

bool Student::operator==(Student& other){
    return id == other.id;
}
