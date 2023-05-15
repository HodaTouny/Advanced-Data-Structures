#include <bits/stdc++.h>
#include "FileData.h"
#include "Student.h"
using namespace std;

class Node {
public:
    Student student;
    Node* left;
    Node* right;
    int height;
    Node(Student student) {
        this->student = student;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVL {
private:
    Node* root;
    int height(Node* root){
        if (root == NULL) {
            return 0;
        }
        return root->height;
    }
    int max(int a, int b){
        return (a > b) ? a : b;
    }
    int getBalance(Node* root){
        if (root == NULL) {
            return 0;
        }
        return height(root->left) - height(root->right);
    }
    Node* rightRotate(Node* root){
        Node* left = root->left;
        Node* leftRight = left->right;
        left->right = root;
        root->left = leftRight;
        root->height = max(height(root->left), height(root->right)) + 1;
        left->height = max(height(left->left), height(left->right)) + 1;
        return left;
    }
    Node* leftRotate(Node* root){
        Node* right = root->right;
        Node* rightLeft = right->left;
        right->left = root;
        root->right = rightLeft;
        root->height = max(height(root->left), height(root->right)) + 1;
        right->height = max(height(right->left), height(right->right)) + 1;
        return right;
    }
    Node* addStudent(Node* root, Student student){
        if (root == NULL) {
            return new Node(student);
        }
        if (student < root->student) {
            root->left = addStudent(root->left, student);
        }
        else if (student > root->student) {
            root->right = addStudent(root->right, student);
        }
        else {
            return root;
        }
        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);
        if (balance > 1 && student < root->left->student) {
            return rightRotate(root);
        }
        if (balance < -1 && student > root->right->student) {
            return leftRotate(root);
        }
        if (balance > 1 && student > root->left->student) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        //right left case
        if (balance < -1 && student < root->right->student) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    Node* removeStudent(Node* root, int id){
        //if student id is less than root id, remove from left subtree
        if (id < root->student.getID()) {
            root->left = removeStudent(root->left, id);
        }
        else if (id > root->student.getID()) {
            root->right = removeStudent(root->right, id);
        }
        else {
            if (root->left == NULL || root->right == NULL) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                }
                else {
                    *root = *temp;
                }
                delete temp;
            }
            else {
                Node* temp = root->right;
                while (temp->left != NULL) {
                    temp = temp->left;
                }
                root->student = temp->student;
                root->right = removeStudent(root->right, temp->student.getID());
            }
        }
        if (root == NULL) {
            return root;
        }
        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    Node* searchStudent(Node* root, int id){
        if (root == NULL || root->student.getID() == id) {
            return root;
        }
        if (root->student.getID() > id) {
            return searchStudent(root->left, id);
        }
        return searchStudent(root->right, id);
    }
    void printAll(Node* root){
        if (root != NULL) {
            printAll(root->left);
            cout << root->student.getID() << ", " << root->student.getName() << ", " << root->student.getGPA() << ", "
                 << root->student.getDepartment() << endl;
            printAll(root->right);
        }
    }
    void countStudentsPerDepartment(Node* root, map<string, int>& departmentCounts){
        if (root != NULL) {
            countStudentsPerDepartment(root->left, departmentCounts);
            departmentCounts[root->student.getDepartment()]++;
            countStudentsPerDepartment(root->right, departmentCounts);
        }
    }

public:
    AVL(){
        root = NULL;
    }
    void addStudent(Student student) {
        root = addStudent(root, student);
    }

    void removeStudent(int id) {
        Node *result = searchStudent(root, id);
        if (result != nullptr) {
            root = removeStudent(root, id);
        } else {
            cout << "Student not found." << endl;
        }
    }

    void searchStudent(int id) {
        Node *result = searchStudent(root, id);
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
};

