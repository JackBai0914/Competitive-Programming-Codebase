/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-30 13:54:30
* @description: 
* /Users/jackbai/Desktop/Goodbye2020/a.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv a.cpp
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

int n;
int a[10010];

bool flag[110];

int main() {
	int t;
	cin >> t;
	while (t --) {
		memset(flag, 0, sizeof flag);
		int sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			for (int j = 1; j < i; j ++) {
				sum += (flag[a[i] - a[j]] == 0);
				flag[a[i] - a[j]] = 1;
			}
		}
		cout << sum << endl;
	}

    return 0;
}