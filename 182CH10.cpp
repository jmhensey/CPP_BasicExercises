// 182CH10.cpp : Defines the entry point for the console application.
// Creator: Julianna Hensey
// Date: 2010/04/03
// Assumptions: User will not fail the input stream

#include <fstream>
#include <climits>
#include <cfloat>
#include <iostream>
using namespace std;
void Menu (/*out*/ short&);

int main ()
{
	//Part 1: Practice with sizeof operator
	int iAnyInt;
	int iAnyLong;
	short shAnyShort;
	ofstream ofReportFile;
	ofReportFile.open ("report.txt");
	ofReportFile << "Size of short integer is: " << sizeof (shAnyShort) << endl;
	ofReportFile << "Size of int type is: " << sizeof (iAnyInt) << endl;
	ofReportFile << "Size of long type is: " << sizeof (iAnyLong) << endl;
	ofReportFile << "Size of float type is: " << sizeof (float) << endl;
	ofReportFile << "Size of double type is: " << sizeof (double) << endl;
	ofReportFile << "Size of long double type is: " << sizeof (long double) << endl;

	//Part 2: Practice with machine-dependent limits
	ofReportFile << "Minimum short is: " << SHRT_MIN << endl;
	ofReportFile << "Maximum short is: " << SHRT_MAX << endl;
	ofReportFile << "Minimum int is: " << INT_MIN << endl;
	ofReportFile << "Maximum int is: " << INT_MAX << endl;
	ofReportFile << "Minimum long is: " << LONG_MIN << endl;
	ofReportFile << "Maximum long is: " << LONG_MAX << endl;
	ofReportFile << "Minimum float is: " << FLT_MIN << endl;
	ofReportFile << "Maximum float is: " << FLT_MAX << endl;
	ofReportFile << "Minimum double is: " << DBL_MIN << endl;
	ofReportFile << "Maximum double is: " << DBL_MAX << endl;
	ofReportFile << "Minimum long double is: " << LDBL_MIN << endl;
	ofReportFile << "Maximum long double is: " << LDBL_MAX << endl;
	ofReportFile << "Maximum unsigned short is: " << USHRT_MAX << endl;
	ofReportFile << "Maximum unsigned int is: " << UINT_MAX << endl;
	ofReportFile << "Maximum unsigned long is: " << ULONG_MAX << endl;

	//Part 3: Practice with enumerator and switch
	enum eSports {BASEBALL, SOCCER, FOOTBALL, SWIMMING, TRACK, HOCKEY, TENNIS, BASKETBALL};
	eSports esprtThisSport; 
	short shUserSport; //sport of user's choice
	Menu (shUserSport); //Menu display and priming read of shUserSport
	while (shUserSport != 0) //input of 0 == quit loop
	{
		//associate user input with enumerated values
		if (shUserSport == 1)
			esprtThisSport = BASEBALL;
		else if (shUserSport == 2)
			esprtThisSport = SOCCER;
		else if (shUserSport == 3)
			esprtThisSport = FOOTBALL;
		else if (shUserSport == 4)
			esprtThisSport = SWIMMING;
		else if (shUserSport == 5)
			esprtThisSport = TRACK;
		else if (shUserSport == 6)
			esprtThisSport = HOCKEY;
		else if (shUserSport == 7)
			esprtThisSport = TENNIS;
		else if (shUserSport == 8)
			esprtThisSport = BASKETBALL;
		switch (esprtThisSport)
		{
		case FOOTBALL:
		case SOCCER: cout << "This is a fall sport" << endl;
			break;
		case HOCKEY:
		case BASKETBALL:
		case SWIMMING: cout << "This is a winter sport" << endl;
			break; 
		default: cout << "This is a spring sport" << endl;
		}
		Menu (shUserSport);
	}
	return 0;
}
void Menu (/*out*/ short& shUserSport)
{
	cout << "This is a list of sports:" << endl;
	cout << "1 BASEBALL" << endl; 
	cout << "2 SOCCER" << endl;
	cout << "3 FOOTBALL" << endl;
	cout << "4 SWIMMING" << endl;
	cout << "5 TRACK" << endl;
	cout << "6 HOCKEY" << endl;
	cout << "7 TENNIS" << endl;
	cout << "8 BASKETBALL" << endl;
	cout << "Select number of a sport, or 0 to quit" << endl;
	cin >> shUserSport;
	//range validation loop
	while (shUserSport > 8 || shUserSport < 0)
	{
		cout << "Invalid selection -- valid range is 0 to 8" << endl;
		cout << "Select number of a sport, or 0 to quit" << endl;
		cin >> shUserSport;
	}
}