/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-10 17:00:21
* @description: 
* /Users/jackbai/Desktop/OI/CGR_Codeforces/d.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv d.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n, m;
vector <pii> a, hp;
int st[110], ed[110];

int rec = 0;
vector<int> rd[110];

bool process() {
	memset(st, -1, sizeof st);
	int l = -1, r;
	F0R(i, a.size()) {
		if (st[a[i].S + 1] != -1) {
			l = st[a[i].S + 1];
			r = i;
			// cerr << "found: " << r << " " << l << endl;
			break;
		}
		st[a[i].F] = i;
	}
	// for (int i = 0; i < a.size(); i ++)
		// cerr << ": " << a[i].F << " " << a[i].S << endl;
	// debug(l);
	// debug(r);
	if (l == -1)
		return false;

	vector <int> d;
	if (l != 0) {
		int s = 0;
		for (int i = 0; i < l; i ++)
			s += a[i].S - a[i].F + 1;
		d.push_back(s);
	}
	d.push_back(a[l].S - a[l].F + 1);
	int s = 0;
	for (int i = l + 1; i <= r; i ++)
		s += a[i].S - a[i].F + 1;
	d.push_back(s);
	s = 0;
	if (r != a.size() - 1) {
		int s = 0;
		for (int i = r + 1; i < a.size(); i ++)
			s += a[i].S - a[i].F + 1;
		d.push_back(s);
	}
	rd[rec ++] = d;
	
	hp = a;
	a.resize(0);
	for (int i = r + 1; i < hp.size(); i ++)
		a.push_back(hp[i]);
	for (int i = l + 1; i < r; i ++)
		a.push_back(hp[i]);
	a.push_back(MP(hp[r].F, hp[l].S));
	for (int i = 0; i < l; i ++)
		a.push_back(hp[i]);
	return true;
}

int main() {
	scanf("%d", &n);
	m = n;
	F0R(i, n) {
		int x;
		scanf("%d", &x);
		a.push_back(MP(x, x));
	}

	while (process()) {
	}

	cout << rec << endl;
	for (int i = 0; i < rec; i ++) {
		cout << rd[i].size() << " ";
		for (int j = 0; j < rd[i].size(); j ++)
			cout << rd[i][j] << " ";
		cout << endl;
	}

    return 0;
}