// 182CH12.cpp : Defines the entry point for the console application.
// Author: Julianna Hensey
// Date: 2010/4/9
// Purpose: to practice using class objects and structs in creating a database style program
// along the lines of the final inventory program.
// Assumptions: user will not fail the input stream

#include <iostream>
#include <string>
using namespace std;
#include "savings.h"

int main ()
{
	int iResponse; //user selection from menu
	int iNewID;
	string sNewLastName;
	Date dNewCreated;
	char cActive;
	short shNewStatus;
	float fNewBal;

	//initialize account
	cSavings thisSavings;
	cout << "Object created with these values:" << endl;
	thisSavings.Report ();

	//main loop. will quit on iResponse == 6
	do
	{
		//Menu
		cout << endl << "What action do you wish to take? Enter integer:" << endl;
		cout << "1 Enter values for savings account" << endl;
		cout << "2 Set status to be inactive" << endl;
		cout << "3 Set status to be active" << endl;
		cout << "4 Update the current balance" << endl;
		cout << "5 Display all values for account" << endl;
		cout << "6 QUIT program" << endl;
		cin >> iResponse; //receive user's choice

		//data range check
		while (iResponse < 1 || iResponse > 6)
		{
			cout << "Invalid Selection. Please Select a number from 1 to 6" << endl;
			cin >> iResponse;
		}

		//Create new savings account
		if (iResponse == 1)
		{
			cout << "Enter account ID as positive integer: ";
			cin >> iNewID;
			cout << "Enter last name of account owner: ";
			cin >> sNewLastName;
			cout << "Enter date opened in form YEAR MONTH DAY separated by spaces: ";
			cin >> dNewCreated.iYear >> dNewCreated.iMonth >> dNewCreated.iDay;
			
			//date validation loop
			while (dNewCreated.iMonth < 1 || dNewCreated.iMonth > 12 || dNewCreated.iDay < 1 || dNewCreated.iDay > 31)
			{
				cout << "Invalid date" << endl;
				cout << "Enter date opened in form YEAR MONTH DAY separated by spaces: ";
				cin >> dNewCreated.iYear >> dNewCreated.iMonth >> dNewCreated.iDay;
			}
			cout << "Set account initially active? Y or N: ";
			cin >> cActive;
			cActive = toupper (cActive);
			if (cActive == 'Y')
				shNewStatus = 1;
			else
				shNewStatus = 0;
			cout << "Enter Beginning Balance: $";
			cin >> fNewBal;
			thisSavings.Create (iNewID, sNewLastName, dNewCreated, shNewStatus, fNewBal);
			thisSavings.Report ();
		}

		//Make account inactive
		else if (iResponse == 2)
		{
			thisSavings.MakeInactive ();
			cout << "Account now inactive" << endl;
		}

		//Make account active
		else if (iResponse == 3)
		{
			thisSavings.MakeActive ();
			cout << "Account now active" << endl;
		}

		//Update value of Balance
		else if (iResponse == 4)
		{
			cout << "Enter amount of updated balance: $";
			cin >> fNewBal;
			thisSavings.UpdateBal (fNewBal);
			cout << "Balance updated to $" << fNewBal << endl;
		}

		//Report values of the savings account
		else if (iResponse == 5)
			thisSavings.Report ();

	}while (iResponse != 6); //exit value

	return 0;
}

