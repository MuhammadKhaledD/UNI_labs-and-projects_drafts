
#include <iostream>
using namespace std;

#include "CFigList.h" 

//[TODO]: --> after the first run,
// Fix the bused dynamic_cast using polymorphism and virtual functions to generate the same output but without breaking class responsibilities, as follows:
//	-Add PrintInfo() function inside class CFigure, CRect and CTriangle
//	-Decide if it should be non-virtual, virtual or pure virtual
//	-Update function FigList::PrintInfo() after using polymorphism 
//   and replace the abused dynamic_cast.
//	-Make the same 3 steps above for function DisplayPerimeters().
//	-Run the modified code and make sure that it generates the same output as before.


// A global function to add figures to the FigList object
void AddFiguresToList(CFigList& figList)
{
	int nChoice=0;
	
	do
	{
		cout<<endl<<"========================="<<endl;
		cout<<"[1] Add a Rectangle"<<endl;
		cout<<"[2] Add a Triangle"<<endl;
		cout<<"[3] Return to main menu"<<endl;
		cout<<"========================="<<endl;
		cout<<"Select an operation <1-3> :";
		cin>>nChoice;	

		if (nChoice == 3)
			return;
		
		figList.AddNewFigure(nChoice); 

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
		cout<<"\t\t[2] Print info of all figures"<<endl;
		cout<<"\t\t[3] Display perimeter of all figures"<<endl;
		cout<<"\t\t[4] Exit"<<endl<<endl;
		cout<<"\t\t********************************************"<<endl;
		cout<<"Select an operation <1-4> :";
		cin>>nChoice;	
		
		switch (nChoice)
		{
		case 1:
			AddFiguresToList(figList);
			break;
		case 2:
			figList.PrintInfo();
			break;
		case 3:
			figList.DisplayPerimeters();
			break;
		default:
			return;
		}
	}while(1);	

}
