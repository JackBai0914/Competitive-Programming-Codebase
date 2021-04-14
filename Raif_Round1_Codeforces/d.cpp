/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-17 14:44:54
* @description: 
* /Users/jackbai/Desktop/cf/d.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv d.cpp
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

int n, a[1000010];


vector <int> u1, u2, u3;

vector <pii> ans;

int main() {
	scanf("%d", &n);
	F0R(i, n) {
		scanf("%d", &a[i]);
	}
	R0F(i, n) {
		if (a[i] == 1) {
			u1.push_back(i);
			ans.push_back(MP(i, i));
		}
		if (a[i] == 2) {
			if (u1.empty()) {
				printf("-1\n");
				return 0;
			}
			ans.push_back(MP(i, u1[u1.size() - 1]));
			u1.pop_back();
			u2.push_back(i);
		}
		if (a[i] == 3) {
			if (!u3.empty()) {
				int p = u3[u3.size() - 1];
				u3.pop_back();
				ans.push_back(MP(p, i));
				ans.push_back(MP(i, i));
				u3.push_back(i);
			}
			else if (!u2.empty()) {
				int p = u2[u2.size() - 1];
				u2.pop_back();
				ans.push_back(MP(p, i));
				ans.push_back(MP(i, i));
				u3.push_back(i);
			}
			else if (!u1.empty()) {
				int p = u1[u1.size() - 1];
				u1.pop_back();
				ans.push_back(MP(p, i));
				ans.push_back(MP(i, i));
				u3.push_back(i);
			}
			else {
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", (int)ans.size());
	F0R(i, ans.size())
		printf("%d %d\n", ans[i].S + 1, ans[i].F + 1);
    return 0;
}