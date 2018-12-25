#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
	double electricity, sale, currentProfit, profit, markup, merchandiseCost, increasedCost, employeesSalary, herSalary, rent, expenses;
	string query;
	cout << "Enter the merchandise cost: $";
	cin  >> merchandiseCost;
	cout << "Enter the Employees' salaries: $";
	cin  >> employeesSalary;
	cout << "Enter your own Salary: $";
	cin  >> herSalary;
	cout << "Enter the rent: $";
	cin  >> rent;
	cout << "Enter the cost of electricity: $";
	cin  >> electricity;
	
	expenses  = merchandiseCost+employeesSalary+herSalary+rent+electricity;
	profit = merchandiseCost*10.0/100;
	increasedCost = merchandiseCost + profit;
	
	cout<<fixed<<setprecision(2);
	cout << "Do you want to put sale on the merchandise?"<< endl << "Enter \"yes\" or \"no\"" <<endl;
	cin	 >> query;
	
		if( query == "no" ){
			currentProfit = merchandiseCost - expenses;
			markup = profit - currentProfit;
			cout<< "The required markup on the merchandise is $" << markup;
		}
		
		else if ( query == "yes" ) {
			sale = merchandiseCost*15.0/100;
			expenses += sale;
			currentProfit = merchandiseCost - expenses;
			markup = profit - currentProfit;
			cout<< "The required markup on the merchandise is $" << markup;
		}
			
		
	return 0;
}
