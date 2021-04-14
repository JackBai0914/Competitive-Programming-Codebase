/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-09 19:13:17
* @description: 
* /Users/jackbai/Desktop/OI/October_Challenge_Codechef/POSAND.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv POSAND.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
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

void solve (int ed) {
	if (ed == 4) {
		printf("2 3 1 ");
		return ;
	}
	solve(ed / 2);
	FOR(i, ed / 2 + 1, ed - 1)
		printf("%d ", i);
	printf("%d ", ed / 2);
	printf("%d ", ed - 1);
	return ;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		cin >> n;
		int x = 1;
		for (; x * 2 <= n; x *= 2);
		if (x == 1) {
			//n = 1;
			printf("1\n");
			continue ;
		}
		if (x == 2) {
			//n < 4
			if (n == 2)	printf("-1\n");
			if (n == 3)	printf("1 3 2\n");
			continue ;
		}
		if (x == n) {
			printf("-1\n");
			continue ;
		}
		solve(x);
		FOR(i, x + 1, n + 1)
			printf("%d ", i);
		printf("%d\n", x);
	}

    return 0;
}