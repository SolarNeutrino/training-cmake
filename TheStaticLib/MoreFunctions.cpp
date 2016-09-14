#include <iostream>
#include "TheStaticLib.h"
using namespace std;


extern "C" int FooFunction(int n)
{
	cout << "FooFunction ( n=" << n << ") called" << endl;
	return n * 2;
}

// The staticDll will extern this function 
extern int DllCustomize(int n);
extern "C" int FeeFunction(int n)
{
	cout << "FeeFunction ( n=" << n << ") called and calling DllCustomize.." << endl;
	return DllCustomize(n);
}

// The staticDll will extern this function 
extern int DllCustomizeInternal(int n);
int FeeFunctionInternal(int n)
{
	cout << "FeeFunctionInternal ( n=" << n << ") called and calling DllCustomizeInternal.." << endl;
	return DllCustomizeInternal(n);
}