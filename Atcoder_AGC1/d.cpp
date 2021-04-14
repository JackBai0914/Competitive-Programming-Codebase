#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int a[1000010];
int b[1000010], bst = 0;

void deal_head () {
	if (a[1] % 2)
		for (int i = 1; i < a[1]; i += 2)
			b[++ bst] = 2;
	else {
		int i = 1;
		for (; i < a[1] / 2; i += 2)
			b[++ bst] = 2;
		b[++ bst] = 1;
		i ++;
		for (; i < a[1]; i += 2)
			b[++ bst] = 2;
	}
}

void deal_tail () {
	if (a[m] % 2) {
		b[++ bst] = 2;
		for (int i = 1; i < a[m]; i += 2)
			b[++ bst] = 2;
	}
	else {
		b[++ bst] = 2;
		int i = 2;
		for (; i < a[m] / 2; i += 2)
			b[++ bst] = 2;
		b[++ bst] = 1;
		i ++;
		for (; i < a[m]; i += 2)
			b[++ bst] = 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int odd = 0;
	for (int i = 1; i <= m; i ++) {
		cin >> a[i];
		odd += (a[i] % 2 == 1);
		if (a[i] % 2) {
			if (i != 1 && a[1] % 2)	swap (a[i], a[m]);
			else					swap (a[i], a[1]);	
		}
	}
	if (odd > 2) {
		cout << "Impossible" << endl;
		return 0;
	}

	deal_head();
	// cerr << " : " << bst << endl;
	for (int i = 2; i < m; i ++) {
		if (a[i] % 2 == 0) {
			if (a[i] / 2 % 2 == 0) {
				b[++ bst] = a[i] / 2 + 2;
				for (int j = a[i] / 2 + 2; j < a[i]; j += 2)
					b[++ bst] = 2;
			}
			else {
				b[++ bst] = a[i] / 2 + 1;
				for (int j = a[i] / 2 + 1; j < a[i]; j += 2)
					b[++ bst] = 2;
			}
		}
	}
	// cerr << " : " << bst << endl;
	if (m != 1)	deal_tail();
	else		b[++ bst] = 1;

	for (int i = 1; i <= m; i ++)
		cout << a[i] << " ";
	cout << endl << bst << endl;
	for (int i = 1; i <= bst; i ++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}