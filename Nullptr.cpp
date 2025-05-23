/*
* Prior to c++11, the literal 0 or the macro NULL, were commonly
* used to represent null pointers.
* However, these approaches had limitations and could lead to
* ambiguity or errors in certain contexts.
* nullptr aligns with C++'s emphasis on type safety and expressiveness, making code
* more readable and maintainable.
*/


#include <iostream>
using namespace std;

void foo(int a)
{
	cout << "Called foo(int)" << endl;
}

void foo(char* a)
{
	cout << "Called foo(char*)" << endl;
}

void handleNullPointer(nullptr_t ptr)
{
	cout << "Handling nullptr" << endl;
}

int main()
{
	// Ambuiguity in overloaded functions
	/*
	* The literal 0 is of type int, so the compiler prefers the foo(int) overload.
	* Even though 0 can be implicitly converted to a char*, the compiler chooses
	* the exact match (int) over a conversion (int to char*).
	*/
	foo(0); // Calls to foo(int), not foo(char*)
	foo(nullptr); // Calls to foo(char*). Avoids ambuiguity!

	// Type safety issues
	int* ptr = NULL;
	int x = NULL; // Compiles, but logically incorrect

	/*
	* nullptr is of type std::nullptr_t, which is implicitly
	* convertible to any pointer type but not to other(integer) types.
	* This eliminates the risk of accidental conversions
	*/
	int* ptr1 = nullptr;
	// int y = nullptr; // Error: cannot convert nullptr to int

	// Checking for nullptr
	if (ptr1 == nullptr)
		cout << "Pointer is null" << endl;

	// Std::nullptr_t type
	handleNullPointer(nullptr);

	return 0;
}