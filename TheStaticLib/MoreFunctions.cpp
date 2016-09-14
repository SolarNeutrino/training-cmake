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