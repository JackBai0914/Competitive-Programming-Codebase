/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-30 13:50:36
* @description: 
* /Users/jackbai/Desktop/CCC/2/2.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 2.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
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
int a[1000010];
ll s[10000010];

int main() {
	cin >> n;

	int mn = 1e9, id = -1;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (i == 0)
			s[i] = a[i];
		else
			s[i] = s[i - 1] + a[i];
	}

	cin >> m;
	cout << m << endl;
	for (int i = 0; i < m; i ++) {
		int id, l;
		cin >> id >> l;
		ll mn = 1e12, mid = -1;
		for (int j = l - 1; j < n; j ++) {
			int ss = (j == l - 1 ? s[j] : s[j] - s[j - l]);
			if (ss < mn) {
				mn = ss;
				mid = j - l + 1;
			}
		}
		cout << id << " " << mid << endl;
	}

    return 0;
}