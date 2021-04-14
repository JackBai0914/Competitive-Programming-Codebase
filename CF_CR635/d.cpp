#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define F first 
#define S second
#define MP make_pair
using namespace std;
typedef pair <int, int> pii;

int C3[200], i_tri[2000020];

int n;
int v[110], add[110];
pii fir[110];

int tri, str;
pii quary (int id) {
	add[id] ++;
	int c_tri, c_str;
	cout << "+ " << id << endl;
	cin >> c_tri >> c_str;
	pii ret = MP(c_tri - tri, c_str - str);
	tri = c_tri, str = c_str;
	return ret;
}

void solve (int a, int b) {
	pii q1 = quary (a);
	if (add[a] == 1)	fir[a] = q1;
	if (add[a] == 2) {
		v[a] = i_tri[q1.F];
		v[a + 1] = q1.S - fir[a].S - v[a - 1];
	}	

	pii q2 = quary (b);
	fir[b] = q2;
}

int main() {
	ios::sync_with_stdio(false);
	memset(i_tri, 0, sizeof i_tri);
	memset(C3, 0, sizeof C3);
	for (int i = 1; i <= 110; i ++) {
		C3[i] = i * (i - 1) * (i - 2) / 6;
		i_tri[C3[i] - C3[i - 1]] = i;
	}

	cin >> n;
	cin >> tri >> str;
	
	solve (1, 3);
	for (int i = 1; i + 4 <= n; i += 2)
		solve (i, i + 4);
	if (n % 2 == 1) {
		pii q = quary(n - 2);
		v[n - 2] = i_tri[q.F];
		v[n - 1] = q.S - fir[n - 2].S - v[n - 3];
	}
	else {
		pii q1 = quary(n - 3);
		v[n - 3] = i_tri[q1.F];
		v[n - 2] = q1.S - fir[n - 3].S - v[n - 4];
		pii q2 = quary(n - 1);
		v[n - 1] = i_tri[q2.F];
	}

	int pans = 0;
	for (int i = 1; i + 2 < n; i ++)
		pans += v[i] * v[i + 1] * v[i + 2];
	v[n] = pans / v[n - 1] / v[n - 2];

	cout << "! ";
	for (int i = 1; i <= n; i ++)
		cout << v[i] - add[i] << " ";
	cout << endl;

	
	return 0;
}
/*
pii q = quary (id);
	unsure = (q.F - tri == 0);
	v[id] = i_tri[q.F - tri];
	if (!unsure) {
		int ret = q.S - str;
		tri = q.F, str = q.S;
		id += 1;
		return ret;
	}
	pii g1 = MP (q.F - tri, q.S - str);
	pii q2 = quary (id);
	if (q2.F - tri == 0)	v[id] = 2;
	if (q2.F - tri == 1)	v[id] = 3;

	if (id == 1) {
		int prod = (q2.S - tri) / v[id];
		pii q3 = quary (id + 2);
		pii q4 = quary (id + 2);
		v[id + 2] = i_tri[q4.F - q3.F];
		v[id + 1] = prod / (v[id + 2] - 2);
		int ret = q4.S - q3.S;
		tri = q4.F, str = q4.S;
		id += 3;
		return ret;
	}
	else {
		v[id + 1] = (last - v[id - 3] * v[id - 2] - v[id - 2] * (v[id] - 2)) / (v[id] - 2);
		int cur = q3.S - q2.S;
		v[id + 2] = (cur - v[id - 2] * v[id - 1] - v[id - 1] * v[id + 1]) / v[id + 1];

		pii q3 = quary (id + 2);
		v[id + 2] ++;
		int ret = q3.S - q2.S;
		tri = q3.F, str = q3.S;
		id += 3;
		return ret;
	}
*/
