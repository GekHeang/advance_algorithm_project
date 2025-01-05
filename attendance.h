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
    string date;
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
    string date;
    Attendance_node *next;


    attendance_data_structure(){
        size = 0;
        front = NULL;
        rear = NULL;
    }
    
    void load_to_queue(){
        fstream read_file;
        read_file.open("attendance.csv", ios::in);
        if (read_file.is_open())
        {
            
            string line;
            string need_conversion;
            getline(read_file, line);
            while (getline(read_file, line))
            {
                Attendance_node *temp = new Attendance_node;
                stringstream seperate(line);
                string need_conversion;
                getline(seperate, name, ',');
                temp->name = name;
                getline(seperate, need_conversion, ',');
                id = stoi(need_conversion);
                temp->id = id;
                getline(seperate, status, ',');
                temp->status = status;
                getline(seperate, reason, ',');
                temp->reason = reason;
                getline(seperate,need_conversion,',');
                timeOff = stoi(need_conversion);
                temp->timeOff = timeOff;
                getline(seperate, date, ',');
                temp->date = date;
                temp->next = NULL;
                if (front == NULL)
                {
                    front = temp;
                    rear = temp;
                }
                else{
                    rear->next =temp;
                    rear = temp;
                }
                size++;
                
            }
            
            cout << "Load data to file successfully" << endl;   
            read_file.close();
            
        }
        
    }

    string today_date(){
        time_t now = time(0);
        tm* local_time = localtime(&now);
        int year = 1900 + local_time->tm_year;
        int today = local_time->tm_mday;
        int month = 1 + local_time->tm_mon;

        return to_string(today) + "/" + to_string(month) + "/" + to_string(year);
    }
    void leave_report(int id, string name, string status){ 
        Attendance_node *new_node;
        new_node = new Attendance_node;
        new_node->name = name;
        new_node->id = id;
        new_node->date = today_date();
        new_node->status = status;
        if (status == "permission")
        {
            cout << "Enter the reason: ";
            cin.ignore();
            getline(cin, reason);
            new_node->reason = reason;
            cout << "Enter the time off: ";
            cin >> timeOff;
            new_node->timeOff = timeOff;
            cout << "name\tid\tstatus\treason\ttimeoff\tdate" << endl;
            display_data_in_node(new_node);
            size++; 

            if (front == NULL) {
                front = new_node;
                rear = new_node;
            } else {
                rear->next = new_node;
                rear = new_node;
            }

            write_data_to_file(new_node);
            
            
        }
        else if(status == "absence"){
            new_node->reason = "unknown";
            new_node->timeOff = 1; 
            cout << "name\tid\tstatus\treason\ttimeoff" << endl; 
            display_data_in_node(new_node);
            size++; 

            if (front == NULL) {
                front = new_node;
                rear = new_node;
            } else {
                rear->next = new_node;
                rear = new_node;
            }

            write_data_to_file(new_node);
        }
        else{
            cout << "Invalid status input." << endl;
        }

        
    }

    void display_data_in_node(Attendance_node *temp){
        cout <<temp->name<< "," 
             <<temp->id << ","
             <<temp->status << ","
             <<temp->reason << ","
             <<temp->timeOff <<"," 
             <<temp->date << ","
             <<endl;
    }
    void write_data_to_file(Attendance_node *temp){
        fstream write_to_file;
        write_to_file.open("attendance.csv", ios::app);
        write_to_file << temp->name << ","
                      << temp->id << ","
                      << temp->status << ","
                      << temp->reason << ","
                      << temp->timeOff << ","
                      << temp->date
                      <<endl;

        write_to_file.close();
    }

    void display_attendance_report(){
        load_to_queue();
        Attendance_node *temp;
        temp = front;
        while(temp != NULL){
            display_data_in_node(temp);
            temp = temp->next;
        }
        
    }

};