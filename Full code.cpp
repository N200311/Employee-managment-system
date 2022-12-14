#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

//base class
class Employee{

    private://Employee class variables
        string Full_Name;
        string Email;
        string Phone;
        string Position;
        double Salary;
    
    public:

        //default constructor
        Employee(){
            Full_Name.clear();//clear function to empty string
            Email.clear();
            Phone.clear();
            Position.clear();
            Salary = 0;
        }
        
        //paramitised constructor constructor
        Employee(string n,string e,string p,string po,double sal){
            Full_Name = n;
            Email = e;
            Phone = p;
            Position = po;
            Salary = sal;
        }
        
        //display method
        void display_employee_info(){
            cout<<"\nEmployee Information :"<<endl;
            cout<<"Name : "<<get_Fullname()<<endl;
            cout<<"Email : "<<get_Email()<<endl;
            cout<<"Phone : "<<get_Phone()<<endl;
            cout<<"Position : "<<get_position()<<endl;
            cout<<"Salary : "<<get_Salary()<<endl;
        }

        //setters
        void set_FullName(string FN){
            Full_Name = FN;
        }
        void set_Email(string E){
            Email = E;
        }
        void set_Phone(string P){
            Phone = P;
        }
        void set_Position(string Pos){
            Position = Pos;
        }
        void set_Salary(double sal){
            Salary = sal;
        }

        //getters
        string get_Fullname(){return Full_Name;}
        string get_Email(){return Email;}
        string get_Phone(){return Phone;}
        string get_position(){return Position;}
        double get_Salary(){return Salary;}


};

template <class T>//generic class
class Node{
    public:
        T Data;
        Node<T>* Next;
        
        Node(T d){
            Data = d;
            Next = NULL;
        }
};

template <class T>//generic class
class EmployeeList{

    private:
	    Node<T>* head;

    public:

        //constructor
    	EmployeeList(){
    	    head = NULL;
    	}

        //insert method
    	bool insert_employee(T e){

    		Node<T>* newNode = new Node<T>(e); //initialize and assign new node

            if(head == NULL){//if list is empty
                head = newNode;//then assign head as the new node
                cout<<"\nEmployee successfully added to Database."<<endl;
                return true;
            }

            Node<T>* look = head; //point new node called "look" to head
            while(look != NULL){//check if Employee already exists or not
                if(look->Data.get_Email() == newNode->Data.get_Email()){ //compare email of new node and look
                    cout<<"\nEmployee already exists in Database."<<endl;
                    return false;
                }
                look = look->Next;//to traverse through the list
            }

            Node<T>* temp = head; //point temp to head
            while(temp->Next != NULL){//adding Employee
                temp = temp->Next;//traverse list till last node
            }
            temp->Next = newNode;//add the new node to list
            cout<<"\nEmployee successfully added to Database."<<endl;
            return true;
        }
            
        //edit salary method
        bool edit_salary(double new_salary, string look_email){

            if(new_salary <= 0){//make sure salary is a positive valid number
                cout<<"\nInvalid input for salary."<<endl;
                cout<<"Salary should be positive and non-Zero."<<endl;
                cout<<"Try Again."<<endl;
                return false;
            }

            if(head == NULL){//if list is empty
                cout<<"\nNo Employees in Database."<<endl;
                return false;
            }

            Node<T>* temp = head; //assign temp to point at head
            while(temp != NULL){//update salary
                if(temp->Data.get_Email() == look_email){ //look for the email
                    temp->Data.set_Salary(new_salary); //update salary when email is found
                    cout<<"\nSalary successfully updated."<<endl;
                    return true;
                }
                temp = temp->Next; //to traverse through the list
            }
            cout<<"\nEmployee does not exist in Database."<<endl;//if employee does not exist
            cout<<"Try Again."<<endl;
            return false;
        }

        //delete method
        bool delete_employee(string email){
    
            if(head == NULL){//if list is empty
                cout<<"\nNo Employees in Database."<<endl;
                return false;
            }

            Node<T>* temp = head; //temp points to head
            Node<T>* extra = NULL; //new node called "extra" equal NULL

            if(temp->Data.get_Email() == email){//if deleting the head
                head = head->Next; //change head to the next node
                delete temp; //delete temp which point to old value of head
                return true;
            }

            temp = head->Next; //temp now points to the node after head

            while(temp != NULL){//deleting employee
                if(temp->Data.get_Email() == email){//looking for the email, if found
                    extra = temp->Next;//assign extra to the node after temp
                    temp->Next = extra->Next; //assign the next of temp to point to the next of extra
                    delete extra; 
                    return true;
                }
                temp = temp->Next;//to traverse through the list
            }
            cout<<"\nEmployee does not exist in Database."<<endl;//employee does not exist
            cout<<"Try Again."<<endl;
            return false;
        }

