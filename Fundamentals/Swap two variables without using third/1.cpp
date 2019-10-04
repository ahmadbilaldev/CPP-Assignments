#include <iostream>
using namespace std;
int main(){
	
	int firstVar, secondVar;
	
	cout<< "Enter the first variable: ";
	cin>> firstVar;
	cout<< "Enter the second variable: ";
	cin>> secondVar;
	 
		firstVar+=secondVar;			// Add the two variables
		secondVar=firstVar-secondVar;	// Subtract the second from the sum and assign answer to second
		firstVar=firstVar-secondVar;	// Now subtract the update value of second var from the sum
		
	cout<< "**After swapping**"<<endl <<"First variable: "<< firstVar << endl;
	cout<< "Second variable: "<< secondVar;
		


return 0;
}
