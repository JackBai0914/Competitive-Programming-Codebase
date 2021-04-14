/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-21 13:36:52
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
int a[100010];
int nxt[100010], bef[100010];

struct node {
	int id, ne;
} nd[100010];
int ed[1000010];
int st = 1;

void add (int id) {
	ed[st - 1] = bef[id];
	nd[st - 1].ne = st;
	nd[st].id = id;
	nd[st].ne = 0;
	ed[st] = n - 1;
	st ++;
}
int gcd (int x, int y) {
	return (y ? gcd(y, x % y) : x);
}
int dis (int l, int r) {
	return (r >= l ? r - l : r + n - l);
}
int subs (int x, int dt) {
	return (x + n - dt) % n;
}
vector <int> ans;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t --) {
    	ans.resize(0);
    	cin >> n;
    	
    	nd[0].id = 0;
    	nd[0].ne = 0;
    	ed[0] = n - 1;
    	st = 1;
    	for (int i = 0; i < n; i ++) {
    		nxt[i] = (i + 1) % n;
    		bef[i] = (i + n - 1) % n;
    		cin >> a[i];
    		if (i && gcd(a[i], a[i - 1]) == 1)
    			add (i);
    	}
    	int pt = 0;
    	while (st) {
    		int ne = nd[pt].ne, neid = nd[ne].id;
    		// cerr << st << " : " << pt << " " << ne << endl;

    		if (gcd(a[neid], a[bef[neid]]) != 1) {
    			// cerr << "tested " << gcd(a[nd[ne].id], a[subs(nd[ne].id, 1)]) << endl;
    			ed[pt] = ed[ne];
    			nd[pt].ne = nd[ne].ne;
    			
    			st --;
    			continue ;
    		}

    		int del = neid;
    		ans.push_back(del);
    		bef[nxt[del]] = bef[del];
    		nxt[bef[del]] = nxt[del];
    		nd[ne].id = nxt[del];


    		if (del == ed[ne]) {
    			nd[pt].ne = nd[ne].ne;
    			st --;
    		}
    		pt = nd[pt].ne;
    	}
    	cout << ans.size() << ' ';
    	for (int i = 0; i < ans.size(); i++)
    		cout << ans[i] + 1 << ' ';
    	cout << endl;
    }

    return 0;
}