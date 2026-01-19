
#include "CRect.h"

#include <iostream>
using namespace std;

void main()
{
	CRect R(1, 10, 20 ,30, 40);
	
	// ======================= Function Overriding =======================

	cout<<"\n//******* Function Overriding ***********//\n";

	// 1- Calling Functions that Exists in Base Class Only:
	cout<<"\nCalling functions that exists in base class only";
	cout<<"\nRect ID="<<R.getID();

	// 2- Calling Functiona that Exists in Both Base and Derived Classes:
	cout<<"\n\nCalling function that is in both base and derived classes";
	cout<<"\nCalling PrintInfo(), which one is called??";
	R.PrintInfo();	// Q: CRect has 2 version of PrintInfo() as mentioned before,
	                // which one is called??
	

	cout<<"\n\n//******* Upcasting and Downcasting ***********//\n";
	cout<<"\n ====== A- Upcasting and Downcasting objects: ====== \n";

	// ======================= A-1: Upcasting Objects =======================

	cout<<"\n1- Upcasting to call CFigure::PrintInfo from CRect Object";
	cout<<"\nUpcasting ==> SAFE";
	// Notice how the parentheses () is used in casting
	((CFigure)R).PrintInfo(); // [Important] Note that casting in general makes temp obj/ptr,
	                          // so here this object upcast make a temp object of type CFigure
	                          // that copies the inherited CFigure part existing inside R

	// [Advanced] if you want to reach the CFigure part inside R
	// not make a temp copy of it through casting, you can write:
	// R.CFigure::PrintInfo(); // Uncomment this line and rerun

	// Q: what is the type of the object R after the upcasting line?
	// Is R's type changed to CFigure??

	// ======================= A-2: Downcasting Objects =======================

	cout<<"\n\n2- Downcasting, can you donwcast objects??? ";
	CFigure F(2);
	
	// Q: Can You downcast objects the same way? 
	// Uncomment next line and see if there is a problem
	// ((CRect)F).PrintInfo();

	cout<<"\n\n\n ====== B- Upcasting and Downcasting Pointers: ====== ";

	// ======================= B-1: Upcasting Pointers =======================

	CRect *pR = new CRect(5, 100, 200, 300, 400);

	cout<<"\n\nNormal ==> Use CRect Pointer to call CRect::PrintInfo() ==> OK";
	pR->PrintInfo(); // Q: which PrintInfo() version is called?

	cout<<"\n\n1- Upcasting ==> Use CRect Pointer to call CFigure::PrintInfo() ==> OK, SAFE";
	((CFigure*)pR)->PrintInfo();	// here a temp pointer is created (NOT object)
	                                // and this temp pointer is pointing to the same original object
	delete pR;
	// ======================= B-2: Downcasting Pointers =======================

	CFigure * pF;
	pF = new CFigure(3);

	cout<<"\n\nNormal ==> Use CFigure Pointer to call CFigure::PrintInfo() ==> OK";
	pF->PrintInfo(); // Q: which one is called? Simple!

	cout<<"\n\n2- Downcasting ==> Use CFigure Pointer to call CRect::PrintInfo() ==> NOT SAFE, may work/may not";
	((CRect*)pF)->PrintInfo(); // Here: it will not work and will go to undefined behavior
	                           // because pF points to CFigure obj and we downcast to CRect
	                           // Q:  run and see what will happen here.

	delete pF;

	cout<<"\n\nGuess when downcast may work.....";
	cout<<"\n\nBase class pointer pF points to object of a derived class CRect";

	// Base class pointer pF points to object of a derived class CRect
	pF = new CRect(6, 100, 200, 300, 400); 

	cout<<"\n\nWhich PrintInfo() verion will be called in: pF->PrintInfo(); ??";
	pF->PrintInfo();           // Q: which PrintInfo() version will be called??

	cout<<"\n\nWhich PrintInfo() verion will be called in: ((CRect*)pF)->PrintInfo(); ??";
	((CRect*)pF)->PrintInfo(); // Q: which PrintInfo() version will be called??

	cout<<"\n\nIs the the previous pointer downcast safe??";

	delete pF;

	cout<<endl;

	char c; cin>> c;
}