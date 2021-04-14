/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-04-10 13:21:51
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
ll v[1000010], s[1000010];
priority_queue <ll> q;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= 2 * n; i ++) {
    	cin >> v[i];
    	s[i] = s[i - 1] + v[i];
    }
    // ll mn = 1e16;
    // for (int i = n; i <= 2 * n; i ++)
    	// mn = min (mn, s[i] - s[i - n]);
    // cerr << mn << " " << s[2 * n] << endl;
    // cout << s[2 * n] - mn << endl;
    
    ll mn = 0;
    for (int i = n; i >= 1; i --) {
    	q.push(-v[i]);
    	q.push(-v[n + n - i + 1]);
    	mn += q.top();
    	q.pop();
    }
    cout << s[2 * n] + mn << endl;
    return 0;
}