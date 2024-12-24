#include<iostream>
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
    private:
    Node* head;     
    Node* tail;      
    int length; 
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
        int num_employees;
        cout<<"How many employees do you want to add? ";
        cin>>num_employees;
        for(int i = 0; i < num_employees; i++)
        {
            Node *new_node;
            new_node = new Node;
            cout << "Fill the employee information "<<i + 1 <<"below." << endl;
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
            cout << "Date of birth: ";
            cin >> date_of_birth;
            new_node->date_of_birth = date_of_birth;
            cout << "National id: ";
            cin >> national_id;
            new_node->national_id = national_id;
            cout << "Status: ";
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
            cout<<"Employee "<<i + 1<<" added successfully!"<<endl;
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

    void update(){}
        

    void display(){
        fstream info_file;
        info_file.open("employee_info.csv", ios::app);
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
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{

    employees_data_structure employee;
    fstream myFile;
    string filename = "employee_info.csv";
    int option;
    bool isTrue = false;

    option:
    system("cls");
    cout <<"Choose an option"<<endl;
    cout <<"1.Add new employee"<<endl;
    cout <<"2.Display information employee"<<endl;

    while(isTrue == false)
    {
        cout<<"Enter the option: ";
        cin>>option;
        if(option == 1)
        {
            string firstLine;
            string line;

            myFile.open(filename, ios::in);
            getline(myFile, firstLine);
            while(getline(myFile, line))
            {
                employee.add_new_employee_info();
            }
            myFile.close();
            system("pause");
            goto option;
        }
        
        else if(option == 2)
        {
            employee.display();
            system("pause");
            goto option;
            
        }
        
        
        
    }
    return 0;
}



























    //employees_data_structure() : head(nullptr), tail(nullptr), length(0) {}

// bool checkData(int newData)
    // {
    //     Node *current = rear;

    //     while (current != NULL)
    //     {
    //         if (newData == current->data)
    //         {
    //             return true;
    //         }
    //         else if (newData > current->data)
    //         {
    //             current = current->right; 
    //         }
    //         else
    //         {
    //             current = current->left; 
    //         }
    //     }

    //     return false; 
    // }











// string firstLine;
            // string line;
            // bool isAddedData;
            // string name;
            // int id;
            // string position;
            // string hire_date;
            // string gender;
            // int age;
            // float salary;
            // string contact_info;
            // string address;
            // string date_of_birth;
            // long int national_id;
            // string status;
// name = stoi(line);
                // id = stoi(line);
                // position = stoi(line);
                // hire_date = stoi(line);
                // gender = stoi(line);
                // age = stoi(line);
                // salary = stoi(line);
                // contact_info = stoi(line);
                // address = stoi(line);
                // date_of_birth = stoi(line);
                // national_id = stoi(line);
                // status = stoi(line);

                // isAddedData = employee.checkData(name);
                // isAddedData = employee.checkData(id);
                // isAddedData = employee.checkData(position);
                // isAddedData = employee.checkData(hire_date);
                // isAddedData = employee.checkData(gender);
                // isAddedData = employee.checkData(age);
                // isAddedData = employee.checkData(salary);
                // isAddedData = employee.checkData(contact_info);
                // isAddedData = employee.checkData(address);
                // isAddedData = employee.checkData(date_of_birth);
                // isAddedData = employee.checkData(national_id);
                // isAddedData = employee.checkData(status);

            //     if(isAddedData)
            //     {
            //         cout<<"Data is already add. \n" <<endl;
            //         system("pause");
            //         goto option;
            //         break;
            //     }

            //     employee.checkData(name);
            //     employee.checkData(id);
            //     employee.checkData(position);
            //     employee.checkData(hire_date);
            //     employee.checkData(gender);
            //     employee.checkData(age);
            //     employee.checkData(salary);
            //     employee.checkData(contact_info);
            //     employee.checkData(address);
            //     employee.checkData(date_of_birth);
            //     employee.checkData(national_id);
            //     employee.checkData(status);
            // }