#include <iostream>
#include <vector>
#include "Customer.h"
#include "Product.h"
#include "Seller.h"	

using namespace std;
void main()
{

	vector <Customer> customers; //all customers in system
	vector <Product> products; //all products in system
	vector <Seller> sellers; //all sellers in system
	Product p(1, 5, 15, "phone", "mobile");
	p.product_info();
	cout << endl;
	int choice;   //this variable is entered by the user to choose his navigation
	cout << "Online Marketplace Management System\n";
	cout << "***********Welcome to Our Marketplace! :)*************\n";
	cout << "Press-->1 To Login \n";
	cout << "Press-->2 For Registration \n";


	cout << "somthing randam\n";

	do {
		cout << "Enter your Choice: ";cin >> choice;
	} while (choice != 1 && choice != 2);
	
}