#include <bits/stdc++.h>
#include "FileData.cpp"
#include "Student.cpp"
#include "AVL.cpp"
using namespace std;

int main() {
    FileData fileData("students.txt");
    vector<Student> students = fileData.readData();
    AVL avl;
    for (const auto& student : students) {
        avl.addStudent(student);
    }

    int choice;
    do {
        cout << "((First Menu - Main menu))" << endl;
        cout << "Choose Data Structure:" << endl;
        cout << "1. BST" << endl;
        cout << "2. AVL" << endl;
        cout << "3. Min Heap" << endl;
        cout << "4. Max Heap" << endl;
        cout << "5. Exit Program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:

                break;
            case 2: {
                int subChoice;
                do {
                    cout << "((Second Menu - BST))" << endl;
                    cout << "Choose one of the following options:" << endl;
                    cout << "1. Add student" << endl;
                    cout << "2. Remove student" << endl;
                    cout << "3. Search student" << endl;
                    cout << "4. Print All (sorted by ID)" << endl;
                    cout << "5. Return to main menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1: {
                            int id;
                            string name, department;
                            float gpa;

                            cout << " Enter student ID: ";
                            cin >> id;
                            cin.ignore();
                            while (true) {
                                bool is_found = true;
                                for (auto it = students.begin(); it != students.end(); ++it) {
                                    if (it->getID() == id||id>100) {
                                        cout <<"Unavailable ID " << endl;
                                        cout << " Enter student ID: ";
                                        cin >> id;
                                        cin.ignore();
                                        is_found = false;
                                        break;
                                    }
                                }
                                if (is_found) {
                                    break;
                                }
                            }
                            cout << "Enter student name: ";
                            getline(cin, name);

                            cout << "Enter student GPA: ";
                            cin >> gpa;
                            cin.ignore();
                            cout << "Enter student department: ";
                            getline(cin, department);
                            Student student(id, name, gpa, department);
                            avl.addStudent(student);
                            students.push_back(student);
                            fileData.setStudentVector(students);
                            fileData.writeData();
                            cout << "Student added." << endl;
                            break;
                        }
                        case 2: {
                            int id;
                            cout << "Enter student ID to remove: ";
                            cin >> id;
                            avl.removeStudent(id);
                            for (auto it = students.begin(); it != students.end(); ++it) {
                                if (it->getID() == id) {
                                    students.erase(it);
                                    cout << "Student removed." << endl;
                                    break;
                                }
                            }
                            fileData.setStudentVector(students);
                            fileData.writeData();
                            break;
                        }

                        case 3: {
                            int id;

                            cout << "Enter student ID to search: ";
                            cin >> id;

                            avl.searchStudent(id);

                            break;
                        }
                        case 4: {
                            cout << "Printing all students (sorted by ID):" << endl;
                            avl.printAll();

                            cout << "Printing students per department:" << endl;
                            avl.countStudentsPerDepartment();

                            break;
                        }
                        case 5:
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (subChoice != 5);

                break;
            }
            case 3:

                break;
            case 4:

                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    fileData.setStudentVector(students);
    return 0;
}
