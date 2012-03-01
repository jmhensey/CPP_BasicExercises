//savings.h: include file for information regarding a savings account.
//This file gives the specification of a cSavings abstract data type
//that will characterize a bank account.
struct Date
{
	int iYear;
	int iMonth;
	int iDay;
}; 
class cSavings
{
private:
	int iAccountID;        //ID number for the account
	string sLastName;	   //Last name of patron
	Date dCreated;		   //Date the account was created
	short shStatus;		   //Status of the account (1 = active/0 = inactive)
	float fCurrentBal;	   //Current balance of the account

public:	
	//Description: Constructor
	//post: numberic members are set to 0 or 0.0 and the Last Name has been set to NONE
	cSavings ();

	//description: Creates new information for a bank account.
	//pre: iAccountID, sLastName, dCreated, shStatus, and fCurrentBal have been assigned
	//post: all private members of object have been assigned from user supplied values
	void Create (/*in*/ int iNewAccountID, 
				/*in*/ string sNewLastName, 
				/*in*/ Date dNewCreated, 
				/*in*/ short shNewStatus, 
				/*in*/ float fNewBal);
	
	//description: Changes account status to Active
	//post: status of account is now "Active" (shStatus = 1)
	void MakeActive ();
	
	//description: Changes account status to Inactive
	//post: status of account is now "Inactive" (shStatus = 0)
	void MakeInactive ();
	
	//description: Updates the balance in the recorded savings account as outlined by the user
	//pre: fNewBal has been assigned
	//post: fCurrentBal == fNewBal
	void UpdateBal (/*in*/ float fNewBal);
	
	//description: Accesses all of the values of the Bank Account and displays them to the user
	//post: displays all values of object
	void Report () const;
	
};