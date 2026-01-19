#include <iostream>
using namespace std;

#include "CFigList.h" // "CFigure.h" is included inside it
#include "CSquare.h"  // "CRect.h" is included inside it

// A global function to add figures to the FigList object
//     Note that it's passed by reference 
//     in order to make the change of "m_nFigCount" remains after return
void AddFiguresToList(CFigList& figList)
{
	int nChoice=0;
	
	do
	{
		cout<<endl<<"========================="<<endl;
		cout<<"[1] Add a Rectangle"<<endl;
		cout<<"[2] Add a Square"<<endl;
		cout<<"[3] Return to main menu"<<endl;
		cout<<"========================="<<endl;
		cout<<"Select an operation <1-3> :";
		cin>>nChoice;	

		if (nChoice == 3)
			return;
		
		figList.AddNewFigure((FigureType)nChoice); // ((FigureType)nChoice): 
		                                           // just cast the int nChoice to FigureType enum
	}while(1);
	
}


// =========== The Main Function =========== 
void main()
{
	CFigList figList;		
	int nChoice=0;
	
	do
	{
		cout<<endl;
		cout<<"\t\t**********      Main Menu   ***************"<<endl<<endl;
		cout<<"\t\t[1] Add a new figure"<<endl;
		cout<<"\t\t[2] Display areas for all figures"<<endl;
		cout<<"\t\t[3] Exit"<<endl<<endl;
		cout<<"\t\t********************************************"<<endl;
		cout<<"Select an operation <1-3> :";
		cin>>nChoice;	
		
		switch (nChoice)
		{
		case 1:
			AddFiguresToList(figList);
			break;
		case 2:
			figList.DisplayAreas();
			break;
		default:	
			cout << "\n========== Notice which destructors of the created figures will be called? ==========";
			cout << "\nThe destructors of the pointer type 'CFigure' or of object";
			cout << "\nor of the object type 'CRect' or 'CSquare??'\n\n";
			return;
		}
	}while(1);	

	
	// Q:  which destructors of the created figures will be called?
	// The destructors of the pointer type 'CFigure' or of object?
	// or of the object type 'CRect' or 'CSquare?
	// how we can change that??
}
