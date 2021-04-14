/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-10 12:59:20
* @description: 
* /Users/jackbai/Desktop/OI/HHKB2020_Atcoder/a.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv b.cpp
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

char mp[110][110];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	F0R(i, n)
		F0R(j, m)
			cin >> mp[i][j];
	int cnt = 0;
	F0R(i, n)
		F0R(j, m - 1)
			cnt += (mp[i][j] == '.' && mp[i][j + 1] == '.');
	F0R(j, m)
		F0R(i, n - 1)
			cnt += (mp[i][j] == '.' && mp[i + 1][j] == '.');
	printf("%d\n", cnt);
    return 0;
}