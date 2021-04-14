/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-19 14:33:26
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

ll n;
ll p[1000010];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t --) {
    	cin >> n;
    	if (n == 2) {
    		cout << "1\n2 1\n1\n2 1\n";
    		continue ;
    	}
    	if (n == 3) {
    		cout << "5\n2 3 1\n2\n1 3\n3 2\n";
    		continue ;
    	}
    	for (int i = 2; i < n; i ++)
    		p[i] = i + 1;
    	p[1] = n;
    	p[n] = 2;
    	p[n - 1] = 1;

    	ll ans = 0;
    	for (ll i = 2; i <= n; i ++)
    		ans += max(n - i, i - 1) * max(n - i, i - 1);
    	cout << ans << endl;
    	for (int i = 1; i <= n; i ++)
    		cout << p[i] << ' ';
    	cout << endl;
    	cout << n - 1 << endl;
    	for (int i = 2; i <= n / 2; i ++) {
    		cout << i << ' ' << n << endl;
    		swap (p[i], p[n]);
    		// for (ll ii = 1; ii <= n; ii ++)
	    	// 	cerr << p[ii] << ' ';
	    	// cerr << endl;
    	}
    	cout << n << " " << 1 << endl;
    	swap (p[1], p[n]);
    	for (int i = n / 2 + 1; i < n; i ++) {
    		cout << i << ' ' << 1 << endl;
    		swap (p[1], p[i]);
    		// for (ll ii = 1; ii <= n; ii ++)
	    	// 	cerr << p[ii] << ' ';
	    	// cerr << endl;
    	}

    	
    }
    return 0;
}