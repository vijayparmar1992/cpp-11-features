/*
* The constexpr keyword is powerful feature that enables 
* compile time evaluation of expresions, functions and objects.
*/


#include <iostream>
using namespace std;

constexpr int multiply(int a)
{
	return a * 5;
}

int main()
{
	constexpr int a = 46; // a is compile-time constant
	static_assert(a == 46, "Init a error");

	int x = multiply(10); // // Guaranteed compile-time evaluation
	static_assert(multiply(10) == 100, "multiply() error"); // Error during compilation

	return 0;
}