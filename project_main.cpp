#include<iostream>
#include<header.h>
using namespace std;
int main(){
    employees_data_structure *employee_1 = new employees_data_structure;
    employee_1->add_new_employee_info("Sarah Johnson", 10123, "Software Engineer", "2020-08-15", "Female", 29, 75000.50, "+1-555-789-1234", "123 Elm Street, Springfield, IL, USA", "1995-04-22", 9876543210123, "Active"
);
    employee_1->display();
    return 0;
}