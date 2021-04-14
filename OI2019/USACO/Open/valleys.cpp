#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#define TIME (double)clock()/CLOCKS_PER_SEC 
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;

int n;
int mp[800][800];
int ID (int a, int b) {
	if (a < 1 || b < 1 || a > n || b > n)
		return -1;
	return (a - 1) * n + b;
}

bool flag[1000010];
pii pos[1000010];

int rt[1000010];
int V[1000010], E[1000010], F[1000010];
int get_r(int x) {return (x == rt[x] ? x : rt[x] = get_r(rt[x]));}
void trans(int a, int b) {
	if (!a)
		return ;
	int ra = get_r(a);
	int rb = get_r(b);
	if (ra == rb)
		return ;
	// cout << "trans : " << a << " " << b << " " 
	// 	 << V[ra] << " " << E[ra] << " " << F[ra] << endl;
	
	V[rb] += V[ra];
	E[rb] += E[ra];
	F[rb] += F[ra];
	V[ra] = E[ra] = F[ra] = 0;
	rt[ra] = rb;
}

int check_point(int n1, int n2, int n3) {
	if (n1 == 0 && n2 == 0)	return 1;
	if (n1 == 0)			return 0;
	if (n2 == 0)			return 0;
	if (n1 == n2) {
		if (n1 == n3)		return 0;
		else				return -1;
	}
	else					return -1;
}

long long ans = 0;

int main() {
	ios::sync_with_stdio(false);
	freopen("valleys.in", "r", stdin);
	freopen("valleys.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) {
			cin >> mp[i][j];
			flag[mp[i][j]] = 1;
			pos[mp[i][j]] = MP(i, j);
		}
	for (int h = 1; h <= 1000000; h ++) {
		if (!flag[h])
			continue ;
		int x = pos[h].F, y = pos[h].S, id = (x - 1) * n + y;
		rt[id] = id;
		F[id] = 1;
		int L = ((~ID(x - 1, y)) ? get_r(ID(x - 1, y)) : 0);
		int R = ((~ID(x + 1, y)) ? get_r(ID(x + 1, y)) : 0);
		int D = ((~ID(x, y - 1)) ? get_r(ID(x, y - 1)) : 0);
		int U = ((~ID(x, y + 1)) ? get_r(ID(x, y + 1)) : 0);
		int LD = ((~ID(x - 1, y - 1)) ? get_r(ID(x - 1, y - 1)) : 0);
		int RD = ((~ID(x + 1, y - 1)) ? get_r(ID(x + 1, y - 1)) : 0);
		int LU = ((~ID(x - 1, y + 1)) ? get_r(ID(x - 1, y + 1)) : 0);
		int RU = ((~ID(x + 1, y + 1)) ? get_r(ID(x + 1, y + 1)) : 0);
		V[id] += check_point(L, U, LU);
		V[id] += check_point(L, D, LD);
		V[id] += check_point(R, U, RU);
		V[id] += check_point(R, D, RD);
		E[id] += (L == 0);
		E[id] += (R == 0);
		E[id] += (D == 0);
		E[id] += (U == 0);
		trans (L, id);
		trans (R, id);
		trans (D, id);
		trans (U, id);
		// cout << "DIR : " << L << " " << R << " " << D << " " << U << " "
		// 	 << LD << " " << RD << " " << LU << " " << RU << endl;
		// cout << "h=" << h << " : " << V[id] << " " << E[id] << " " << F[id] << endl;
		// for (int i = 1; i <= n; i ++) {
		// 	for (int j = 1; j <= n; j ++)
		// 		cout << get_r(ID(i, j)) << " ";
		// 	cout << endl;
		// }
		if (V[id] - E[id] + F[id] == 1)
			ans += F[id];

	}
	cout << ans << endl;
	return 0;
}