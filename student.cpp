#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    int marks[5];
    int totalMarks;
    float averageMarks;

public:
    void inputDetails(int index) {
        cout << "\n--- Enter Details for Student " << index << " ---" << endl;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        
        cout << "Enter Marks for 5 Subjects: " << endl;
        for (int i = 0; i < 5; i++) {
            cout << "  Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
        
        calculateTotalAndAverage();
    }

    void calculateTotalAndAverage() {
        totalMarks = 0;
        for (int i = 0; i < 5; i++) {
            totalMarks += marks[i];
        }
        averageMarks = totalMarks / 5.0;
    }

    void displayDetails() const {
        cout << "\n---------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nTotal Marks: " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
    }

    int getTotalMarks() const {
        return totalMarks;
    }
};

int main() {
    Student students[5];

    for (int i = 0; i < 5; i++) {
        students[i].inputDetails(i + 1);
    }

    cout << "\n================================" << endl;
    cout << "     ALL STUDENT DETAILS" << endl;
    cout << "================================" << endl;
    for (int i = 0; i < 5; i++) {
        students[i].displayDetails();
    }

    int highestIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (students[i].getTotalMarks() > students[highestIndex].getTotalMarks()) {
            highestIndex = i;
        }
    }

    cout << "\n================================" << endl;
    cout << "   STUDENT WITH HIGHEST MARKS" << endl;
    cout << "================================" << endl;
    students[highestIndex].displayDetails();

    return 0;
}
