#include<fstream>
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
    long int national_id;
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
    long int national_id;
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
        cin >> name;
        new_node->name = name;
        cout << "Id: ";
        cin >> id;
        new_node->id = id;
        cout << "Position: ";
        cin >> position;
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
        cin >> contact_info;
        new_node->contact_info = contact_info;
        cout << "Address: ";
        cin >> address;
        new_node->address = address;
        cout << "date_of_birth: ";
        cin >> date_of_birth;
        new_node->date_of_birth = date_of_birth;
        cout << "national_id: ";
        cin >> national_id;
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

    void delete_employee_info(int employee_id){
        if (size == 0)
        {
            cout << "Data structure is empty. cannot delete" << endl;
        }
        if (front->id == employee_id) 
        {
            Node *temp;
            temp = front;
            front = front->next;
            delete temp;
            size--;
            cout << "Employee with ID " << employee_id << " deleted successfully." << endl;
            return;
        }

        Node* current = front;
        Node* prev = NULL;

        while (current != NULL && current->id != employee_id) 
        {
            prev = current;
            current = current->next;
        }
        
        if (current == NULL) 
        {
            cout << "Employee with ID " << employee_id << " not found." << endl;
            return;
        }
        
        prev->next = current->next;
        if (current == rear) 
        {
            rear = prev;  
        }
        
        delete current;
        size--;
        cout << "Employee with ID " << employee_id << " deleted successfully." << endl;
    }

    void search_employee_info(string attribute, string value) {
        Node* current = front;
        while (current != NULL) 
        {
            if ((attribute == "name" && current->name == value) ||
                (attribute == "id" && to_string(current->id) == value) ||
                (attribute == "position" && current->position == value)) 
                {
                    cout << "Employee Found: " << endl;
                    cout << "Name: " << current->name << ", ID: " << current->id << endl;
                    return;
                }
                current = current->next;
        }
        cout << "Employee not found." << endl;
    }
        

    void display(){
        fstream info_file;
        info_file.open("employee_info.csv", ios::app);
        Node *temp;
        temp = front;
        while (front != NULL)
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
                << temp->address << ","
                << temp->date_of_birth << ","
                << temp->national_id << ","
                << temp->status << ","
                <<endl;
            temp = temp->next;
        }
        info_file.close();
    }

    ~employees_data_structure()
    {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};
