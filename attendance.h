#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
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
        attendence_file.close();
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
    
    // void display_report(){
    //     fstream info_file;
    //     info_file.open("attendent.csv", ios::out);
    //     Node *temp;
    //     temp = front;
    //     while (temp != NULL){
    //         cout << temp->name << "," 
    //             << temp->id << ","
    //             << temp->name << ","
    //             << temp->status << ","
    //             << temp->reason << ","
    //             << temp->timeOff << ","
    //             <<endl;
    //         info_file << temp->name << "," 
    //             << temp->id << ","
    //             << temp->name << ","
    //             << temp->status << ","
    //             << temp->reason << ","
    //             << temp->timeOff << ","
    //             <<endl;
    //         temp = temp->next;
    //     }
    //    info_file.close();
    // }  
};