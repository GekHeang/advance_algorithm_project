#include<fstream>
#include<sstream>
#include<string>
using namespace std;
struct Node{
    string name;
    int id;
    string position;
    string hire_date;
    string gender;
    int age;
    float salary;
    string contact_info;
    string address;
    string date_of_birth;
    string national_id;
    string status;
    Node *next;
};

class employees_data_structure
{
    public:
    int size;
    Node *front;
    Node *rear;
    string name;
    int id;
    string position;
    string hire_date;
    string gender;
    int age;
    float salary;
    string contact_info;
    string address;
    string date_of_birth;
    string national_id;
    string status;
    Node *next;

    employees_data_structure(){
        size = 0;
        front = NULL;
        rear = NULL;
    }

    void add_new_employee_info(){
        Node *new_node;
        new_node = new Node;
        cout << "Fill the employee information below." << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        new_node->name = name;
        cout << "Id: ";
        cin >> id;
        new_node->id = id;
        cout << "Position: ";
        getline(cin, position);
        new_node->position = position;
        cout << "Hire date: ";
        cin >> hire_date;
        new_node->hire_date = hire_date;
        cout << "Gender: ";
        cin >> gender;
        new_node->gender = gender;
        cout << "Age: ";
        cin >> age;
        new_node->age = age;
        cout << "Salary: ";
        cin >> salary;
        new_node->salary = salary;
        cout << "Contact_info: ";
        getline(cin, contact_info);
        new_node->contact_info = contact_info;
        cout << "Address: ";
        getline(cin, address);
        new_node->address = address;
        cout << "date_of_birth: ";
        getline(cin, date_of_birth);
        new_node->date_of_birth = date_of_birth;
        cout << "national_id: ";
        getline(cin, national_id);
        new_node->national_id = national_id;
        cout << "status: ";
        cin >> status;
        new_node->status = status;
        new_node->next = NULL;
        if (front == NULL)
        {
            front = new_node;
            rear = new_node;
        }
        else{
            rear->next = new_node;
            rear = new_node;
        }
        size++;
    }

