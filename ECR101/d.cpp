/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-28 15:10:57
* @description: 
* /Users/jackbai/Desktop/ECR101/d.cpp 
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

int n;



int main() {
	int t;
	cin >> t;
	while (t --) {
		cin >> n;
		vector <pii> rec;
		int use = n;
		for (int i = n - 1; i >= 3; i --) {
			if ((use - 1) / i + 1 >= i) {
				rec.push_back(MP(n, i));
				use = (use - 1) / i + 1;
			}
			rec.push_back(MP(i, n));
		}
		while (use != 1) {
			rec.push_back(MP(n,2));
			use = (use - 1) / 2 + 1;
		}
		cout << rec.size() << endl;
		for (int i = 0; i < rec.size(); i++)
			cout << rec[i].F << " " << rec[i].S << '\n';
	}

    return 0;
}