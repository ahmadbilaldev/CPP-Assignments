#include <iostream>
#include <stdio.h>
using namespace std;

class flight
{
  private:
    int flight;
    float destination, distance, fuelRequired;
    char passengerName[10];
    float calcFuel()
    {
        if (distance <= 1000)
        {
            fuelRequired = 500;
        }
        else if (distance > 1000 && distance <= 2000)
        {
            fuelRequired = 1100;
        }
        else
        {
            fuelRequired = 1300;
        }
    }

  public:
    student()
    {
        cout << "Enter admission number: " << endl;
        cin >> admissionNum;
        cout << "Enter student name: " << endl;
        cin >> stdName;
        cout << "Enter English marks: " << endl;
        cin >> engMarks;
        cout << "Enter Math marks: " << endl;
        cin >> mathMarks;
        cout << "Enter Science marks: " << endl;
    }
    void showData()
    {
        cout << "Student name: " << stdName << endl;
        cout << "Admission number: " << admissionNum << endl;
        cout << "English Marks: " << engMarks << endl;
        cout << "Math Marks: " << mathMarks << endl;
        cout << "Science Marks: " << scienceMarks << endl
             << endl;
        calcTotal();
        cout << "Total Marks: " << totalMarks << endl;
    }
};
int main()
{
    student student1;

    student1.showData();
    system("pause");
    return 0;
}