    void delete_employee_info(){
        if (size == 0)
        {
            cout << "Data structure is empty. cannot delete" << endl;
        }
        else{
            Node *temp;
            temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }        

    void display(){
        fstream info_file;
        info_file.open("employee_info.csv", ios::out);
        Node *temp;
        temp = front;
        while (temp != NULL)
        {
            cout << temp->name << "," 
                << temp->id << ","
                << temp->position << ","
                << temp->hire_date << ","
                << temp->gender << ","
                << temp->age << ","
                << temp->salary << ","
                << temp->contact_info << ","
                << temp->address << ","
                << temp->date_of_birth << ","
                << temp->national_id << ","
                << temp->status << ","
                <<endl;
            info_file << temp->name << "," 
                << temp->id << ","
                << temp->position << ","
                << temp->hire_date << ","
                << temp->gender << ","
                << temp->age << ","
                << temp->salary << ","
                << temp->contact_info << ","
                << temp->address << ","
                << temp->date_of_birth << ","
                << temp->national_id << ","
                << temp->status << ","
                <<endl;
            temp = temp->next;
        }
        info_file.close();
    }

    void write_data_into_file(){
        fstream info_file;
        info_file.open("employee_info.csv", ios::out);
        fstream deleted_file;
        deleted_file.open("deleted.csv", ios::out);
        fstream update_file;
        update_file.open("update_file.csv", ios::out);
        Node *temp;
        temp = front;
        deleted_file << "name, id, position, hire_date, gender, age, salary, contact_info, address, date_of_birth, national_id, status"<< endl;
        info_file << "name, id, position, hire_date, gender, age, salary, contact_info, address, date_of_birth, national_id, status"<< endl;
        while (temp != NULL)
        {
            deleted_file << temp->name << "," 
                << temp->id << ","
                << temp->position << ","
                << temp->hire_date << ","
                << temp->gender << ","
                << temp->age << ","
                << temp->salary << ","
                << temp->contact_info << ","
                << temp->address << ","
                << temp->date_of_birth << ","
                << temp->national_id << ","
                << temp->status << ","
                <<endl;

            info_file << temp->name << "," 
                << temp->id << ","
                << temp->position << ","
                << temp->hire_date << ","
                << temp->gender << ","
                << temp->age << ","
                << temp->salary << ","
                << temp->contact_info << ","
                << temp->address << ","
                << temp->date_of_birth << ","
                << temp->national_id << ","
                << temp->status << ","
                <<endl;
            update_file << temp->name << "," 
                << temp->id << ","
                << temp->position << ","
                << temp->hire_date << ","
                << temp->gender << ","
                << temp->age << ","
                << temp->salary << ","
                << temp->contact_info << ","
                << temp->address << ","
                << temp->date_of_birth << ","
                << temp->national_id << ","
                << temp->status << ","
                <<endl;
            temp = temp->next;
        }
        info_file.close();
        deleted_file.close();
    }
    int display_size(){
        return size;
    }

    void read_data_from_file_and_load_to_queue(){
        fstream info_file;
        string line;
        info_file.open("employee_info.csv", ios::in);
        if (!info_file.is_open()){
            cout << "The file is unable to open" << endl;
            return;
        }
        else{
            getline(info_file,line);
            while (getline(info_file,line))
            {
                string need_conversion;
                stringstream seperate(line);
                getline(seperate, name, ',');
                getline(seperate, need_conversion,',');
                id = stoi(need_conversion);
                getline(seperate, position,',');
                getline(seperate, hire_date,',');
                getline(seperate, gender,',');
                getline(seperate, need_conversion,',');
                age = stoi(need_conversion);
                getline(seperate, need_conversion,',');
                salary = stof(need_conversion);
                getline(seperate, contact_info,',');
                getline(seperate, address,',');
                getline(seperate, date_of_birth,',');
                getline(seperate, national_id,',');
                getline(seperate, status,',');
                Node *temp = new Node;
                temp->name = name;
                temp->id = id;
                temp->position = position;
                temp->hire_date = hire_date;
                temp->gender = gender;
                temp->age = age;
                temp->salary = salary;
                temp->contact_info = contact_info;
                temp->address = address;
                temp->date_of_birth = date_of_birth;
                temp->national_id = national_id;
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
        }
        info_file.close();
    }

    bool check_if_id_exist_(Node *front, int searched_id){
       if (front != NULL)
       {
            if (searched_id == front->id)
            {
                return true;
            }
            else{
                return check_if_id_exist_(front->next, searched_id);
            }
       }
        return false;
    }
    bool id_is_found(int id){
        return check_if_id_exist_(front, id);
    }

    Node *id_(Node *front, int id){
        Node *temp;
        temp = front;
        if (temp->id = id)
        {
            return temp;
        }
        else{
            temp = temp->next;
        }
        cout << "The ID is not exist" << endl;
        return NULL;
    }
    Node *id_for_update_function(int id){
        return id_(front, id);
    }

    void update_information(int id, string property, string new_value){
        Node *temp;
        temp = id_for_update_function(id);
        if (temp != NULL)
        {
            if (property == "name")
            {
                temp->name = new_value; 
            }
            else if (property == "position"){
                temp->position == new_value;
            }
            else if(property == "id"){
                temp->id = stoi(new_value);                
            }
            else if(property == "hire_date"){
                temp->hire_date = new_value;
            }
            else if(property == "gender"){
                temp->gender = new_value;
            }
            else if(property == "age"){
                temp->age = stoi(new_value);
            }    
            else if(property == "salary"){
                temp->salary = stof(new_value);
            }
            else if(property == "address"){
                temp->address = new_value;
            }
            else if(property == "date_of_birth"){
                temp->date_of_birth = new_value;
            }
            else if(property == "national_id"){
                temp->national_id = new_value;
            }
            else if(property == "status"){
                temp->status = new_value;
            }
            fstream update_file;
            update_file.open("update_file.csv", ios::out);
            if (update_file.is_open())
            {
                // update_file << temp->name << "," << temp->id << "," << temp->position << ","
                //             << temp->hire_date << "," << temp->gender << "," << temp->age << ","
                //             << temp->salary << "," << temp->contact_info << "," 
                //             << temp->address << "," << temp->date_of_birth << "," 
                //             <<temp->national_id << "," << temp->status << ",";
                write_data_into_file();
            }
            update_file.close();
        }
        
    }
    ~employees_data_structure(){}
};
