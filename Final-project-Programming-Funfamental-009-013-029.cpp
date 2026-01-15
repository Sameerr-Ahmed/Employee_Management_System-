#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

const int MAX_EMPLOYEES=100;

char full_Name[MAX_EMPLOYEES][50];
char father_name[MAX_EMPLOYEES][50];
char cnic[MAX_EMPLOYEES][20];
char address[MAX_EMPLOYEES][100];
int year_joined[MAX_EMPLOYEES];
int pay_grade[MAX_EMPLOYEES];
int employee_id[MAX_EMPLOYEES];
float basic_salary[MAX_EMPLOYEES];

int employee_count=0;

void add_employee()
{
    if (employee_count>=MAX_EMPLOYEES)
	{
        cout<<"Error: Maximum employee limit reached!\n";
        return;
    }
    cout<<"Enter Employee Name: ";
    gets(full_Name[employee_count]);
    cout<<"Enter Father's Name: ";
    gets(father_name[employee_count]);
    cout<<"Enter CNIC (with dashes): ";
    gets(cnic[employee_count]);
    cout<<"Enter Address: ";
    gets(address[employee_count]);
    cout<<"Enter Year Joined Service: ";
    cin>>year_joined[employee_count];
    cout<<"Enter Pay Grade (1 to 15): ";
    cin>>pay_grade[employee_count];
    cout<<"Enter Employee ID: ";
    cin>>employee_id[employee_count];
    cout<<"Enter Basic Salary: ";
    cin>>basic_salary[employee_count];
    cin.ignore(); 
	employee_count++;
    cout<<"Employee record added successfully!\n";
}

void search_employee()
{
    int id;
    cout<<"Enter Employee ID to search: ";
    cin>>id;
    for (int i=0;i<employee_count;i++)
	{
        if (employee_id[i]==id)
		{
            cout<<"Employee Found!\n";
            cout<<"Name: "<<full_Name[i]<<"\n";
            cout<<"Father's Name: "<<father_name[i]<<"\n";
            cout<<"CNIC: "<<cnic[i]<<"\n";
            cout<<"Address: "<<address[i]<<"\n";
            cout<<"Year Joined: "<<year_joined[i]<<"\n";
            cout<<"Pay Grade: "<<pay_grade[i]<<"\n";
            cout<<"Basic Salary: "<<basic_salary[i]<<"\n";
            return;
        }
    }
    cout<<"Employee not found!\n";
}

void view_all_employees()
{
    if (employee_count==0)
	{
        cout<<"No employee records to display!\n";
        return;
    }
    cout<<setw(10)<<"Emp ID"<<setw(20)<<"Name"<<setw(20)<<"Father's Name";
	cout<<setw(20)<<"CNIC"<<setw(10)<<"Pay Grade"<<setw(15)<<"Basic Salary"<<"\n";
    for (int i=0;i<employee_count;i++)
	{
        cout<<setw(10)<<employee_id[i];
    	cout<<setw(20)<<full_Name[i];
        cout<<setw(20)<< father_name[i];
        cout<<setw(20)<<cnic[i];
        cout<<setw(10)<<pay_grade[i];
        cout<<setw(15)<<basic_salary[i] << "\n";
    }
}

void view_by_pay_grade()
{
    int grade;
    cout<<"Enter Pay Grade to filter (1 to 15): ";
    cin>>grade;
    bool found=false;
    cout<<setw(10)<<"Emp ID"<<setw(20)<<"Name"<<setw(15)<<"Basic Salary"<<"\n";
    for(int i=0;i<employee_count;i++)
	{
        if (pay_grade[i]==grade)
		{
            cout<<setw(10)<<employee_id[i];
            cout<<setw(20)<<full_Name[i];
            cout<<setw(15)<<basic_salary[i] << "\n";
            found = true;
        }
    }
    if(!found)
	{
        cout<<"No employees found in this pay grade.\n";
    }
}

void compute_take_home_salary()
{
    int id;
    cout<<"Enter Employee ID: ";
    cin>>id;
    for (int i=0;i<employee_count;i++)
	{
        if (employee_id[i]==id)
		{
            float house_rent=0.45*basic_salary[i];
            float medical_allowance=0.05*basic_salary[i];
            float conveyance_allowance=0.10*basic_salary[i];
            float take_home_salary=basic_salary[i]+house_rent+medical_allowance+conveyance_allowance;
            cout<<"Basic Salary: "<<basic_salary[i]<<"\n";
            cout<<"House Rent Allowance: "<<house_rent<<"\n";
            cout<<"Medical Allowance: "<<medical_allowance<<"\n";
            cout<<"Conveyance Allowance: "<< conveyance_allowance<<"\n";
            cout<<"Take-home Salary: "<<take_home_salary<<"\n";
            return;
        }
    }
    cout<<"Employee not found!\n";
}
int main()
{
	int choice;
    do {
        cout<<"\nEmployee Management System Menu:\n";
        cout<<"1. Add Employee Record\n";
        cout<<"2. Search Employee Record\n";
        cout<<"3. View All Employee Records\n";
        cout<<"4. View Employees by Pay Grade\n";
        cout<<"5. Compute Take-home Salary\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch (choice)
		{	case 1:
                add_employee();
                break;
            case 2:
                search_employee();
                break;
            case 3:
                view_all_employees();
                break;
            case 4:
                view_by_pay_grade();
                break;
            case 5:
                compute_take_home_salary();
                break;
            case 6:
                cout<<"Exiting program. Goodbye!\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n"; }	}
	while(choice != 6);	{
		cout<<"\nHave a great day Goodbye ";}
  return 0;	}


