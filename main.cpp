#include "shuffle.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> a = {1, 2, 3, 4};
	shuffle(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return EXIT_SUCCESS;
}
