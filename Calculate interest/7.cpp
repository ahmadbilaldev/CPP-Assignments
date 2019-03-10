#include <iostream>
#include <iomanip>
using namespace std;
int main(){

double netBalance, payment, interestRate, interest, averageDailyBalance;
int d1, d2;
	cout << "Enter the net balance: ";
	cin  >> netBalance;
	cout << "Enter the payment: ";
	cin  >> payment;
	cout << "Enter the number of days in billing cycle: ";
	cin  >> d1;
	cout << "Enter the Enter the number of days payment is made before in the billing cycle: ";
	cin  >> d2;
	cout << "Enter the interest rate per month: ";
	cin  >> interestRate;

	averageDailyBalance = (netBalance*d1 - payment * d2)/d1;
	interest = averageDailyBalance * interestRate;



cout << fixed << setprecision(2);
cout << interest;


return 0;
}
