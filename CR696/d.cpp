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

int n;
ll a[1000010], s1[1000010], s2[1000010];
ll p1[1000010], p2[1000010];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t --) {
    	cin >> n;
    	for (int i = 1; i <= n; i ++)
    		cin >> a[i];
    	p1[0] = true;
    	s2[0] = 0;
    	for (int i = 1; i <= n; i ++) {
    		s1[i] = a[i] - s1[i - 1];
    		p1[i] = (p1[i - 1] & (s1[i] >= 0));
    	}
    	p2[n + 1] = true;
    	s2[n + 1] = 0;
    	for (int i = n; i >= 1; i --) {
    		s2[i] = a[i] - s2[i + 1];
    		p2[i] = (p2[i + 1] & (s2[i] >= 0));
    	}
    	if (p1[n] == true && s1[n] == 0) {
    		cout << "YES" << '\n';
    		continue ;
    	}
    	bool fail = true;
    	for (int i = 1; i + 1 <= n; i ++) {
    		//swap i, i + 1;
    		bool ok = (p1[i - 1] & p2[i + 2]);
    		ll st = s1[i - 1];
    		ll ed = s2[i + 2];
    		if (!ok)
    			continue ;
    		// cerr << i << " : " << st << " " << ed << " " << a[i] << " " << a[i + 1] << endl;
    		if (a[i + 1] >= st && a[i] >= ed && a[i + 1] - st == a[i] - ed) {
    			fail = false;
    			cout << "YES" << '\n';
    			break;
    		}
    	}
    	if (fail) {
    		cout << "NO" << '\n';
    		continue ;
    	}
    }
    return 0;
}