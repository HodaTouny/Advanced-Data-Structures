#include <bits/stdc++.h>
#include "FileData.h"
#include "Student.h"
using namespace std;
class BSTNode {
public:
    Student student;
    BSTNode* left;
    BSTNode* right;
    BSTNode(const Student& student) {
        this->student=student;
        left=NULL;
        right= NULL;
    }
};
class BinarySearchTree {
private:
    BSTNode *root;
    BSTNode *addStudent(BSTNode *root, Student student) {
        if (root == nullptr) {
            return new BSTNode(student);
        }
        if (student < root->student) {
            root->left = addStudent(root->left, student);
        }
        else if (student > root->student) {
            root->right = addStudent(root->right, student);
        }
        return root;
    }

    BSTNode *removeStudent(BSTNode *root, int id) {
        if (root == nullptr) {
            return nullptr;
        }
        if (id < root->student.getID()) {
            root->left = removeStudent(root->left, id);
        }
        else if (id > root->student.getID()) {
            root->right = removeStudent(root->right, id);
        }
        else{
            if (root->right == nullptr) {
                BSTNode *temp = root->left;
                delete root;
                return temp;
            }
            else {
                BSTNode *temp = root->right;
                delete root;
                return temp;
            }

        }
        return root;
    }

    BSTNode *searchStudent(BSTNode *root, int id) {
        if (root == nullptr || root->student.getID() == id) {
            return root;
        }

        if (id < root->student.getID()) {
            return searchStudent(root->left, id);
        } else {
            return searchStudent(root->right, id);
        }
    }

    void printAll(BSTNode *root) {
        if (root != nullptr) {
            printAll(root->left);
            cout << root->student.getID() << ", " << root->student.getName() << ", " << root->student.getGPA() << ", "
                 << root->student.getDepartment() << endl;
            printAll(root->right);
        }
    }

    void countStudentsPerDepartment(BSTNode *root, map<string, int> &departmentCounts) {
        if (root != nullptr) {
            countStudentsPerDepartment(root->left, departmentCounts);
            departmentCounts[root->student.getDepartment()]++;
            countStudentsPerDepartment(root->right, departmentCounts);
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }
    void addStudent(Student student) {
        root = addStudent(root, student);
    }

    void removeStudent(int id) {
        BSTNode *result = searchStudent(root, id);
        if (result != nullptr) {
            root = removeStudent(root, id);
        } else {
            cout << "Student not found." << endl;
        }
    }

    void searchStudent(int id) {
        BSTNode *result = searchStudent(root, id);
        if (result != nullptr) {
            cout << "[" << result->student.getID() << ", " << result->student.getName() << ", "
                 << result->student.getGPA() << ", " << result->student.getDepartment() << "]" << endl;
        } else {
            cout << "Student not found." << endl;
        }
    }

    void printAll() {
        printAll(root);
    }
    void countStudentsPerDepartment() {
        map<string, int> departmentCounts;
        countStudentsPerDepartment(root, departmentCounts);
        cout << "Students per Departments:" << endl;
        for (const auto& it : departmentCounts) {
            cout << it.first << " " << it.second << " Students" << endl;
        }
    }

    void BSTMenu(){
        FileData fileData("students.txt");
        vector<Student> students = fileData.readData();
        BinarySearchTree bst;
        for (const auto& student : students) {
            bst.addStudent(student);
        }
        int subChoice;
        do {
            cout << "((BST Menu))" << endl;
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
                    bst.addStudent(student);
                    students.push_back(student);
                    fileData.setStudentVector(students);
                    cout << "Student added" << endl;
                    break;
                }
                case 2: {
                    int id;
                    cout << "Enter student ID to remove: ";
                    cin >> id;
                    bst.removeStudent(id);
                    for (auto it = students.begin(); it != students.end(); ++it) {
                        if (it->getID() == id) {
                            students.erase(it);
                            cout << "Student removed" << endl;
                            break;
                        }
                    }
                    fileData.setStudentVector(students);
                    break;
                }

                case 3: {
                    int id;

                    cout << "Enter student ID to search: ";
                    cin >> id;
                    bst.searchStudent(id);
                    break;
                }
                case 4: {
                    cout << "all students sorted by ID:" << endl;
                    bst.printAll();
                    cout << "students per department:" << endl;
                    bst.countStudentsPerDepartment();

                    break;
                }
                case 5:
                    break;
                default:
                    cout << "Invalid choice Please try again" << endl;
            }
        } while (subChoice != 5);
        fileData.setStudentVector(students);

    }

};
