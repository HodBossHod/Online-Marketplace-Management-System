#include <iostream>
#include <vector>
#include "Customer.h"
#include "Product.h"
#include "Seller.h"    
#include "Person.h"
#include <conio.h>
#include<string>
#include <windows.h>
#include"Validation.h"

using namespace std;
//------------------ global vars and vectors ------------------

vector <Customer> customers; //all customers in system
 vector <Product> products; //all products in system
vector <Seller> sellers; //all sellers in system
Admin admin("hadi","Admin2021@gmailcom");
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//-------------------------function declaration --------------------
string password();
void control();
void Registration();
void login();

int main()
{
    Product p1(101, 5, 15, "phone", "A");
    Product p2(101, 5, 15, "android", "B");
    Product p3(102, 5, 15, "mak", "B");
    Product p4(102, 5, 15, "lenovo", "B");
	products.push_back(p1);
	products.push_back(p2);
	products.push_back(p3);
	products.push_back(p4);
	cout << products.size();
	/*products.erase(products.begin() + 3);*/
	cout << products.size();
    //customers
    //the information for the first customer
    Customer c1("Customer1",			       //Name
				"Customer1@gmail.com",		  //Email
				"Customer1 adress",			 //adress
				"phone1",				    //phone
				"pass1");				   //passwod
	
	//the information for the second customer
    Customer c2("Customer2",                 //Name
				"Customer2@gmail.com", 	    //Email
				"Customer1 adress",		   //adress
				"phone2", 				  //phone
				"pass2");				 //passwod
    //save the data
    customers.push_back(c1);
    customers.push_back(c2);
    //sellers

    //the information for the first seller
    Seller s1("Seller1", //Name
			  "Seller1@gmail.com","pass3"); //NO NEED TO THIS IN SELLER

    //the information for the second seller
    Seller s2("Seller2",  //Name
			  "Seller2@gmail.com","pass4");	//NO NEED TO THIS IN SELLER
    //save the data
    sellers.push_back(s1);
    sellers.push_back(s2);
    //to display the data in seller and customer vector
    for (int i = 0; i < sellers.size(); i++)
        cout << sellers[i].get_name() << "\t\t" <<
				sellers[i].get_password() << "\t\t" <<
				sellers[i].get_id() <<"\t\t" << 
				sellers[i].get_email() << "\t\t" << 
				sellers[i].get_address() << "\t\t" << 
				sellers[i].get_phoneNum() << endl;

    for (int i = 0; i < customers.size(); i++)
        cout << customers[i].get_name() << "\t" << 
				customers[i].get_password() << "\t\t" << 
				customers[i].get_id() << "\t\t" << 
				customers[i].get_email() << "\t\t" <<
				customers[i].get_address() << "\t" << 
				customers[i].get_phoneNum() << endl;

	/*customers[0].Add_to_cart(p1, 2);
	customers[0].Add_to_cart(p2, 2);
	customers[0].Add_to_cart(p3, 2);
	
	customers[0].remove_from_cart(p3);*/

    cout << "\n\n\n";
    cout << "\t\t\t\t\tOnline Marketplace Management System\n";
    cout << "\t\t***************************Welcome to Our Marketplace! :)**************************\n";
    string N_num;
    bool isValid=true;
    while (true) {
        if (isValid) {
            control();
        }
        cout << "please press 1 to continue\n";
        cout << "please press 2 to exit\n";
        getline(cin,N_num);
        if (N_num == "1")
        {
            isValid=true;
        }
        else if (N_num == "2")
        {
            return 0;
        }
        else
        {
            isValid = false;
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Invalid entry\n";
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
	
    system("pause");
    return 0;


}

//------------------- function Defenation --------------------
//password function
string password() {
	char pass[50];
	int num = 0;
	cout << "Enter the password: \n";
	while (pass[num - 1] != '\r')
	{
		pass[num] = _getch();
		if (pass[num - 1] != '\r')
		{
			cout << "*";
		}
		num++;
	}
	pass[num - 1] = '\0';
	string s = pass;
	return s;
}

//for asking the user if he want to login or regist
void control()
{
    //Person p;
    string choice;   //this variable is entered by the user to choose his navigation 
    cout << "please enter number :\n";
    cout << "1-Login\t" << "2-Registration\n";
    getline(cin, choice);
    if (choice == "1")
    {
        login();
    }
    else if (choice == "2")
    {
        Registration();

        for (int i = 0; i < sellers.size(); i++)
            cout << sellers[i].get_name() << "\t\t" << 
					sellers[i].get_password() << "\t\t" <<
					sellers[i].get_id() << "\t\t" <<
					sellers[i].get_email() << "\t\t" << 
					sellers[i].get_address() << "\t\t" << 
					sellers[i].get_phoneNum() << endl;

        for (int i = 0; i < customers.size(); i++)
            cout << customers[i].get_name() << "\t" << 
					customers[i].get_password() << "\t\t" <<
					customers[i].get_id() << "\t\t" <<
					customers[i].get_email() << "\t\t" <<
					customers[i].get_address() << "\t" << 
					customers[i].get_phoneNum() << endl;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Please enter the correct number ....\n";
        SetConsoleTextAttribute(hConsole, 15);
        control();
    }
}

//regestration function
void Registration()
{
	string number;
	string setName, setPass, setAdd, setEmail, setPhone;
	cout << "please press 1 for seller\n";
	cout << "please press 2 for customer\n";
    getline(cin, number);
	if (number == "1" || number == "2")
	{
		cout << "Enter your Name :  \n";
		cin.ignore();
		getline(cin, setName);
        setEmail = Validation::emailValidation();
		setPass = Validation::passwordValidation();

		

		if (number == "2")
		{
			cout << "Enter your Phone Number :  \n";
			getline(cin, setPhone);
			cout << "Enter your Address :  \n";
			getline(cin, setAdd);
			Customer tmpCustomer(setName, setEmail, setAdd, setPhone, setPass); //temparaory create for customer
            cout << "************************************\n";
            cout << "Your ID is: " << tmpCustomer.get_id() << endl;
            cout << "\n\n\n";
            cout << "************************************\n";
			customers.push_back(tmpCustomer);
		}
		else if (number == "1")
		{
			Seller tmpSeller(setName, setEmail,setPass);//temparaory creat for seller
            cout << "************************************\n";
            cout << "Your ID is: " << tmpSeller.get_id() << endl;
            cout << "\n\n\n";
            cout << "************************************\n";
			sellers.push_back(tmpSeller);
		}
	}
	else
	{
        SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid input\n";
        SetConsoleTextAttribute(hConsole, 15);
		Registration();
	}
}

//login functiom
void login()
{
    bool check = false;
    int person_id;
    //string setEmail;
    string person_email;
    string person_password;
    cout << "Enter your ID" << endl;
    person_id = Validation::isNumber();
    cout << "Enter your Email :  \n";
    getline(cin,person_email);

    person_password = password();
    if (person_id >= 100 && person_id < 1000)
    {
        for (int i = 0; i < sellers.size(); i++)
        {
            if (person_email == sellers[i].get_email() && 
				person_password == sellers[i].get_password())
            {
                SetConsoleTextAttribute(hConsole, 1);
                cout << "\nHello , " << sellers[i].get_name() << endl;
                SetConsoleTextAttribute(hConsole, 15);
                sellers[i].seller_menu(admin,products);
                check = true;
                break;
            }
            
        }
        if (check == false)
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\nYour Email or Password is Invalid \nPlease try again\n";
            SetConsoleTextAttribute(hConsole, 15);
            login();
            // break;
        }
    }
    else if (person_id >= 1000&&person_id <10000)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (person_email == customers[i].get_email() && 
				person_password == customers[i].get_password())
            {
                SetConsoleTextAttribute(hConsole, 4);
                cout << "\nHello, " << customers[i].get_name() << endl;
                SetConsoleTextAttribute(hConsole, 15);
				customers[i].customer_menu(products);
                check = true;
                break;
            }
    
        }
        if (check == false)
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\nYour Email or your Password is invalid \nPlease try again\n";
            SetConsoleTextAttribute(hConsole, 15);
            login();
            // break;
        }
    }
	else if (person_id == admin.get_id() && /*person_email==admin.get_email() &&*/ person_password ==admin.get_password()) {
		admin.Accept_or_Reject(products);
    }
    else {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "\n\nThe ID you have entered is not found \n\n";
        SetConsoleTextAttribute(hConsole, 15);
    }

}
