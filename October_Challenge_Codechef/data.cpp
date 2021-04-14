/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-11 23:17:16
* @description: 
* /Users/jackbai/Desktop/OI/October_Challenge_Codechef/data.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv data.cpp
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

int rt[1000010];
int a[100010], b[100010];

int main() {
	srand(time(0));
	const int w = 100000;
	const int h = 80000;
	const int n = 50000;
	const int m = 40000;

	F0R(i, w)	rt[i] = i + 1;
	random_shuffle(rt, rt + w);
	F0R(i, n)	a[i] = rt[i];

	F0R(i, h)	rt[i] = i + 1;
	random_shuffle(rt, rt + h);
	F0R(i, m)	b[i] = rt[i];

	cout << w << " " << h << " " << n << " " << m << endl;
	F0R(i, n)	cout << a[i] << " "; cout << endl;
	F0R(i, m)	cout << b[i] << " "; cout << endl;
    return 0;
}