/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-17 14:24:10
* @description: 
* /Users/jackbai/Desktop/cf/c.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv c.cpp
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

string s;
stack <char> st;

int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		while (!st.empty()) {
			st.pop();
		}
		cin >> s;
		int ans = 0;
		int a_left = 0, b_left = 0;
		F0R(i, s.size()) {
			if (s[i] == 'A') {
				st.push('A');
			}
			else {
				if (!st.empty()) {
					// cerr << "get: " << i << " " << st.top() << endl;
					if (st.top() == 'A') {
						st.pop();
						ans += 2;
					}
					else if (st.top() == 'B') {
						st.pop();
						ans += 2;
					}
				}
				else {
					st.push('B');
				}
			}
		}
		printf("%d\n", (int)s.size() - ans);
	}


    return 0;
}