// CPP program to illustrate swapping
// of two vectors using std::vector::swap()

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v1 = { 1, 2, 3 , 5};
	vector<int> v2 = { 4, 5, 6 };

	// swapping the above two vectors
	// using std::vector::swap
	v1.swap(v2);

	// print vector v1
	cout << "Vector v1 = ";
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}

	// print vector v2
	cout << "\nVector v2 = ";
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}

	return 0;
}
