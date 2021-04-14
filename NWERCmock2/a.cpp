/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-27 17:27:16
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

int n, m = 0, ans = 0, k = 0;
int a[1000010], b[1000010];
map <int, int> mp;

int num[1000010];

int v[1000010], cnt[1000010];

int ban[1000010], banv[1000010];

int add[1000010], sub[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	b[i] = a[i];
    }
    // cerr << "after inp: " << TIME << endl;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i ++) {
    	if (i == 1 || b[i - 1] != b[i])
    		k ++;
    	mp[b[i]] = k;
    }
    for (int i = 1; i <= n; i ++) {
    	a[i] = mp[a[i]];
    	if (i == 1 || a[i] != a[i - 1])
    		m ++;
    	else
    		ans ++;
    	v[m] = a[i], cnt[m] ++;
    	num[a[i]] ++;
    }
    // for (int i = 1; i <= n; i ++)
    // 	cout << a[i] << endl;
    // cerr << "Ppreans: " << ans << endl;
    // cerr << "mid" << TIME << endl;
    for (int i = 1; i <= m; i ++) {
    	if (num[v[i]] == cnt[i]) {
    		// cerr << "finding fat: " << i << " " << v[i] << " " << num[v[i]] << " " << cnt[i] << endl;
    		ban[v[i]] = true; banv[i] = true;
    		if (i != 1 && v[i - 1] == v[i] - 1) {if (banv[i - 1] == false)ans ++;banv[i - 1] = true;}
    		if (i != m && v[i + 1] == v[i] + 1) {if (banv[i + 1] == false)ans ++;banv[i + 1] = true;}
    	}
    }
    // cerr << "preans: " << ans << endl;
    for (int i = 1; i <= m; i ++) {
    	if (banv[i])
    		continue;
    	int st = i, ed = i;
    	while (ed + 1 <= m && !banv[ed + 1] && v[ed + 1] == v[ed] + 1)
    		ed ++;
    	if (st != ed) {
	    	add[v[st]] ++;
	    	sub[v[ed]] ++;
	    }
    	// cerr << "find: " << st << " " << v[st] << " " << ed << " " << v[ed] << " (" << v[ed + 1] << " " << mp[v[ed + 1]] << " " << mp[v[ed]] << endl;
    	i = ed;
    }

    int cur = 0;
    bool warning = false;
    for (int i = 1; i <= k; i ++) {
    	if (ban[i]) {
    		warning = false;
    		continue ;
    	}
    	cur += add[i];
    	cur -= sub[i];
    	if (sub[i])
    		warning = false;
    	if (cur == 0)
    		continue ;
    	if (cur == 1) {
    		// cerr << "1 op: " << i << endl;
    		if (warning)
    			warning = false;
    		else {
    			ans ++;
    			warning = true;
    		}
    	}
    	else {
    		// cerr << "multi op: " << i << endl;
    		warning = false;
    		ans ++;
    	}
    }
    cout << n - ans - 1 << endl;
    cerr << n - ans - 1 << " " << TIME << endl;
    return 0;
}