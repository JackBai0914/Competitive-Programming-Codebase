#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n;

char c[110];
void find (int x, int sp) {
	if (x == n) {
		for (int i = 1; i <= n; i ++) {
			cout << c[i];
		}
		cout << endl;
		return ;
	}
	for (int i = 1; i <= sp; i ++) {
		c[x + 1] = 'a' + i - 1;
		find (x + 1, sp);
	}
	c[x + 1] = 'a' + sp;
	find (x + 1, sp + 1);
}

int main() {
	cin >> n;	
	find (0, 0);
	return 0;
}