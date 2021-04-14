#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int fun (int a, int b, int k) {
	if (k == 0) {
		return 0;
	}
	int su = (k*k*k+5*k)/6;
	su+=(a-1)*k;
	su+=(b-1)*((k-1)*k/2);
	return su;
}

int fun2 (int a) {
	return a * (a + 1) / 2;
}
int fun3 (int a) {
	return a * (a - 1) / 2 + 1;
}

void pri (int an) {
	string s = "";
	while (an > 0) {
		int k = an % 10;
		char c = k + '0';
		s = c + s;
		an -= k;
		an /= 10;
	}
	cout << s << endl;
}


int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		swap (x1, y1), swap (x2, y2);
		int su1 = fun(fun2(y1), y1, x2) - fun(fun2(y1), y1, x1-1);
		int su2 = fun(fun2(y2), y2, x2) - fun(fun2(y2), y2, x1-1);
		int su3 = fun(fun3(x1), x1+1, y2-1) - fun(fun3(x1), x1+1, y1-1);
		int su4 = fun(fun3(x2), x2+1, y2) - fun(fun3(x2), x2+1, y1);
		int s1 = su1 + su4;
		int an = s2 - s1 + 1;
		pri(an);
	}

	
	return 0;
}