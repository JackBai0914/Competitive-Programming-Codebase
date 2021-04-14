/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-17 14:19:59
* @description: 
* /Users/jackbai/Desktop/cf/b.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv b.cpp
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
int a[1000010];

int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		bool c1 = true, c2 = true;
		string s;
		cin >> s;
		F0R(i, n) {
			c1 &= (s[i] == '>' || s[i] == '-');
			c2 &= (s[i] == '<' || s[i] == '-');
		}
		int ans = 0;
		F0R(i, n)
			if (s[i] == '-' || s[(i + 1) % n] == '-' || c1 || c2)
				ans ++;
		printf("%d\n", ans);
	}
    return 0;
}