//10:06-
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
int r, g, b;
ll rl[1000010];
ll gl[1000010];
ll bl[1000010];
ll fans = 0;

ll sqr (ll x) {return x * x;}
ll calc (ll a, ll b, ll c) {return sqr(a - b) + sqr(b - c) + sqr(c - a);}

void solve (int r, int g, int b, ll *rl, ll *gl, ll *bl) {
	int ptg = 1, ptb = 1;
	for (int i = 1; i <= r; i ++) {
		while (ptb < b && bl[ptb] < rl[i])
			ptb ++;
		ll mid = (rl[i] + bl[ptb]) >> 1;
		while (ptg < g && abs (gl[ptg] - mid) >= abs (gl[ptg + 1] - mid))
			ptg ++;
		fans = min (fans, calc (rl[i], gl[ptg], bl[ptb]));
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t -- ) {
		fans = 1ll<<62;
		cin >> r >> g >> b;
		for (int i = 1; i <= r; i ++)	cin >> rl[i];
		for (int i = 1; i <= g; i ++)	cin >> gl[i];
		for (int i = 1; i <= b; i ++)	cin >> bl[i];
		sort (rl + 1, rl + r + 1);
		sort (gl + 1, gl + g + 1);
		sort (bl + 1, bl + b + 1);
		solve (r, g, b, rl, gl, bl);
		solve (r, b, g, rl, bl, gl);
		solve (g, r, b, gl, rl, bl);
		solve (g, b, r, gl, bl, rl);
		solve (b, g, r, bl, gl, rl);
		solve (b, r, g, bl, rl, gl);
		cout << fans << endl;
	}
	
	return 0;
}
