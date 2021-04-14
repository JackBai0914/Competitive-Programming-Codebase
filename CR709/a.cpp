/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-21 13:21:20
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

int n, m;
vector <int> opt[100010];
int ans[100010];
int cnt[100010];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t --) {
    	cin >> n >> m;
    	for (int i = 1; i <= n; i ++)
    		cnt[i] = 0;
    	for (int i = 1; i <= m; i ++) {
    		int k, x;
    		cin >> k;
    		opt[i].resize(0);
    		for (int j = 0; j < k; j ++) {
    			cin >> x;
    			opt[i].push_back(x);
    		}
    		if (k != 1)
    			continue ;
    		cnt[x] ++;
    		ans[i] = x;
    	}
    	for (int i = 1; i <= m; i ++) {
    		if (opt[i].size() == 1)
    			continue ;
    		if (cnt[opt[i][0]] == (m + 1) / 2)
    			cnt[opt[i][1]] ++, ans[i] = opt[i][1];
    		else
    			cnt[opt[i][0]] ++, ans[i] = opt[i][0];
    	}
    	int mx = 0;
    	for (int i = 1; i <= n; i ++)
    		mx = max (mx, cnt[i]);
    	if (mx > (m + 1) / 2) {
    		cout << "NO" << endl;
    	}
    	else {
    		cout << "YES" << endl;
    		for (int i = 1; i <= m; i ++)
    			cout << ans[i] << ' ';
    		cout << endl;
    	}
    	
    }
    return 0;
}