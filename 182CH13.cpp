// 182CH13.cpp : Defines the entry point for the console application.
// Author: Julianna Hensey
// Date: 2010/4/28
// Purpose: learn selection sort and adding and deleting numbers from a sorted list
// Assumptions: User will not fail the input stream

#include <iostream>
using namespace std;
//function declarations
void PrintList (int[], int&);
void SelectionSort (int[],int);
bool BinarySearch (int[], int, int, int&);

int main ()
{
	char cReply;		//y or n for repeat program
	do
	{
		int iArray[8];
		int iArraySize;		//amount of items in array
		int iAdded;			//number to be inserted into array
		int iNumtoDelete;	//number to be deleted from array
		int iLocation;		//holds addresses of array while inserting or deleting in sorted list
		int iPlace;			//location of iNumtoDelete in the array
		int iWorked;		//whether number was found in array in Binary Search


		//prompt for size of array
		cout << "How many values (maximum 6) do you wish to load into the list? ";
		cin >> iArraySize;
		//data validation loop
		while (iArraySize > 6 || iArraySize < 1)
		{
			cout << "Value must be in range of 1 to 6" << endl;
			cout << "Please re-enter: ";
			cin >> iArraySize;
		}


		//prompt for integers in array
		for (int iCount = 0; iCount < iArraySize; iCount++)
		{
			cout << "Enter any integer to the list: ";
			cin >> iArray[iCount];
		}

		cout << "Entered List values are: " << endl;
		PrintList (iArray, iArraySize);	//sends values of array to the console


		//insert integer into unsorted list
		cout << "Enter integer value to insert: ";
		cin >> iAdded; 
		iArray[iArraySize] = iAdded;
		iArraySize++;		//increment iArraySize
		cout << "Unsorted List values are: " << endl;
		PrintList (iArray, iArraySize);


		//create sorted array from values given
		SelectionSort (iArray, iArraySize);
		cout << "Sorted List values are: " << endl;
		PrintList (iArray, iArraySize);


		//insert integer into sorted list
		cout << "Enter integer value to insert: ";
		cin >> iAdded;
		iLocation = iArraySize - 1;	//starts at bottom of array
		//loop to compare until proper place found in sorted list
		while (iLocation >= 0 && iAdded < iArray[iLocation])
		{
			iArray[iLocation + 1] = iArray[iLocation];
			iLocation--;
		}
		//insert iAdded into array
		iArray[iLocation+1] = iAdded;
		iArraySize++;
		//print result to console
		cout << "Sorted List values are: " << endl;
		PrintList (iArray, iArraySize);


		//delete integer from array
		cout << "Enter integer value to delete: ";
		cin >> iNumtoDelete;
		iWorked = BinarySearch (iArray, iArraySize, iNumtoDelete, iPlace);
		if (iWorked == false)
			cout << "Value not found in list" << endl;
		else
		{
			iLocation = iPlace;
			while (iLocation <= iArraySize)
			{
				iArray[iLocation] = iArray[iLocation + 1];
				iLocation++;
			}
			iArraySize--;	//decrease array size to accomodate deletion
			//print result to console
			cout << "Sorted List values are: " << endl;
			PrintList (iArray, iArraySize);
		}

		cout << endl;

		//prompt user for repeat of program
		cout << "Repeat program? y or n: ";
		cin >> cReply;
		cReply = toupper (cReply);


	}while (cReply == 'Y');
}
//description: prints values of array to screen
//pre: iSizeofArray and iArrayIn[] have been assigned
//post: values of the array have been sent to console
void PrintList (/*in*/ int iArrayIn[],
				/*in*/ int& iSizeofArray)
{
	for (int iCount = 0; iCount < iSizeofArray; iCount++)
	{
		cout << iArrayIn[iCount] << " ";

		//line break after 10th number
		if (iCount == 9)
			cout << endl;
	}
	cout << endl;
}
//description: takes unsorted list and sorts it in ascending order
//pre: 
void SelectionSort (/*in*/ int iArrayIn[], 
					/*in*/ int iSizeofArray)
{
	int iTempStorage;
	int iMin;   //minimum number 
	int iInnerCount;

	for (int iOuterCount = 0; iOuterCount < iSizeofArray; iOuterCount++)
	{
		iMin = iOuterCount;
		// Find index of smallest value left
		for (iInnerCount = iOuterCount + 1; iInnerCount < iSizeofArray; iInnerCount++)
			if (iArrayIn[iInnerCount] < iArrayIn[iMin])
				iMin = iInnerCount;
		iTempStorage = iArrayIn[iMin]; 	// Swap 
		iArrayIn[iMin] = iArrayIn[iOuterCount];
		iArrayIn[iOuterCount] = iTempStorage;
	}
}
//description: searches for a number within a sorted array
//pre: iArrayIn[] is sorted and iSizeofArray and iNumtoFind have been assigned
//post: iPosition has been assigned
bool BinarySearch (/*in*/ int iArrayIn[], 
				   /*in*/ int iSizeofArray,
				   /*in*/ int iNumtoFind,	//number to search for
				   /*out*/ int& iPosition)	//position of iNumtoFind
{
	int iMiddle;
	int iFirst =  0;
	int iLast = iSizeofArray - 1;
	bool bFound = false;
	while (iLast >= iFirst && !bFound)
	{	 iMiddle = (iFirst + iLast)/2; // Index of middle element

	if (iNumtoFind < iArrayIn[iMiddle])     
		iLast = iMiddle - 1;	 // Look in first half next 
	else if (iNumtoFind > iArrayIn[iMiddle])   	 
		iFirst = iMiddle + 1;	 // Look in second half next
	else
		bFound = true;	   	 // Item  has been found
	}
	if  (bFound) 
	{
		iPosition = iMiddle;
		return true;
	}
	else return false;
}