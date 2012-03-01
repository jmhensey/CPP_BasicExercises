// savings.cpp: source file in association with savings.h
// creator: Julianna Hensey
// date: 2010/4/7
// This source file includes the function definitions for all 
// functions within the savings.h header file.
// Assumptions: all values passed into functions are within the 
// range that they should be.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "savings.h"

//constructor
cSavings::cSavings ()
{
	iAccountID = 0;
	sLastName = "NONE";
	dCreated.iYear = 0;
	dCreated.iMonth = 0;
	dCreated.iDay = 0;
	shStatus = 0;
	fCurrentBal = 0.0f;
}
void cSavings::Create (int iNewID, string sNewLastName, Date dNewCreated, short shNewStatus, float fNewBal)
{
	iAccountID = iNewID;
	sLastName = sNewLastName;
	dCreated = dNewCreated;
	shStatus = shNewStatus;
	fCurrentBal = fNewBal;
}
void cSavings::MakeActive ()
{
	shStatus = 1;

}
void cSavings::MakeInactive ()
{
	shStatus = 0;
}
void cSavings::UpdateBal (float fNewBal)
{
	fCurrentBal = fNewBal;
}
void cSavings::Report () const
{
	cout << "Account ID:    " << iAccountID << endl;
	cout << "Last name:          " << sLastName << endl;
	cout << "Date opened:   ";
	if (dCreated.iYear == 0)
		cout << "000";
	cout << dCreated.iYear << "-";
	if (dCreated.iMonth < 10)
		cout << "0";
	cout << dCreated.iMonth << "-";
	if (dCreated.iDay < 10)
		cout << "0";
	cout << dCreated.iDay << endl;
	cout << "Status:        ";
	if (shStatus == 0)
		cout << "INACTIVE" <<endl;
	else 
		cout << "ACTIVE" << endl;
	cout << "Balance:       $" << fixed << setprecision (2);
	cout << fCurrentBal << endl;
}