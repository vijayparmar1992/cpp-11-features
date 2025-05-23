#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	vector<int> vect = { 1,2,3,4,5 };

	for (auto vec : vect)
		cout << vec << " ";

	for (auto& vec : vect)
	{
		vec = vec * 2;
	}

	for (auto vec : vect)
		cout << vec << " ";

	cout << endl;

	// Iterating over standard containers
	unordered_map<string, int>ids = { {"Vijay",1}, {"Sanjay",2} };

	for (const auto& id : ids)
		cout << id.first << " " << id.second << endl;

	return 0;
}