        //display all employees method
        bool print_all_employees(){

            if(head == NULL){
                cout<<"\nNo Employees in database."<<endl;
                return false;
            }
            Node<T>* temp = head;
            while(temp != NULL){
                temp->Data.display_employee_info();
                temp = temp->Next;
            }
            return true;
        }

        //Bouns method
        bool update_Employee_info(string email){

            if(head == NULL){ //if the list is empty
                cout<<"\nNo Employees in database."<<endl;
                return false;
            }

            Node<T>* look = head; //assign "look" to point at head
            int variable;

            while(look != NULL){
                if(look->Data.get_Email() == email){//if email is found
                    cout<<"\nChoose what you would like to edit: "<<endl;
                    cout<<"1. Name."<<endl;
                    cout<<"2. Email."<<endl;
                    cout<<"3. Phone."<<endl;
                    cout<<"4. Position."<<endl;
                    cout<<"5. Salary."<<endl;
                    cout<<"Enter your choice: ";
                    while(!(cin>>variable))//if the value entered is string or invalid
                    {
                        cout<<"\nInvalid choice, please enter a number from 1 to 5: ";
                        cin.clear(); 
                        cin.ignore(1000,'\n');
                    }
                    change(variable,look); //call function change
                    cout<<"Update Completed."<<endl;
                    return true;
                }
                look = look->Next;//to traverse through the list
            }
            cout<<"\nEmployee does not exist in Database."<<endl;//if email is not found
            cout<<"Try again."<<endl;
            return false;

        }
};

//functions prototypes
void change(int var, Node<Employee>* emp);
void implement_choice(int choice,EmployeeList<Employee> list);

int main() {

    int choice;
    EmployeeList<Employee> list_of_Employees;
    
    cout<<"Welcome to the Employee Management System"<<endl;
    cout<<"\nChoose one of the following to use the system features"<<endl;
    cout<<"1. Insert a new Employee"<<endl;
    cout<<"2. Edit employee's salary"<<endl;
    cout<<"3. Delete an employee"<<endl;
    cout<<"4. Print all employees"<<endl;
    cout<<"5. Update Employee's information"<<endl;
    cout<<"6. Close the program"<<endl;
    cout<<"\nEnter Your Choice: ";

    cin>>choice;
    implement_choice(choice,list_of_Employees);// call function implement_choice
    
    return 0;
}

