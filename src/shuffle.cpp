#include "shuffle.h"
#include <random>
#include <utility>

using namespace std;

void shuffle(vector<int>& a)
{
	random_device rd;
    mt19937 mt(rd());

    for (int i = a.size() - 1; i >= 1; i--) {
        uniform_int_distribution<int> dist(0, i);
        int j = dist(mt);
        swap(a[i], a[j]);
    }
}
