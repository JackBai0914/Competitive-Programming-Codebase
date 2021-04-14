/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-30 13:55:10
* @description: 
* /Users/jackbai/Desktop/Goodbye2020/b.cpp 
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
int b[1000010];
bool c[1000010];

int main() {
	int t;
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 0; i <= 2 * n + 2; i ++)
			b[i] = c[i] = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			b[a[i]] ++;
		}
		int sum = 0;
		for (int i = 1; i <= 2 * n; i ++) {
			if (b[i] == 0)
				continue ;
			if (c[i] == 0) {
				sum ++;
				c[i] = 1;
				b[i] --;
			}
			if (b[i] == 0)
				continue ;
			if (c[i + 1] == 0) {
				sum ++;
				c[i + 1] = 1;
				b[i] --;
			}
		}
		cout << sum << endl;
	}


    return 0;
}