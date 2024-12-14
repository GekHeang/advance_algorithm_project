#include<iostream>

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
    Node *next;
    string status;
};

class employees_data_structure
{
    public:
    int size;
    Node *front;
    Node *rear;

    employees_data_structure(){
        size = 0;
        front = NULL;
        rear = NULL;
    }

    void add_new_employee_info(string name, int id, string position, string hire_date, string gender, int age, float salary, string contact_info, string address, string date_of_birth, long int national_id, string status){
        Node *new_node;
        new_node = new Node;
        new_node->name = name;
        new_node->id = id;
        new_node->position = position;
        new_node->hire_date = hire_date;
        new_node->gender = gender;
        new_node->age = age;
        new_node->salary = salary;
        new_node->contact_info = contact_info;
        new_node->address = address;
        new_node->date_of_birth = date_of_birth;
        new_node->national_id = national_id;
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
            temp = temp->next;
        }

        
        
    }

};
