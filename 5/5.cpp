#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main() {
	
int i, type, numberOfTickets, boxTickets, sidelineTickets, premiumTickets, generalTickets;
ofstream outFile;
	for( i=0 ; i<4 ; i++){
		
		cout << "Enter the type of ticket:  1-Box 2-Sideline 3-Premium 4-General" <<endl;
		cin >> type;
		cout << "Enter number of tickets sold: ";
			switch(type) {
				case 1:
					cin >> boxTickets;
					break;
				case 2:
					cin>> sidelineTickets;
					break;
				case 3:
					cin>> premiumTickets;
					break;
				case 4:
					cin>> generalTickets;
					break;
				default:
					cout<< 	"Invalid input";
			}
	}
	
double priceBox, priceSideline, pricePremium, priceGeneral;
	priceBox = 250*boxTickets;
	priceSideline = 100*sidelineTickets;
	pricePremium = 50*premiumTickets;
	priceGeneral = 25*generalTickets;
	
	outFile.open( "ticketinfo5.txt" );
	outFile << fixed << setprecision(2);
	outFile << boxTickets << "  " << priceBox << endl;
	outFile << sidelineTickets << "  " << priceSideline << endl;	
	outFile << premiumTickets << "  " << pricePremium << endl;
	outFile << generalTickets << "  " << priceGeneral << endl;
	outFile.close();
return 0;
}
