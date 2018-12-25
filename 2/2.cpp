#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){

double height;
cout << "Enter the height of the cylinder: ";
cin >> height;

double radius;
cout << "Enter the radius of the base of the cylinder: ";
cin >> radius;

const double PI = 3.14159;

cout << fixed << showpoint << setprecision(2);
cout << "Surface area = ";
cout << 2 * PI * radius * height + 2 * PI * pow(radius, 2.0);
cout << endl;
cout << "Volume of the cylinder = ";
cout << PI * pow(radius, 2.0)* height;

return 0;
}
