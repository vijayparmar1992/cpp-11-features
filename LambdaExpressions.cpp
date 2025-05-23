/*
* Lambda expressions enables the creation of anonymous functions
* directly within code.
* 
* [capture_clause] (parameter) -> return_type
* { function body }
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto square = [](int x) {return x * x; };

int main()
{
	int a = 5; int b = 12;
	auto lambda = [=]() -> int {return a + b; }; // Captures all variables by value
	cout << lambda() << endl;

	auto lambdaR = [&]() {a += 10; }; // Captures all variables by value
	lambdaR(); // Executing lambdaR
	cout << a << endl;
	cout << square(10) << endl;

	// Capturing local state
	vector<int>vect = { 1,2,3,4,5 };
	int sum = 0;
	for_each(vect.begin(), vect.end(), [&sum](int v) {sum += v; });
	cout << sum << endl;

	// If a lambda captures variables by value and needs to modify them, use the mutable keyword
	int y = 0;
	auto mutableLambda = [y]()mutable {y++; cout << y << endl; }; // copy of y will get updated
	mutableLambda();
	cout << y << endl;

	return 0;
}