/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-09 19:02:32
* @description: 
* /Users/jackbai/Desktop/OI/October_Challenge_Codechef/CHEFEZQ.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv CHEFEZQ.cpp
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

int n, k;
ll s[1000010], q[1000010];

int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		FOR (i, 1, n + 1)
			scanf("%lld", &q[i]);
		bool mark = false;
		FOR(i, 1, n + 1) {
			s[i] = s[i - 1] + q[i];
			if (i * k > s[i]) {
				printf("%d\n", i);
				mark = true;
				break;
			}
		}
		if (!mark)
			printf("%lld\n", s[n] / k + 1);
	}
	return 0;
}