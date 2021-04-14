#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;

int n;

bool q[220];
bool query () {
	cout << "? ";
	for (int i = 1; i <= 2 * n; i ++)
		if (q[i])
			cout << i << ' ';
	cout << endl;
	string T;
	cin >> T;
	return (T == "Red");
}

bool ans[220];

int main () {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		q[i] = true;
	bool ini = query ();
	int l = 1, r = n; 
	while (l != r) {
		int mid = (l + r) >> 1;
		memset(q, 0, sizeof q);
		for (int i = 1; i <= mid; i ++)		q[i] = true;
		for (int i = mid + 1; i <= n; i ++)	q[n + i] = true;
		bool res = query ();
		if (res == ini)	r = mid;
		else			l = mid + 1;
	}
	//res is the place which red is more, but res - 1 is blue is more
	int res = l;
	
	for (int t = 1; t <= 2 * n; t ++) {
		memset(q, 0, sizeof q);
		for (int i = 1; i <= res - 1; i ++)	 q[i] = true;
		for (int i = res + 1; i <= n; i ++)	 q[n + i] = true;
		if (q[t])
			continue ;
		q[t] = true;
		ans[t] = query ();
	}

	for (int t = 1; t <= 2 * n; t ++) {
		memset(q, 0, sizeof q);
		for (int i = 1; i <= res - 1; i ++)	 q[n + i] = true;
		for (int i = res + 1; i <= n; i ++)	 q[i] = true;
		if (q[t])
			continue ;
		q[t] = true;
		ans[t] = query ();
	}

	cout << "! ";
	for (int i = 1; i <= 2 * n; i ++) {
		cout << (ans[i] == 1 ? 'R' : 'B');
	}
	cout << endl;

	return 0;
}