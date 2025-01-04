#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include "header.h"
using namespace std;
struct Attendance_node
{
    int id;
    string name;
    string status;
    string reason;
    int timeOff;
    Attendance_node *next;
};

class attendance_data_structure{
    public:
    int size;
    Attendance_node *front;
    Attendance_node *rear;
    int id;
    string name;
    string status;
    string reason;
    int timeOff;
    Attendance_node *next;


    attendance_data_structure(){
        size = 0;
        front = NULL;
        rear = NULL;
    }
    void load_data_from_employee_info(){
        fstream info_file;
        string line;
        string need_conversion;
        string temp;
        info_file.open("employee_info.csv", ios:: in);
        getline(info_file, line);
        while(getline(info_file, line)){
            stringstream seperate(line);
            getline(seperate, name,',');
            getline(seperate, need_conversion, ',');
            id = stoi(need_conversion);

            while (getline(seperate, temp, ','))
            {
                
            }

            Attendance_node *temp;
            temp = new Attendance_node;
            temp->name = name;
            temp->id = id;
            temp->next = NULL;
            if (front == NULL)
            {
                front = temp;
                rear = temp;
            }
            else{
                rear->next = temp;
                rear = temp;
            }
            size++;
            
        }
        info_file.close();
    }
    void load_to_queue(){
        fstream attendance_file;
        string line;
        attendance_file.open("attendance.csv", ios::in);
        if (!attendance_file.is_open())
        {
            cout << "The file is unable to open" << endl;
            return;
        }
        else{
            getline(attendance_file,line);
            while (getline(attendance_file,line))
            {
                string need_conversion;
                stringstream seperate(line);
                getline(seperate, name, ',');
                getline(seperate, need_conversion,',');
                id = stoi(need_conversion);
                getline(seperate, status,',');
                getline(seperate, reason);
                getline(seperate, need_conversion,',');
                timeOff = stoi(need_conversion);
                Attendance_node *temp = new Attendance_node;
                temp->name = name;
                temp->id = id;
                temp->status = status;
                temp->next = NULL;
                if (front == NULL)
                {
                    front = temp;
                    rear = temp;
                }
                else{
                    rear->next = temp;
                    rear = temp;
                }
                size++;
            }
        cout << "Load data from file successfully"<< endl;
        attendance_file.close();
        }
    }


    void leave_report(int id, string name, string status){
        Attendance_node *new_node;
        new_node = new Attendance_node;
        new_node->name = name;
        new_node->id = id;
        if (status == "permission")
        {
            new_node->status = status;
            cout << "Enter the reason: ";
            cin.ignore();
            getline(cin, reason);
            new_node->reason = reason;
            cout << "Enter the time off: ";
            cin >> timeOff;
            new_node->timeOff = timeOff;
            cout << "name\tid\tstatus\treason\ttimeoff" << endl; 
            display_data_in_node(new_node);
            write_data_to_file(new_node);
        }
        else if(status == "absence"){
            new_node->status = status;
            new_node->reason = "unknown";
            new_node->timeOff = 1;
            cout << "name\tid\tstatus\treason\ttimeoff"; 
            display_data_in_node(new_node);
            write_data_to_file(new_node);
        }
        else{
            cout << "Invalid status input." << endl;
        }
        
    }

    void display_data_in_node(Attendance_node *temp){
        cout << temp->name<< " " << temp->id << "\t"<< temp->status << " "<< temp->reason << " "<< temp->timeOff << endl;
    }

    void write_data_to_file(Attendance_node *temp){
        fstream attendance_file;
        attendance_file.open("attendace.csv", ios:: app);
        attendance_file<< temp->name<< "," << temp->id << ","<< temp->status << ","<< temp->reason << ","<< temp->timeOff << endl;
        
        attendance_file.close();
    }
    // det
    bool leaveReport(int id, string name, string status, string reason, int timeOff){
    cout<<"Enter information for Leave Report.\n";
    while(1){
            if(status == "true") // mean permission
            {
                cout<<"Have permission.\n";
                cout<<"Enter ID: "<<endl;
                cin>>id;
                cout<<"Enter name: "<<endl;
                cin>>name;
                cout<<"Tell the reason: "<<endl;
                cin>>reason;
                cout<<"Duration: "<<endl;
                cin>>timeOff;
            }
            else
            {
                cout<<"Absence"<<endl;
            }
        }   
    }
    
    Attendance_node *check_attendance_id(Attendance_node *front, int id){
        Attendance_node *temp;
        temp = front;
        bool found = false;
        while(temp != NULL){
            if (temp->id == id)
            {
                found = true;
                return temp;
            }
            else{
                temp = temp->next;
            }
        }
        if (found == false)
        {
            cout << "ID is not found in the system." << endl;
            return NULL;
        }
    }
    Attendance_node *check_if_id_exist(int id){
        return check_attendance_id(front, id);
    }
    
    void write_data_to_attendance_file(){
        Attendance_node *temp;
        temp = front;
        fstream attendance_file;
        attendance_file.open("attendance.csv", ios::out);
        if (!attendance_file.is_open())
        {
            cout << "file is unable to open." << endl;
        }
        else{
            cout << "name,id,status,reason,time_off" << endl;
            while (temp != NULL)
            {
                attendance_file << temp->name << "," << temp->id << "," << temp->status << "," << temp->reason << "," << temp->timeOff << "," << endl;
                temp = temp->next;
            }
            
        }
        attendance_file.close();
    }

    void update_leave_report(int id, string category, string new_value){
        int need_conversion;
        Attendance_node *temp = check_if_id_exist(id);
        if(temp != NULL){
            if (category == "name")
            {
                temp->name = new_value;
            }
            else if (category == "id")
            {
                need_conversion = stoi(new_value);
                temp->id = need_conversion;
            }
            else if(category == "status"){
                temp->status = new_value;
            }
            else if(category == "reason"){
                temp->reason = new_value;
            }
            else if(category == "time off"){
                need_conversion = stoi(new_value);
                temp->timeOff = need_conversion;
            }
            else{
                cout << "Invalid category" << endl;
            }
            write_data_to_attendance_file();
        }
    }
 
    void search_attendance_function(string category, string searched_value){
        load_to_queue();
        Attendance_node *temp;
        temp = front;
        bool found = false;
        if (category == "name")
        {
            int total_time_off = 0;
            while (temp != NULL)
            {
                if (searched_value == temp->name)
                {
                   display_data_in_node(temp);
                   found = true;
                   total_time_off += temp->timeOff;
                }
                else{
                    temp = temp->next;
                }
                cout << "total time off of this employee: " << total_time_off << " day" << endl;
            }
            if (found == false)
            {
                cout << "No data is found" << endl;
            }
        }
        else if (category == "id")
        {
            int need_conversion;
            need_conversion = stoi(searched_value);
            while (temp != NULL)
            {
                if (need_conversion == temp->id)
                {
                   display_data_in_node(temp);
                   found = true;
                }
                else{
                    temp = temp->next;
                }
            }
            if (found == false)
            {
                cout << "No data is found" << endl;
            }
        }
        else if (category == "status")
        {
            while (temp != NULL)
            {
                if (searched_value == temp->status)
                {
                   display_data_in_node(temp);
                   found = true;
                }
                else{
                    temp = temp->next;
                }
            }
            if (found == false)
            {
                cout << "No data is found" << endl;
            }
        }
        
        
    }
};