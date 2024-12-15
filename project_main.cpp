#include<iostream>
#include "header.h"
#include<fstream>
using namespace std;
int main(){
    int function_number;
    fstream info_file;
    info_file.open("employee_info.csv", ios:: app);
    cout << "Available functions in this program" << endl;
    cout << "1. Add new employee's information"<< endl;
    cout << "2. Detele employee's information" << endl;
    cout << "3. Update employee's information" << endl;
    cout << "Enter the function's number that you want to use: ";
    cin >> function_number;

    if (function_number == 1)
    {
        employees_data_structure *employee = new employees_data_structure;
        employee->add_new_employee_info();
        
        
        info_file << "name, id, position, hire_date, gender, age, salary, contact_info, address, date_of_birth, national_id, status" <<endl;
        employee->display();
    }
    info_file.close();
    return 0;
}