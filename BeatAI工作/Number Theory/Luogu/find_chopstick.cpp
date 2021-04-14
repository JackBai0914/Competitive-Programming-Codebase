#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int lst[20000020];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		lst[i] = lst[n + i] = i;
	random_shuffle(lst + 1, lst + 2 * n + 1);

	cout << '[';
	for (int i = 1; i < 2 * n; i ++) {
		cout << lst[i];
		if (i + 1 != 2 * n)
			cout << ", ";
	}
	cout << ']' << endl;

	cout << lst[2 * n] << endl;
	return 0;
}

	