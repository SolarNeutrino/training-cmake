#include <iostream>
#include "TheStaticLib.h"
using namespace std;


extern "C" int FooFunction(int n)
{
	cout << "FooFunction ( n=" << n << ") called" << endl;
	return n * 2;
}