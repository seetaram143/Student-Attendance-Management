#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;

    void addStudent() {
        ofstream file("students.txt", ios::app);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;

        file << id << " " << name << endl;
        file.close();
    }

    void displayStudents() {
        ifstream file("students.txt");
        while (file >> id >> name) {
            cout << "ID: " << id << " Name: " << name << endl;
        }
        file.close();
    }
};

void markAttendance() {
    ofstream file("attendance.txt", ios::app);
    int id;
    char status;

    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Attendance (P/A): ";
    cin >> status;

    file << id << " " << status << endl;
    file.close();
}

void viewAttendance() {
    ifstream file("attendance.txt");
    int id;
    char status;

    while (file >> id >> status) {
        cout << "ID: " << id << " Status: " << status << endl;
    }
    file.close();
}

int main() {
    Student s;
    int choice;

    do {
        cout << "\n1. Add Student\n2. Display Students\n3. Mark Attendance\n4. View Attendance\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: s.addStudent(); break;
            case 2: s.displayStudents(); break;
            case 3: markAttendance(); break;
            case 4: viewAttendance(); break;
        }
    } while (choice != 5);

    return 0;
}