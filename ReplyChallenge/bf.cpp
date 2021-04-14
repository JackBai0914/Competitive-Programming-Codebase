/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-11 15:18:36
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

int T;
int n, k;
ll a[1000010], b[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; t ++) {
    	cin >> n >> k;
    	for (int i = 0; i < n; i ++)	cin >> a[i];
    	for (int i = 0; i < n; i ++)	cin >> b[i];
    	sort(a, a + n);
    	sort(b, b + n);
    	ll ans0 = 0, ans1 = 0;
    	for (int i = 0; i < k; i ++)
    		ans0 += a[i] * b[i];
    	for (int i = 0; i < k; i ++) {
    		// cerr << a[n - i - 1] << " " <<  b[n - i - 1] << endl;
    		ans1 += a[n - i - 1] * b[n - i - 1];
    	}
    	cout << "Case #" << t << ": " << ans0 << " " << ans1 << endl;
    }
    return 0;
}