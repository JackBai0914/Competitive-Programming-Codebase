/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-30 13:46:59
* @description: 
* /Users/jackbai/Desktop/CCC/1/1.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 1.cpp
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
int a[1000010];

int main() {
	cin >> n;

	int mn = 1e9, id = -1;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (a[i] < mn) {
			mn = a[i];
			id = i;
		}
	}

	cout << id << endl;
    return 0;
}