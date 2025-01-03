#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
struct Node
{
    int id;
    string name;
    string status;
    string reason;
    int timeOff;
    Node *next;
};

class attendance_data_structure{
    public:
    int size;
    Node *front;
    Node *rear;
    int id;
    string name;
    string status;
    string reason;
    int timeOff;
    Node *next;


    attendance_data_structure(){
        size = 0;
        front = NULL;
        rear = NULL;
    }
    void load_data_from_employee_info(){
        fstream info_file;
        info_file.open("employee_info.csv", ios:: in);

        info_file.close();
    }
    void load_to_queue(){
        fstream attendence_file;
        string line;
        attendence_file.open("attendent.csv", ios::in);
        if (!attendence_file.is_open())
        {
            cout << "The file is unable to open" << endl;
            return;
        }
        else{
            getline(attendence_file,line);
            while (getline(attendence_file,line))
            {
                string need_conversion;
                stringstream seperate(line);
                getline(seperate, name, ',');
                getline(seperate, need_conversion,',');
                id = stoi(need_conversion);
                getline(seperate, reason);
                getline(seperate, need_conversion,',');
                getline(seperate, status,',');
                timeOff = stoi(need_conversion);
                Node *temp = new Node;
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
        attendence_file.close();
        }
    }
    
    Node *check_id_and_name(Node *front, int id, string name){
        
        Node *temp;
        temp = front;
        bool found = false;
        while (temp != NULL)
        {
            if (temp->id == id && temp->name == name)
            {
                found = true;
                string decision;
                int decision_number;
                cout << "ID: " << temp->id << ", Name: " << temp->name << endl; 
                cout << "Is this the name and ID that you want to add leave report for ?" << endl;
                cin >> decision;
                if (decision == "yes")
                {
                    return temp;
                }
                else if (decision == "no"){
                    cout << "1. check new name and id" << endl;
                    cout << "2. Exit the program" << endl;
                    cout << "Enter which option do you prefer: ";
                    cin >> decision_number;
                    if (decision_number == 1)
                    {
                        int new_id;
                        string new_name;
                        cout << "Enter new id: ";
                        cin >> id;
                        cout << "Enter new name: ";
                        cin >> name;
                        temp = front;
                        
                    }
                    else if(decision_number == 2){
                        break;
                    }
                    
                }
                
            }
            else {
                cout << "Invalid input" << endl;
            }
            temp = temp->next;
        }
        if (found == false)
        {
            cout << "ID and name is not found." << endl;
            return NULL;
        }
        
    }

    Node *simplified_check_id_and_name(int id, string name){

        return check_id_and_name(front, id, name);
    }

    void leave_report(int id, string name){
        
        Node *check_id_and_name_result = simplified_check_id_and_name(id, name);
        if(check_id_and_name_result != NULL){
            Node *new_node;
            new_node = new Node;
            cout << "Enter the status: " << endl;
            cin >> status;
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
            }
            else if(status == "absence"){
                new_node->status = status;
                new_node->reason = "unknown";
                new_node->timeOff = 1; 
            }
            else{
                cout << "Invalid status input." << endl;
            }
        }
        
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
    
    void display_report(){
        fstream info_file;
        info_file.open("attendent.csv", ios::out);
        Node *temp;
        temp = front;
        while (temp != NULL){
            cout << temp->name << "," 
                << temp->id << ","
                << temp->name << ","
                << temp->status << ","
                << temp->reason << ","
                << temp->timeOff << ","
                <<endl;
            info_file << temp->name << "," 
                << temp->id << ","
                << temp->name << ","
                << temp->status << ","
                << temp->reason << ","
                << temp->timeOff << ","
                <<endl;
            temp = temp->next;
        }
       info_file.close();
    }  
};