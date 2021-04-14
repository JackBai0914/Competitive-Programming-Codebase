/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-12 09:29:24
* @description: 
* /Users/jackbai/Desktop/OI/UKIEPC2020/warmup2/test.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv test.cpp
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

int c, n;
pair <ll, ll> num[100010];//usenum, init_hat
int cur[100010], ord[100010];

int main() {
	cin >> c >> n;
	for (int i = 1; i <= c; i ++) {
		num[i] = MP(0, i);
		cur[i] = i;
	}
	for (int i = 1; i <= n; i ++) {
		cin >> ord[i];
		if (i == 1)
			continue ;
		num[cur[ord[i]]].F ++;
		cur[ord[i - 1]] = cur[ord[i]];
	}

	sort(num + 1, num + c + 1);

	long long ans = 0;
	for (int i = c, j = 0; i >= 1; i --) {
		if (num[i].S == ord[1])
			continue ;
		j ++;
		ans += num[i].F * j;
		// cerr << " : " << num[i].F << " " << num[i].S << endl;
	}


	cout << ans << endl;

	for (int i = c; i >= 1; i --) {
		if (num[i].S == ord[1])
			continue ;
		cout << num[i].S << " ";
	}
	cout << endl;


    return 0;
}