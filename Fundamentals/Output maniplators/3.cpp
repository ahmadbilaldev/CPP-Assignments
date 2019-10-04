#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){

const double PI = 3.14159;
double radius, height;

	cout << "Enter the height of the cylinder: ";
	cin >> height;

	cout << "Enter the radius of the base of the cylinder: ";
	cin >> radius;

	cout << fixed << showpoint << setprecision(2);
	cout << "Surface area = ";
	cout << 2 * PI * radius * height + 2 * PI * pow(radius, 2.0) << endl;
	
	cout << "Volume of the cylinder = ";
	cout << PI * pow(radius, 2.0)* height;

return 0;
}
