/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-30 13:46:59
* @description: 
* /Users/jackbai/Desktop/CCC/1/1.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 1.cpp
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
ll a[1000010];

int main() {
	cin >> n;

	for (int i = 0; i < n; i ++)
		cin >> a[i];

	cin >> m;
	cout << m << endl;
	for (int i = 0; i < m; i ++) {
		ll id, pow, st, ed;
		cin >> id >> pow >> st >> ed;
		ll mn = 1e12, mid = -1;
		for (int j = st; j <= ed; j ++) {
			if (a[j] < mn) {
				mn = a[j];
				mid = j;
			}
		}
		cout << id << " " << mid << " " << pow << endl;
	}

    return 0;
}