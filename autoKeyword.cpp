#include <iostream>
#include <vector>
using namespace std;

// Generic programming
template <typename T, typename U>
auto add(T a, U b)
{
	return a + b;
}


int main()
{
	auto x = 11; // x is deduced as int
	auto y = 11.21; // y is deduced as double
	auto name = "Anmol"; // name is deduced as char*
	cout << typeid(name).name() << endl;

	vector<int> vect = { 1,2,3,4 };
	auto it = vect.begin(); // dedeuced as vector<int>::iterator it

	// Range-based for loops
	for (auto& element : vect)
		cout << element << " ";

	cout << endl;

	// Use of auto for generic programming
	auto addInt = add(5, 3);
	cout << "Init type addtion is " << addInt << endl;
	auto addFloat = add(5.11, 3.22);
	cout << "Float type addtion is " << addFloat << endl;

	/*
	* By default, auto strips away reference and const qualifiers.
	* To preserve them use auto& or const auto&
	*/
	const int& myRef = x;
	auto ref = myRef; // ref is deduced as int, const and reference are dropped.
	const auto& newRef = myRef;

	// auto requires an intializer to deduce the type
	auto myVar; // Error as initializer required.

	return 0;
}