#include <iostream>
#include <iomanip>
using namespace std;
int main(){

double mass, density, volume;
cout << "Enter the mass of the object in grams: ";
cin >> mass;

cout << "Enter the density of the object in grams per cubic centimeters : ";
cin >> density;

	volume = mass / density;

cout << fixed << setprecision(2);
cout << "The volume of the object is = " << volume;

return 0;
}
