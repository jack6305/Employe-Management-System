Employee Management System

Overview

The Employee Management System is a simple console-based application written in C++. 
It provides functionalities to manage employee records efficiently, including adding, displaying, searching, and deleting employee information stored in a file.
The system uses a menu-driven interface to allow easy interaction with the user.

Features

- Add Employee: Enter and save employee details (ID, Name, Salary) to a file.
- Display Employees: Retrieve and display all stored employee records in a formatted table.
- Search Employee: Look up an employee's details using their ID.
- Delete Employee: Remove an employee's record from the system permanently.
- File Handling: All data is stored in `employees.txt` for persistence.
- Error Handling: Ensures smooth operation with file existence checks and user-friendly prompts.

Technologies Used

- Programming Language: C++
- File Handling: Uses text file (`employees.txt`) for data storage.
- Standard Libraries: `<iostream>`, `<fstream>`, `<vector>`, `<iomanip>`


Prerequisites

- A C++ compiler (GCC, Clang, MSVC, etc.)
- A terminal or command prompt


Usage

1. Upon running, the system displays a menu with options:
   - `1` to Add Employee
   - `2` to Display Employees
   - `3` to Search Employee
   - `4` to Delete Employee
   - `5` to Exit

Future Enhancements

- Implement database integration (SQLite, MySQL) for better scalability.
- Add user authentication for secured access.
- Enhance UI with a graphical interface.

## License

This project is open-source and available under the **MIT License**.





