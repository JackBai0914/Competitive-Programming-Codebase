/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-09 19:43:32
* @description: 
* /Users/jackbai/Desktop/OI/October_Challenge_Codechef/REPLESX.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv REPLESX.cpp
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

int n, x, p, k;
int a[1000010];

int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d %d", &n, &x, &p, &k);
		FOR(i, 1, n + 1)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		if (x == a[p])	{printf("0\n");		continue ;}
		if (x == a[k]) 	{printf("-1\n");	continue ;}
		else if (x < a[k]) {
			if (p > k)		{printf("-1\n");continue ;}
			int pt = k;
			while (pt - 1 > 0 && a[pt - 1] > x)	pt --;
			if (p < pt)		{printf("-1\n");continue ;}
			printf("%d\n", p - pt + 1);
		}
		else if (x > a[k]){
			if (p < k)	{printf("-1\n");continue ;}
			int pt = k;
			while (pt + 1 <= n && a[pt + 1] < x)pt ++;
			if (p > pt)		{printf("-1\n");continue ;}
			printf("%d\n", pt - p + 1);
		}
	}

    return 0;
}