
#include <iostream>
#include "TheDll.h"
#include "TheStaticLib.h"
using namespace std;

#include "gtest/gtest.h"
TEST(Training, FooFunction)
{
	EXPECT_EQ(FooFunction(2), 4);
}
TEST(Training, FeeFunction)
{
	EXPECT_EQ(FeeFunction(2), 6);
}
int main(int argc, char** argv)
{
	cout << "The Dll Tests" << endl; // prints !!!Hello World!!!
	::testing::InitGoogleTest(&argc, argv);
	int status = RUN_ALL_TESTS();
	return status;
}
