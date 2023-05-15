#include <bits/stdc++.h>
#include "FileData.cpp"
#include "Student.cpp"
#include "AVL.cpp"
#include "BST.cpp"
#include "MinHeap.cpp"
#include "MaxHeap.cpp"
using namespace std;

int main() {
    maxHeap heapObj;
    minHeap heapObject;
    BinarySearchTree bst;
    AVL avl;

    int choice;
    do {
        cout << "((Main menu))" << endl;
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
                bst.BSTMenu();
                break;
            case 2: {
                avl.AVLMenu();

                break;
            }
            case 3:
                heapObject.Heap();
                break;
            case 4:
                heapObj.Heap();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
