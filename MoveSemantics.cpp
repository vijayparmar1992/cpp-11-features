#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MyClass {
private:
	int value;
	int* ptr = nullptr;
public:

	MyClass()
	{
		value = 0;
		ptr = new int();
	}

	MyClass(const MyClass& other)
	{
		cout << "In copy constructr" << endl;
		value = other.value;
		ptr = new int(*other.ptr); // deep copy
	}

	MyClass& operator=(const MyClass& other)
	{
		cout << "In copy assigment operator" << endl;
		if (this != &other)
		{
			value = other.value;
			delete ptr; 
			ptr = new int(*other.ptr); // deep copy
		}
		return *this;
	}


	MyClass(MyClass&& other) noexcept
	{
		cout << "In move copy constructor" << endl;
		value = other.value;
		ptr = other.ptr;
		other.value = 0;
		other.ptr = nullptr;
	}

	MyClass& operator=(MyClass&& other) noexcept
	{
		cout << "In move assigment operator" << endl;
		if (this != &other)
		{
			value = other.value;
			delete ptr;
			ptr = other.ptr;
			other.value = 0;
			other.ptr = nullptr;
		}
		return *this;
	}
};

// In move functions, there is no new memory allocation. Hence, we can assign noexcept,
// as there would be no throw under any circumstances
// noexcept enbales STL optimizations  

void print(MyClass&& m)
{
	cout << "In print()" << endl;
}


int main()
{
	MyClass lkg, skg;
	skg = std::move(lkg);
	print(std::move(skg));

	MyClass primary, secondary;
	secondary = primary; // This would throw if, custom copy assigment operator is not defined
	MyClass higherSecondary = secondary; // This would throw if, custom copy ctor is not defined

	return 0;
}