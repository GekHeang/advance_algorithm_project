#include<iostream>
#include "header.h"
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


int data_size(){
    fstream read_from_file;
    string line;
    int data_size = 0;
    read_from_file.open("employee_info.csv", ios:: in);
    if (read_from_file.is_open())
    {
        cout << "The file is open successfully" << endl;
        getline(read_from_file, line);
        while (getline(read_from_file, line))
        {
            data_size++;
        }
        read_from_file.close();  
        return data_size;
    }
    else{
        cout << "Unable to open the file" << endl;
    }
}
int main(){
    int function_number;
    fstream info_file;
    while (function_number != 0)
    {
        
        info_file.open("employee_info.csv", ios:: app);
        cout << "Available functions in this program" << endl;
        cout << "1. Add new employee's information"<< endl;
        cout << "2. Detele employee's information" << endl;
        cout << "3. Update employee's information" << endl;
        cout << "4. Search function" << endl;
        cout << "5. Display employees who is going to retired from next year until next 5 year" << endl;
        cout << "6. Test id_is_found" << endl;
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
            cout << "Enter the property that you want to change: ";
            cin >> property;
            cout << "Enter new data: ";
            cin.ignore();
            getline(cin, new_data);
            employee->update_information(id, property, new_data);
        }

        if (function_number == 4){
            
        }

        if (function_number == 6){
            int id;
            employee->read_data_from_file_and_load_to_queue();
            cout << "Enter the id that you want to search:";
            cin >> id;
            employee->id_is_found(id);
            if (employee->id_is_found(id) == true)
            {
                cout << "id is found" << endl;
            }
            else{
                cout << "id is not found" << endl;
            }
            
            
        }
        
    }
    
    
    return 0;
}