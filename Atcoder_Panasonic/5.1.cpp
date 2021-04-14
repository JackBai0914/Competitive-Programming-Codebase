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
typedef long long ll;
int fans = 1e9;

int ex[20000020], ne[20000020];
void exkmp (string s, string t) {
	for (int i = 0; i < s.size() || i < t.size(); i ++)
		ex[i] = ne[i] = 0;

	ne[0] = t.size();
	while (1 + ne[1] < t.size() &&t[1 + ne[1]] == t[ne[1]])
		ne[1] ++;
	int p0 = 1, p1 = 1 + ne[1] - 1;
	for (int i = 2; i < t.size(); i ++) {
		int len = ne[i - p0];
		if (i + len - 1 < p1)
			ne[i] = len;
		else {
			p0 = i;
			ne[i] = max (0, p1 - i + 1);
			while (i + ne[i] < t.size() && t[i + ne[i]] == t[ne[i]])
				ne[i] ++;
			p1 = i + ne[i] - 1;
		}
	}

	while (ex[0] < s.size() && ex[0] < t.size() && s[ex[0]] == t[ex[0]])
		ex[0] ++;
	p0 = 0, p1 = 0 + ex[0] - 1;
	for (int i = 1; i < s.size(); i ++) {
		int len = ne[i - p0];
		if (i + len - 1 < p1)
			ex[i] = len;
		else {
			p0 = i;
			ex[i] = max (0, p1 - i + 1);
			while (i + ex[i] < s.size() && ex[i] < t.size() && s[i + ex[i]] == t[ex[i]])
				ex[i] ++;
			p1 = i + ex[i] - 1;
		}
	}

	// for (int i = 0; i < t.size(); i ++)
	// 	cout << i << " : " << ne[i] << endl;
	// for (int i = 0; i < s.size(); i ++)
	// 	cout << i << " : " << ex[i] << endl;

	// for (int i = 0; i < s.size(); i ++)
		// if (s.size() - i == ex[i] || t.size() == ex[i])
			// return s.size() + t.size() - ex[i];
	// return s.size() + t.size();
}

int main() {
	std::ios::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	exkmp (s, t);
	ll a1 = 0, a2 = 0;
	for (int i = 0; i < t.size(); i ++) {
		// cerr << i << " : " << ne[i] << endl;
		a1 ^= (ll)(ne[i] + 1) * (i + 1);
	}
	for (int i = 0; i < s.size(); i ++) {
		// cerr << i << ": " << ex[i] << endl;
		a2 ^= (ll)(ex[i] + 1) * (i + 1);
	}
	cout << a1 << endl << a2 << endl;
	return 0;
}