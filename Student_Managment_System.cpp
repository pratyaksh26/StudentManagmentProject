#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string department;

    Student(int id, string name, int age, string department) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->department = department;
    }
};

class StudentManagement {
private:
    vector<Student> students;
public:
    void addStudent(int id, string name, int age, string department) {
        students.push_back(Student(id, name, age, department));
        cout << "Student added successfully!" << endl;
    }

    void displayStudents() {
        cout << "\n--- Student List ---" << endl;
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Age" << "Department" << endl;
        for (const auto& student : students) {
            cout << left << setw(10) << student.id << setw(20) << student.name << setw(10) << student.age << student.department << endl;
        }
    }

    void searchStudent(int id) {
        for (const auto& student : students) {
            if (student.id == id) {
                cout << "Student Found: " << student.name << " | Age: " << student.age << " | Department: " << student.department << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found!" << endl;
    }

    void deleteStudent(int id) {
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                students.erase(students.begin() + i);
                cout << "Student with ID " << id << " deleted successfully!" << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found!" << endl;
    }
};

int main() {
    StudentManagement sm;
    int choice, id, age;
    string name, department;

    while (true) {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student\n2. Display Students\n3. Search Student\n4. Delete Student\n5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter ID: "; cin >> id;
                cout << "Enter Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Age: "; cin >> age;
                cout << "Enter Department: "; cin.ignore(); getline(cin, department);
                sm.addStudent(id, name, age, department);
                break;
            case 2:
                sm.displayStudents();
                break;
            case 3:
                cout << "Enter ID to search: "; cin >> id;
                sm.searchStudent(id);
                break;
            case 4:
                cout << "Enter ID to delete: "; cin >> id;
                sm.deleteStudent(id);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, try again!" << endl;
        }
    }
}