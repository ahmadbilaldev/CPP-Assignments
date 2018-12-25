#include<iostream>
#include <string>
#include<fstream>
#include<iomanip>
using namespace std;
int main() {

	ifstream inFile;
	ofstream outFile;
	int i;
	string fname, fname2, fname3, lname, lname2, lname3;
	double curSalary, curSalary2, curSalary3, perc, perc2, perc3, increment, updSalary;
	inFile.open("ch3_ex7_data.txt");
	outFile.open("ch3_ex7_output.txt");
	
		for ( i=0 ; i<3 ; i++){
		
		inFile>> fname >> lname >> curSalary >> perc;
			
			increment = (perc/100) * curSalary;
			updSalary = curSalary + increment;
		
		outFile<< fixed << setprecision(2);
		outFile<< fname << " "<< lname << "  " << updSalary << endl;
		}
	inFile.close();
	outFile.close();
	return 0;
}
