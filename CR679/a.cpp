/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-25 11:02:33
* @description: 
* /Users/jackbai/Desktop/CR679/a.cpp 
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
int a[6];
int b[100010];

pii q[1000010];
int qst = 0, ed = 0, st = 1;
int sum[100010], num = 0;
int ans = 2e9;

int main() {
	F0R(i, 6) {
		cin >> a[i];
	}
	cin >> n;
	F0R(i, n) {
		cin >> b[i];
		F0R(j, 6)
			q[++ qst] = (MP(b[i] - a[j], i));
	}

	sort(q + 1, q + qst + 1);

	int mx = -1e9, mn = 1e9;
	
	while (ed != qst) {
		ed ++;
		if (sum[q[ed].S] == 0)
			num ++;
		sum[q[ed].S] ++;
		mx = q[ed].F;
		mn = min (mn, q[ed].F);

		while (st <= ed && sum[q[st].S] > 1) {
			sum[q[st].S] --;
			st ++;
			mn = q[st].F;
		}

		if (num == n)
			ans = min (ans, mx - mn);
	}
	cout << ans << endl;

    return 0;
}