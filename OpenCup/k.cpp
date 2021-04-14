/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-11 09:24:11
* @description: 
* /Users/jackbai/Desktop/OI/OpenCup/k.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv k.cpp
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

int n, q;
int pii balls[1000010];
map <char, pii> dir;

struct node {
	pii pos;
	int ti;
	vector <int> b;
	node() {}
	node(int _ti) {ti = _ti;}
} nd[1000010];
void combine(node a, node b) {
	
		
}


int main() {
	scanf

    return 0;
}