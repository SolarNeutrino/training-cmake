#include <iostream>
using namespace std;
#include "TheDll.h"
#include "TheStaticLib.h"

int main()
{
	cout << "fnTheDll() returned " << fnTheDll() << endl;
	int n = FooFunction(2);
	cout << "App Got  " << n << " From FooFunction(2)" << endl;
	return 0;
}