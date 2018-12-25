#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	double kilos , pounds;
	cout<< "Enter the weight of the person in Kilos: ";
	cin>> kilos;
	
	pounds = kilos * 2.2;
	cout<< fixed << setprecision(2);
	cout<< "Weight in Kilos = "<<kilos << endl;
	cout<< "Weight in Pounds = "<<pounds;
	
	
return 0 ;
}
