#include<fstream>
#include<sstream>
#include<string>
#include<ctime>
#include<chrono>
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
        read_data_from_file_and_load_to_queue();
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
        cin.ignore();
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
        cin.ignore();
        getline(cin, contact_info);
        new_node->contact_info = contact_info;
        cout << "Address: ";
        // cin.ignore();
        getline(cin, address);
        new_node->address = address;
        cout << "date_of_birth: ";
        // cin.ignore();
        getline(cin, date_of_birth);
        new_node->date_of_birth = date_of_birth;
        cout << "national_id: ";
        // cin.ignore();
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

        cout << new_node->name << "," 
                << new_node->id << ","
                << new_node->position << ","
                << new_node->hire_date << ","
                << new_node->gender << ","
                << new_node->age << ","
                << new_node->salary << ","
                << new_node->contact_info << ","
                << new_node->address << ","
                << new_node->date_of_birth << ","
                << new_node->national_id << ","
                << new_node->status << ","
                <<endl;
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


    void write_data_into_file(){
        fstream info_file;
        info_file.open("employee_info.csv", ios::out);
        Node *temp;
        temp = front;
        info_file << "name, id, position, hire_date, gender, age, salary, contact_info, address, date_of_birth, national_id, status"<< endl;
        while (temp != NULL)
        {
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

    Node *id_(Node *front, int id){
        Node *temp;
        temp = front;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                return temp;
            }
            else{
                temp = temp->next;
            }
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
                temp->position = new_value;
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
            else if(property == "contact_info"){
                temp->contact_info = new_value;
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
            
            write_data_into_file();
            
        }
        
    }
    
    void display_data_in_node(Node *temp){
        cout << temp->name << "," << temp->id << "," << temp->position << "," 
            << temp->hire_date << "," << temp->gender << "," << temp->age << ","
            << temp->salary << "," << temp->contact_info << "," 
            << temp->address << "," << temp->date_of_birth << "," 
            << temp->national_id << "," << temp->status << "," << endl;
    }
    void search(string property, string search_value){
        read_data_from_file_and_load_to_queue();
        Node *temp;
        temp = front;
        bool found = false;
        if (temp == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        
        if (property == "name")
        {
            while (temp != NULL)
            {
                if (search_value == temp->name)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
            }   
            if(found == false){
                cout << "No data is founded" << endl;
            }
        }
        else if(property =="id"){
            int converted_id = stoi(search_value);
            while(temp != NULL){
                {
                    if (converted_id == temp->id)
                    {
                        found = true;
                        display_data_in_node(temp);
                    }
                    temp = temp->next;
                }

            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
        }
        else if(property =="position"){
            while (temp != NULL)
            {
                if (search_value == temp->position)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
                
            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
        }
        else if (property == "hire_date")
        {
            while (temp != NULL)
            {
                if (search_value == temp->hire_date)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
                
            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
        }
        else if(property == "gender"){
            while (temp != NULL)
            {
                if (search_value == temp->gender)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
                
            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
            
        }
        else if (property == "age")
        {
            int converted_age = stoi(search_value);
            while (temp != NULL)
            {
                if (converted_age == temp->age)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
                
            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
        }
        else if (property == "salary")
        {
            float converted_salary = stof(search_value);
            while (temp != NULL)
            {
                if (converted_salary == temp->salary)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
                
            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
        }
        else if(property == "contact_info"){
            while (temp != NULL)
            {
                if (search_value == temp->contact_info)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
                
            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
        }
        else if(property == "address"){
            while (temp != NULL)
            {
                if (search_value == temp->address)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
                
            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
        }
        else if(property == "date_of_birth"){
            while (temp != NULL)
            {
                if (search_value == temp->date_of_birth)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
                
            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
        }
        else if(property == "national_id"){
            while (temp != NULL)
            {
                if (search_value == temp->national_id)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
                
            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
        }
        else if(property == "status"){
            while (temp != NULL)
            {
                if (search_value == temp->status)
                {
                    display_data_in_node(temp);
                    found = true;
                }
                temp = temp->next;
                
            }
            if (found == false)
            {
                cout << "No data is founded" << endl;
            }
        }
        else{
            cout << "category is not exist" << endl;
        }
    }


    void check_for_future_retire(){
        read_data_from_file_and_load_to_queue();
        Node *temp;
        temp = front;
        int year;
       
        if (temp == NULL)
        {
            cout << "No Data in queue" << endl;
            return;
        }
        
        cout << "Enter the year you would like to check:";
        cin >> year;

        if (year >= current_year() && year <= current_year() + 10){
            while (temp != NULL)
            {
                string dob = temp->date_of_birth;
                string day_string, year_string;
                int converted_day, converted_year;
                string month;
                stringstream separate(dob);
                getline(separate, day_string, '-');
                converted_day = stoi(day_string);
                getline(separate, month,'-');
                getline(separate, year_string, '-');
                converted_year = stoi(year_string);

                if (year - converted_year >= 65){
                    display_data_in_node(temp);
                }
                temp = temp->next;
                
            }
        }
        else{
            cout << "input year is too early or too far into the future";
        }     
    }

    int current_year(){
        time_t now = time(0);
        tm* local_time = localtime(&now);
        int current_year = 1900 + local_time->tm_year;

        return current_year;
    }

    void check_employees_hire_duration(int year){
        read_data_from_file_and_load_to_queue();
        Node *temp;
        temp = front;
        string hire_date;
        int int_hire_date_year, int_hire_date_day;
        string string_hire_date_year, string_hire_date_day;
        string hire_date_month;
        if (year >= 1 && year <= 40)
        {
            cout << "Employee who are working for up to "<< year << " year" << endl;
            
            while (temp != NULL)
            {
                hire_date = temp->hire_date;
                stringstream separate(hire_date);
                getline(separate, string_hire_date_day, '-');
                int_hire_date_day = stoi(string_hire_date_day);
                getline(separate, hire_date_month, '-');
                getline(separate, string_hire_date_year, '-');
                int_hire_date_year = stoi(string_hire_date_year);
                if(current_year() - int_hire_date_year >= year){
                    display_data_in_node(temp);
                }
                temp = temp->next;
            }
            cout << "---------------------------------------------------------------------------" << endl;
            
            
        }

    }
    ~employees_data_structure(){}
};
