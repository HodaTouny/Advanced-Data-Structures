#include <bits/stdc++.h>
#include "FileData.h"
#include "Student.h"

using namespace std;

class minHeap{
    private:
        vector<Student> heap;
        FileData Data{"students.txt"};
        int size = 0;

    public:
        minHeap(){
            this->heap = Data.readData();
            this->size = Data.getStudentsNum();
            heapify();
        }
        int parentIndex(int child){ return (child - 1) / 2; }
        int leftChildIndex(int parent){ return (2 * parent) + 1; }
        int rightChildIndex(int parent){ return (2 * parent) + 2; }

        void swap(int SOIndex, int STIndex) {
            Student tmp = heap[SOIndex];
            heap[SOIndex] = heap[STIndex];
            heap[STIndex] = tmp;
        }

        void heapifyDown(int parent) {
            int LChild = leftChildIndex(parent);
            int RChild = rightChildIndex(parent);
            int PARENTOLD = parent;
            if (LChild < size && heap[LChild].getGPA() < heap[parent].getGPA()) {
                parent  = LChild;
            }
            if (RChild < size && heap[RChild].getGPA() < heap[parent].getGPA()) {
                parent  = RChild;
            }
            if (parent  != PARENTOLD) {
                swap(parent , PARENTOLD);
                heapifyDown(parent);
            }
        }

        void heapify() {
            for (int i = parentIndex(size); i >= 0; i--) {
                heapifyDown(i);
            }
        }

        void printAllStudents(){
            for(int i=0;i<size;i++){
                cout<<heap[i].getID() <<" "<<heap[i].getName()<<" "<<heap[i].getGPA()<<" "<<heap[i].getDepartment()<<"\n";
            }
        }

        void addStudent(Student stud){
            heap.push_back(stud);
            size++;
            heapify();
            Data.setStudentsNum(size);
            Data.setStudentVector(heap);
            Data.writeData();
        }

};


int main() {
    minHeap heap;
    int choice = 0;
    int id=0; float gpa = 0;string name="",department="";
    bool isvalid = true;
    do{
        cout<<"1 : Add Student\n2 : Print All Students Sorted By GPA\n3 : exit";
        cin>>choice; cout<<"\n";
        if(choice == 1){
            cout<<"Enter Student ID : "; cin>>id;cout<<"\n";
            cout<<"Enter Student Name : "; getline(cin, name);cout<<"\n";
            cout<<"Enter Student GPA : "; cin>>gpa;cout<<"\n";
            cout<<"Enter Student Department : ";cin>>department;cout<<"\n";
            Student stud = Student(id,name,gpa,department);
            heap.addStudent(stud);
        }else if(choice==2){
            heap.printAllStudents();
        }else if(choice == 3){
            return 0;
        }
        else{
            isvalid = false;
        }

    } while (isvalid);

    return 0;
}