void implement_choice(int choice,EmployeeList<Employee> list){
    //temp variables
    string temp_Full_Name;
    string temp_Email;
    string temp_Phone;
    string temp_Position;
    double temp_Salary;
    
    switch (choice)
    {
        case 1:
        {//brackets fixed error "transfer of control bypasses initialization of" in switch
            cout<<"\nEnter Employee Information:"<<endl;
            cout<<"Full Name: ";
            cin.ignore(); //to make getline work
            getline(cin,temp_Full_Name); //to take the full name with the space
            cout<<"Email: "; 
            cin>>temp_Email;
            cout<<"Phone: "; 
            cin>>temp_Phone;
            cout<<"Position: "; 
            cin.ignore();
            getline(cin,temp_Position);
            cout<<"Salary: "; 
            cin>>temp_Salary;
            Employee e(temp_Full_Name,temp_Email,temp_Phone,temp_Position,temp_Salary);
            list.insert_employee(e);
            //continue the programs
            while(choice < 6)
            {
            cout<<"\nContinuing program..."<<endl;
            cout<<"Choose of the following to use the system features"<<endl;
            cout<<"1. Insert a new Employee"<<endl;
            cout<<"2. Edit employee's salary"<<endl;
            cout<<"3. Delete an employee"<<endl;
            cout<<"4. Print all employees"<<endl;
            cout<<"5. Update Employee's information"<<endl;
            cout<<"6. Close the program"<<endl;
            cout<<"\nEnter Your Choice: ";
            cin.clear();
            cin.ignore(1000,'\n');
            while(!(cin>>choice))//if choice is an invalid input
            {
                cout<<"\nInvalid choice, please enter a number from 1 to 6: ";
                cin.clear();
                cin.ignore(1000,'\n');
            }
            implement_choice(choice,list);
            }
            break;
        }

        case 2:
        {
            cout<<"\nEnter Employee's Email: ";
            cin>>temp_Email;

            cout<<"\nEnter New Salary: ";
            while(!(cin>>temp_Salary)){
                cout<<"\nInvalid input for Salary."<<endl;
                cout<<"Salary should be a number."<<endl;
                cout<<"Try Again."<<endl;
                cout<<"\nEnter New Salary: ";
                cin.clear();
                cin.ignore(1000,'\n');
            }

            list.edit_salary(temp_Salary,temp_Email);

            while(choice < 6)
            {
            cout<<"\nContinuing program..."<<endl;
            cout<<"Choose of the following to use the system features"<<endl;
            cout<<"1. Insert a new Employee"<<endl;
            cout<<"2. Edit employee's salary"<<endl;
            cout<<"3. Delete an employee"<<endl;
            cout<<"4. Print all employees"<<endl;
            cout<<"5. Update Employee's information"<<endl;
            cout<<"6. Close the program"<<endl;
            cout<<"\nEnter Your Choice: ";

            while(!(cin>>choice)){
                cout<<"\nInvalid choice, please enter a number from 1 to 6: ";
                cin.clear();
                cin.ignore(1000,'\n');
            }
            implement_choice(choice,list);
            }
            break;
        }

        case 3:
        {
            cout<<"\nEnter Employee's Email: ";
            cin>>temp_Email;

            list.delete_employee(temp_Email);

            while(choice < 6)
            {
            cout<<"\nContinuing program..."<<endl;
            cout<<"Choose of the following to use the system features"<<endl;
            cout<<"1. Insert a new Employee"<<endl;
            cout<<"2. Edit employee's salary"<<endl;
            cout<<"3. Delete an employee"<<endl;
            cout<<"4. Print all employees"<<endl;
            cout<<"5. Update Employee's information"<<endl;
            cout<<"6. Close the program"<<endl;
            cout<<"\nEnter Your Choice: ";
            cin.clear();
            cin.ignore(1000,'\n');
            while(!(cin>>choice)){
                cout<<"\nInvalid choice, please enter a number from 1 to 6: ";
                cin.clear();
                cin.ignore(1000,'\n');
            }
            implement_choice(choice,list);
            }

            break;
        }

        case 4:
        {
            list.print_all_employees();

            while(choice < 6)
            {
            cout<<"\nContinuing program..."<<endl;
            cout<<"Choose of the following to use the system features"<<endl;
            cout<<"1. Insert a new Employee"<<endl;
            cout<<"2. Edit employee's salary"<<endl;
            cout<<"3. Delete an employee"<<endl;
            cout<<"4. Print all employees"<<endl;
            cout<<"5. Update Employee's information"<<endl;
            cout<<"6. Close the program"<<endl;
            cout<<"\nEnter Your Choice: ";
            while(!(cin>>choice)){
                cout<<"\nInvalid choice, please enter a number from 1 to 6: ";
                cin.clear();
                cin.ignore(1000,'\n');
            }
            implement_choice(choice,list);
            }

            break;
        }

        case 5:
        {
            cout<<"Enter Employee Email: ";
            cin>>temp_Email;
            list.update_Employee_info(temp_Email);
            break;
        }

        case 6:
        {
            cout<<"\nProgram terminating..."<<endl;
            exit(0);
        }

        default:
        {
            cout<<"\nInvalid choice entered."<<endl;
            cout<<"Please Enter a number from 1 to 5."<<endl;
            cout<<"Try again."<<endl;

            while(choice < 6)
            {
            cout<<"\nContinuing program..."<<endl;
            cout<<"Choose of the following to use the system features"<<endl;
            cout<<"1. Insert a new Employee"<<endl;
            cout<<"2. Edit employee's salary"<<endl;
            cout<<"3. Delete an employee"<<endl;
            cout<<"4. Print all employees"<<endl;
            cout<<"5. Update Employee's information"<<endl;
            cout<<"6. Close the program"<<endl;
            cout<<"\nEnter Your Choice: ";
            cin.clear();
            cin.ignore(1000,'\n');
            while(!(cin>>choice)){
                cout<<"\nInvalid choice, please enter a number from 1 to 6: ";
                cin.clear();
                cin.ignore(1000,'\n');
            }
            implement_choice(choice,list);
            }

            break;
        }
        
    }
}

void change(int var,Node<Employee>* emp){
    string new_name;
    string new_email;
    string new_phone;
    string new_position;
    double new_salary;

    switch(var){
        case 1:
            cout<<"\nEnter the new Name: ";
            cin.ignore();
            getline(cin,new_name);
            emp->Data.set_FullName(new_name);
            break;

        case 2:
            cout<<"\nEnter the new Email: ";
            cin>>new_email;
            emp->Data.set_Email(new_email);
            break;

        case 3:
            cout<<"\nEnter the new Phone: ";
            cin>>new_phone;
            emp->Data.set_Phone(new_phone);
            break;

        case 4:
            cout<<"\nEnter the new Position: ";
            cin>>new_position;
            emp->Data.set_Position(new_position);
            break;

        case 5:
            cout<<"Enter the new Salary: ";
            while(!(cin>>new_salary)){
                cout<<"\nInvalid input for Salary."<<endl;
                cout<<"Salary should be a number."<<endl;
                cout<<"Try Again."<<endl;
                cout<<"\nEnter New Salary: ";
                cin.clear();
                cin.ignore(1000,'\n');
            }
            emp->Data.set_Salary(new_salary);
            break;

        default:
            cout<<"\nInvalid choice entered."<<endl;
            cout<<"Please Enter a number from 1 to 5."<<endl;
            cout<<"Try again."<<endl;
            break;

    }
}