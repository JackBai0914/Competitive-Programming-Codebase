/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-28 14:31:34
* @description: 
* /Users/jackbai/Desktop/ECR101/a.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv a.cpp
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

int main() {
	int t;
	cin >> t;
	while (t --) {
		cin >> s;
		if (s.size() % 2) {
			cout << "NO" << endl;
			continue ;
		}
		int p = 0, n = 0, tg = s.size() / 2;
		for (int i = 0; i < s.size(); i ++) {
			p += (s[i] == '(');
			n += (s[i] == ')');
		}
		for (int i = 0; i < s.size(); i ++) {
			if (s[i] == '?' && p != tg) {
				p ++;
				s[i] = '(';
			}
			else if (s[i] == '?') {
				s[i] = ')';
			}
		}
		int num = 0, ans = true;
		for (int i = 0; i < s.size(); i ++) {
			if (s[i] == '(')	num ++;
			else				num --;
			if (num < 0)
				ans = false;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}

    return 0;
}