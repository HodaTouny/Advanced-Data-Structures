#include "FileData.h"

vector<Student> FileData::readData() {
    ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error while opening\n" ;
        return students;
    }

    infile >> num_students;

    for (int i = 0; i < num_students; i++) {
        int id;
        string name, department;
        float gpa;
        infile >> id >> ws;
        getline(infile, name);
        infile >> gpa >> ws;
        getline(infile, department);
        students.push_back(Student(id, name, gpa, department));
    }

    infile.close();
    return students;
}

void FileData::writeData() {
   ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Error while opening\n" ;
        return;
    }

    outfile << num_students <<"\n";
    for (auto& student : students) {
        outfile << student.getID() <<"\n" << student.getName() <<"\n"<< student.getGPA() << "\n"<< student.getDepartment() <<"\n";
    }

    outfile.close();
}

void FileData::setStudentVector(std::vector<Student> students) {
    this->students = students;
    this->num_students = students.size();
}