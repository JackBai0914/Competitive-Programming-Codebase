/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-10 15:50:09
* @description: 
* /Users/jackbai/Desktop/OI/CGR_Codeforces/a.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv a.cpp
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

int n, a[1000010];

int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		vector <int> b[3];
		int s[3] = {0, 0, 0};
		scanf("%d", &n);
		F0R(i, n) {
			scanf("%d", &a[i]);
			if (a[i] < 0)	b[1].push_back(a[i]), s[1] -= a[i];
			if (a[i] == 0)	b[0].push_back(a[i]);
			if (a[i] > 0)	b[2].push_back(a[i]), s[2] += a[i];
		}
		if (s[1] == s[2]) {
			printf("NO\n");
			continue ;
		}
		printf("YES\n");
		if (s[1] > s[2]) {
			F0R(i, b[1].size())	printf("%d ", b[1][i]);
			F0R(i, b[2].size())	printf("%d ", b[2][i]);
			F0R(i, b[0].size())	printf("%d ", b[0][i]);
		}
		else {
			F0R(i, b[2].size())	printf("%d ", b[2][i]);
			F0R(i, b[1].size())	printf("%d ", b[1][i]);
			F0R(i, b[0].size())	printf("%d ", b[0][i]);
		}
		printf("\n");

	}
    return 0;
}