// TheDll.cpp : Defines the exported functions for the DLL application.
//
#include <iostream>
using namespace std;

#include "TheDll.h"


// This is an example of an exported variable
THEDLL_API_SYMBOL int nTheDll=0;

// This is an example of an exported function.
THEDLL_API int fnTheDll(void)
{
	cout << "fnTheDll" << endl;
    return 42;
}

// This is the constructor of a class that has been exported.
// see TheDll.h for the class definition
CTheDll::CTheDll()
{
	cout << "CTheDll Constructor" << endl;

    return;
}

// The staticDll will extern this function 
int DllCustomize(int n)
{
	cout << "DllCustomize (n =" << n << " ) called." << endl;
	return n * 3;
}
// The staticDll will extern this function 
// This will be used by a Function NOT exposed via DEF (say called from interrupt)
int DllCustomizeInternal(int n)
{
	cout << "DllCustomizeInternal (n =" << n << " ) called." << endl;
	return n * 3;
}