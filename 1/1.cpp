#include<iostream>
#include <string>
#include<iomanip>
#include<fstream>
using namespace std;
int main() {
	float length, width, pmeter, radius, rArea, cArea, circum, beginBal, addBal, endBal, interest;
	int age, asc;
 	string fname, lname;
	char ch, ch2;
	ifstream inFile;
	ofstream outFile;
	inFile.open("inData1.txt");
	outFile.open("outData1.txt");
	inFile>> length >> width >> radius >>fname >>lname >>age >>beginBal >>interest >>ch;
	cout<< fixed <<setprecision(2);
	rArea = length*width;
	pmeter = 2*(length+width);
	cArea = 3.1416*radius*radius;
	circum = 2*3.1416*radius;
	addBal = (beginBal/100)*3.50;
	endBal = beginBal + addBal;
	asc = ch + 1;
	ch2 = asc;
	
	outFile<< fixed << setprecision(2) << "Rectangle: " << endl;
	outFile<< "Length = "<< length << ", width = "<< width <<", area = "<<rArea; 
	outFile<< ", parameter = "<< pmeter << endl <<endl; 
	outFile<< "Circle: "<<endl << "Radius = "<< radius << ", area = "<< cArea <<", circumference = "<< circum<< endl << endl;
	outFile<< "Name: "<< fname << " " << lname <<", age: "<< age << endl;
	outFile<< "Beginning balance = $" << beginBal << ", interest rate = "<< interest<< endl;
	outFile<< "Balance at the end of the month = $"<< endBal << endl << endl;
	outFile<< "The character that comes after "<< ch << " in the ASCII set is "<< ch2;
	
	
	inFile.close();
	outFile.close();
	return 0;
}
