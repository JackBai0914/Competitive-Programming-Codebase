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

string fix_0(string t) {
	string s = t;
	for (int i = 0; i + 2 < s.size(); i ++)
		if (s.substr(i, 3) == "000")
			s = s.substr(0,i) + s.substr(i+3);
	return s;
}

map <string, int> mp;
int diff = 0;
string mx = "";
vector <string> rec;

string deal (string s) {
	string t = s;
	for (int i = 0; i < t.size(); i ++)
		if (t[i] == '2') {
			t = t.substr(0, i) + "01" + t.substr(i + 1);
		}
	// cout << t << endl;
	t = fix_0(t);

	int cnt = 0;
	while (true) {
		t = fix_0(t);

		// if ((cnt++) > 10000) 
		// cout << "beg: " << t << endl;

		bool oped = false;
		for (int i = 0; i < t.size(); i ++) {
			// if (t[i] == '1') {
				if (i + 2 < t.size() && t.substr(i, 3) == "101") {
					t = t.substr(0, i) + "00" + t.substr(i+3);
					oped = true;
					break;
				}
				if (i + 2 < t.size() && t.substr(i, 3) == "111") {
					t = t.substr(0, i) + "010" + t.substr(i+3);
					oped = true;
					break;
				}
				// if (i+5 < t.size())
					// cout << "check : " << t.substr(i, 6) << "== " << "001100" << endl;
				if (i + 5 < t.size() && t.substr(i, 6) == "001100") {
					t = t.substr(0, i) + "1001" + t.substr(i+6);
					oped = true;
					break;
				}
				if (i + 4 < t.size() && t.substr(i, 5) == "01001") {
					t = t.substr(0, i) + "1100" + t.substr(i+5);
					oped = true;
					break;
				}
				if (i + 4 < t.size() && t.substr(i, 5) == "10010") {
					t = t.substr(0, i) + "0011" + t.substr(i+5);
					oped = true;
					break;
				}

			}
		// cout << ": " << t << endl;
		t = fix_0(t);
		// cout << ": " << t << endl;
		if (!oped)
			break;
	}
	// cerr << "end: " << t << endl;
	if (!mp[t]) {
		rec.push_back(t);
		diff ++;
	}
	mp[t] = 1;
	if (t.size() > mx.size())
		mx = t;
	return t;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	string s;
	while (cin >> s) {
		cout << deal(s) << '\n';
	}
	cerr << "diff: " << diff << endl;
	cerr << "mx: " << mx << endl;
	for (int i = 0; i < rec.size(); i ++)
		cerr << rec[i] << endl;
}