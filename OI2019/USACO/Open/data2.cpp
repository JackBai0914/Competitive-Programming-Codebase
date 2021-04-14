#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

int n = 30000;
int k = 6;

int main() {
	srand(time(0));
	// srand((unsigned long long)(new char()));
	// k = rand() % 3 + 4;
	cout << n << " " << k << endl;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < k; j ++)
			cout << rand() % 1 + 1 << " ";
		cout << endl;
	}
	for (int i = 1; i <= k; i ++) {
		for (int j = 1; j < n; j ++)
			cout << rand() % 1 + 1 << " ";
		cout << endl;
	}
	return 0;
}
