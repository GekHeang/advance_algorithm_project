#include<iostream>
#include "header.h"
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


int main(){
    int function_number;
    fstream info_file;
    while (function_number != 0)
    {
        info_file.open("employee_info.csv", ios:: app);
        cout << "Available functions in this program" << endl;
        cout << "1. Add new employee's information"<< endl;
        cout << "2. Delete employee's information" << endl;
        cout << "3. Update employee's information" << endl;
        cout << "4. Search function" << endl;
        cout << "5. Display employees who is going to retire in the future" << endl;
        cout << "6. Search for employees hire duration" << endl;
        cout << "7. Amount of total employees" << endl;
        cout << "Enter the function's number that you want to use: ";
        cin >> function_number;
        employees_data_structure *employee = new employees_data_structure;

        if (function_number == 1)
        {
            employee->add_new_employee_info();
            employee->display();
            info_file.close();
        }

        if(function_number == 2){
            info_file.open("employee_info.csv", ios:: in);
            if (!info_file.is_open())
            {
                cout << "The file is unable to open" << endl;
                return -1;
            }
            
            employee->read_data_from_file_and_load_to_queue();
            employee->delete_employee_info();
            cout << "Deletion is successful" << endl;
            fstream deleted_file;
            deleted_file.open("deleted.csv", ios::out);
            if (!deleted_file.is_open())
            {
                cout << "File is unable to open" << endl;
            }
            else{
            
            employee->write_data_into_file();
            }
        }

        if(function_number == 3){
            employee->read_data_from_file_and_load_to_queue();
            int id = 0;
            string property;
            string new_data;
            cout << "Enter the ID that you want to update the information: ";
            cin >> id;
            cout << "Enter the categories that you want to change: ";
            cin >> property;
            cout << "Enter new data: ";
            cin.ignore();
            getline(cin, new_data);
            employee->update_information(id, property, new_data);
        }

        if (function_number == 4){
            string category;
            string searched_data;
            cout << "Enter the category that you want to search: ";
            cin.ignore();
            getline(cin,category);

            cout << "Enter the data you want to search: ";
            
            getline(cin, searched_data);
            employee->search(category, searched_data);
        }
        
        if (function_number == 5)
        {
            int option_number;
            int year;
            int amount_of_year;
            cout << "There are 2 methods for checking employees who is going to retire in the future" << endl;
            cout << "1. Enter the year you would like to check." << endl;
            cout << "2. Enter the number of years to check for upcoming retirements." << endl;
            cout << "Enter the option that you prefer: ";
            cin >> option_number;
            employee->check_for_future_retire(option_number);
        }
        
        if (function_number == 6){
            int year;
            do
            {
                cout << "search function for hire duration year limit is from 1 until 40." << endl;
                cout << "Enter the employing year that you want to check: ";
                cin >> year;
            } while (year < 1 || year > 40);
            
            employee->check_employees_hire_duration(year);
            
        }
        if (function_number == 7)
        {
            cout << "Total Employees in the company is: " << employee->display_size() << endl;
        }
        
    }
    
    
    return 0;
}