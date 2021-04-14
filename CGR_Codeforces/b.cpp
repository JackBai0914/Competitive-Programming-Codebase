/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-10 16:01:05
* @description: 
* /Users/jackbai/Desktop/OI/CGR_Codeforces/b.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv b.cpp
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
string s;

vector <int> q;

int main() {
	int t;
	cin >> t;
	while (t --) {
		int old = 0, cnt = 0, ans = 0;
		cin >> n >> k;
		q.resize(0);
		cin >> s;
		if (n == 1) {
			if (k == 0 && s[0] == 'L')	printf("0\n");
			else						printf("1\n");
			continue ;
		}
		int prev = -1;
		F0R(i, s.size()) {
			if (s[i] == 'W') {
				old += 1 + (i > 0 && s[i - 1] == 'W');
				if (prev != i - 1) {
					if (prev == -1)	cnt += i;
					else			q.push_back(i - prev - 1);
				}
				prev = i;
			}
		}
		if (old == 0) {
			printf("%d\n", max(0, 2 * min(k, n) - 1));
			continue ;
		}
		cnt += s.size() - prev - 1;
		sort(q.begin(), q.end());
		int pter = 0;
		while (pter < q.size() && k >= q[pter]) {
			// debug(q[pter]);
			ans += 2 * q[pter] + 1;
			k -= q[pter];
			pter ++;
		}
		if (pter < q.size())
			ans += 2 * k;
		else
			ans += 2 * min(k, cnt);
		printf("%d\n", ans + old);
	}

    return 0;
}