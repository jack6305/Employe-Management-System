#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

void addEmployee() {
    Employee emp;
    ofstream file("employees.txt", ios::app);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }
    cout << "Enter ID: "; cin >> emp.id;
    cout << "Enter Name: "; cin.ignore(); getline(cin, emp.name);
    cout << "Enter Salary: "; cin >> emp.salary;
    file << emp.id << " " << emp.name << " " << emp.salary << endl;
    file.close();
    cout << "Employee Added Successfully!\n";
}

void displayEmployees() {
    ifstream file("employees.txt");
    if (!file) {
        cout << "Error opening file or no employees found!\n";
        return;
    }
    Employee emp;
    cout << "\nID    Name                 Salary\n";
    cout << "--------------------------------------\n";
    while (file >> emp.id >> ws, getline(file, emp.name, ' ') && file >> emp.salary) {
        cout << left << setw(6) << emp.id << setw(20) << emp.name << " " << fixed << setprecision(2) << emp.salary << "\n";
    }
    file.close();
}

void searchEmployee(int id) {
    ifstream file("employees.txt");
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }
    Employee emp;
    bool found = false;
    while (file >> emp.id >> ws, getline(file, emp.name, ' ') && file >> emp.salary) {
        if (emp.id == id) {
            cout << "\nEmployee Found:\n";
            cout << "ID: " << emp.id << "\nName: " << emp.name << "\nSalary: " << fixed << setprecision(2) << emp.salary << "\n";
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "Employee Not Found!\n";
}

void deleteEmployee(int id) {
    ifstream file("employees.txt");
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }
    ofstream temp("temp.txt");
    Employee emp;
    bool found = false;
    while (file >> emp.id >> ws, getline(file, emp.name, ' ') && file >> emp.salary) {
        if (emp.id != id) temp << emp.id << " " << emp.name << " " << emp.salary << endl;
        else found = true;
    }
    file.close(); temp.close();
    remove("employees.txt"); rename("temp.txt", "employees.txt");
    if (found) cout << "Employee Deleted Successfully!\n";
    else cout << "Employee Not Found!\n";
}

int main() {
    int choice, id;
    while (true) {
        cout << "\n===== Employee Management System =====\n";
        cout << "1. Add Employee\n2. Display Employees\n3. Search Employee\n4. Delete Employee\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: cout << "Enter ID to search: "; cin >> id; searchEmployee(id); break;
            case 4: cout << "Enter ID to delete: "; cin >> id; deleteEmployee(id); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid Choice! Please try again.\n";
        }
    }
}