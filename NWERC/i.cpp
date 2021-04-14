/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-28 10:59:05
* @description: 
*  
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 
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
const int mod = 1000000007; 
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n;
ll d[1010], sd[1010];
ll t[3][1010], s[3][1010];

bool pass[3][1010][1010];
ll dis (int x, int st, int ed) {
	if (ed < st)
		ed += n;
	return sd[ed - 1] - sd[st - 1] + s[x][ed - 1] - s[x][st - 1];
}

bool check (int a, int b, int pa, int pb) {
	//if a will catch b
	if (pb < pa)
		pb += n;
	// if (a == 2 && b == 0 && pa == 6 && pb == 7) {
	// 	cerr << "! " << endl;
	// }
	for (int i = pb; i < pa + n; i ++) {
		ll ta = dis(a, pa, i);
		ll tb = dis(b, pb, i);
		// if (a == 2 && b == 0 && pa == 6 && pb == 7) {
		
		// 	cerr << i << " ! " << ta << " " << tb << " " << t[b][i] << endl;
		// }
		if (ta < tb + t[b][i])
			return false;
	}
	// if (a == 2 && b == 0 && pa == 6 && pb == 7)
	// 	cerr << "going well" << endl;
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
    	cin >> d[i];
    	d[n + i] = d[i];
    }
    for (int i = 1; i <= n * 2; i ++)
    	sd[i] = sd[i - 1] + d[i];
    for (int p = 0; p < 3; p ++) {
    	for (int i = 1; i <= n; i ++) {
    		cin >> t[p][i];
    		t[p][i + n] = t[p][i];
    	}
    	for (int i = 1; i <= 2 * n; i ++)
    		s[p][i] = s[p][i - 1] + t[p][i];
    }
    for (int t = 0; t < 3; t ++) {
    	int p1, p2;
    	if (t == 0)	p1 = 0, p2 = 1;
    	if (t == 1)	p1 = 0, p2 = 2;
    	if (t == 2)	p1 = 1, p2 = 2;
    	for (int i = 1; i <= n; i ++)
    		for (int j = 1; j <= n; j ++)
    			if (i != j) {
	    			pass[t][i][j] = (check (p1, p2, i, j) & check (p2, p1, j, i));
    		// 		if (pass[t][i][j]) {
						// cerr << "legal: " << p1 << " " << p2 << " " << i << " " << j << endl;
    		// 		}
    			}
    }

    for (int i = 1; i <= n; i ++)
    	for (int j = 1; j <= n; j ++)
    		for (int k = 1; k <= n; k ++)
    			if (pass[0][i][j] && pass[1][i][k] && pass[2][j][k]) {
    				cout << i << " " << j << " " << k << endl;
    				return 0;
    			}
    cout << "impossible" << endl;
    return 0;
}