#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef pair <int, int> pii;

bool fail1 = false;

ll s_to_i (string s) {
	ll ans = 0;
	for (int i = 0; i < s.size(); i ++) {
		ans = ans * 10 + s[i] - '0';
	}
	return ans;
}

bool legal (string s) {
	if (s == "")
		return false;
	if (s[0] == '0')
		return false;
	if (s.size() > 10)
		return false;
	for (int i = 0; i < s.size(); i ++)
		if (s[i] < '0' || s[i] > '9')
			return false;
	if (s_to_i(s) > 1000000000 || s_to_i(s) <= 0)
		return false;
	return true;
}


bool if_well = true;
bool legit (string s) {
	string a, b, c, op;
	ll x, y, z;
	int eq_num = 0, eq_p;
	int op_num = 0, op_p;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == '=') {
			eq_num ++;
			eq_p = i;
		}
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			op_num ++;
			op_p = i;
		}
	}
	if (eq_num != 1 || op_num != 1) {
		if_well = false;
		return false;
	}
	a = s.substr(0, op_p);
	b = s.substr(op_p + 1, eq_p - op_p - 1);
	c = s.substr(eq_p + 1);
	op = s[op_p];
	// cout << a << " " << b << " " << c << endl;
	if (!legal(a) || !legal(b) || !legal(c)) {
		if_well = false;
		return false;
	}
	x = s_to_i(a);
	y = s_to_i(b);
	z = s_to_i(c);

	if (op == "+")	return (x + y == z);
	if (op == "-")	return (x - y == z);
	if (op == "*")	return (x * y == z);
	if (op == "/")	return (y * z == x);
	return false;
}

char mp[15] = {'0','1','2','3','4','5','6','7','8','9','+','-','*','/', '='};

int main() {
	// ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	string s;
	cin >> s;
	bool ok1 = legit (s);
	if (!if_well) {
		cout << "Format Error" << endl;
		return 0;
	}
	if (ok1) {
		cout << "Correct" << endl;
		return 0;
	}
	string t;
	for (int a = 0; a < s.size(); a ++)
		for (int b = a + 1; b < s.size(); b ++) {
			for (int i = 0; i <= 14; i ++)
				for (int j = 0; j <= 14; j ++) {
					t = s;
					t[a] = mp[i];
					t[b] = mp[j];
					if (legit (t)) {
						cout << "Typo: " << s << " instead of " << t << endl;
						return 0;
					}
				}
		}
	cout << "Math Error" << endl;
	return 0;
}