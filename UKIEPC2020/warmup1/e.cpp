/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-10 16:24:10
* @description: 
* /Users/jackbai/Desktop/UKIEPC2016/e.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv e.cpp
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

int bar[10]; 

int mn = 10000, id = -1;

int main() {
	string s;	cin >> s;
	for (int i = 0; i < s.size(); i++)
		bar[s[i] - '0'] ++;
	for (int i = 0; i < 10; i++)
		if (bar[i] + (i == 0) < mn) {
			mn = bar[i] + (i == 0);
			id = i;
		}
	string ans = "";
	for (int i = 0; i <= bar[id]; i++)
		ans += (char)('0' + id);
	if (id == 0)
		ans = '1' + ans;
	cout << ans << endl;
    return 0;
}