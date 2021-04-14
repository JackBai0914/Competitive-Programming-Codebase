/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-18 17:37:09
* @description: 
* /Users/jackbai/Desktop/OI/cookoff202010_codechef/d.cpp 
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

int D;

int main() {
	int t;
	cin >> t;
	while (t --) {
	vector <int> v;
		cin >> D;
		if (D == 0) {
			cout << 1 << endl;
			cout << 1 << endl;
			continue ;
		}
		while (D) {
			if (D >= 99999) {
				v.push_back(1);
				v.push_back(99999);
				v.push_back(100000);
				v.push_back(1);
				D -= 99998;
			}
			else {
				v.push_back(1);
				v.push_back(D+1);
				v.push_back(D+2);
				v.push_back(1);
				D = 0;
			}
		}
		cout << v.size() << endl;
		F0R (i, v.size()) {
			cout << v[i] << ' ';
		}
		cout << endl;
	}
    return 0;
}