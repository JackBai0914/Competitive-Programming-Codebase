/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-21 03:58:38
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

int r, c;
bool mp[1010][1010];
int s[1010][1010][4];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt ++) {
    	cin >> r >> c;
    	ll ans = 0;
    	for (int i = 1; i <= r; i ++)
    		for (int j = 1; j <= c; j ++)
    			cin >> mp[i][j];
    	for (int i = 1; i <= r; i ++) {
    		int last = -1;
    		for (int j = 1; j <= c; j ++)
    			if (mp[i][j]) {
    				if (last == -1)
    					last = j;
    				s[i][j][0] = last;
    			}
    			else
    				last = -1;
    	}
    	for (int i = 1; i <= r; i ++) {
    		int last = -1;
    		for (int j = c; j >= 1; j --)
    			if (mp[i][j]) {
    				if (last == -1)
    					last = j;
    				s[i][j][1] = last;
    			}
    			else
    				last = -1;
    	}
    	for (int j = 1; j <= c; j ++) {
    		int last = -1;
    		for (int i = 1; i <= r; i ++)
    			if (mp[i][j]) {
    				if (last == -1)
    					last = i;
    				s[i][j][2] = last;
    			}
    			else
    				last = -1;
    	}
    	for (int j = 1; j <= c; j ++) {
    		int last = -1;
    		for (int i = r; i >= 1; i --)
    			if (mp[i][j]) {
    				if (last == -1)
    					last = i;
    				s[i][j][3] = last;
    			}
    			else
    				last = -1;
    	}
    	for (int i = 1; i <= r; i ++)
    		for (int j = 1; j <= c; j ++) {
    			//
    			if (!mp[i][j])
    				continue ;
    			ans += max(0, min (j - s[i][j][0], (i - s[i][j][2] + 1) / 2 - 1));
    			ans += max(0, min (s[i][j][1] - j, (i - s[i][j][2] + 1) / 2 - 1));
    			ans += max(0, min (j - s[i][j][0], (s[i][j][3] - i + 1) / 2 - 1));
    			ans += max(0, min (s[i][j][1] - j, (s[i][j][3] - i + 1) / 2 - 1));

    			ans += max(0, min (i - s[i][j][2], (j - s[i][j][0] + 1) / 2 - 1));
    			ans += max(0, min (i - s[i][j][2], (s[i][j][1] - j + 1) / 2 - 1));
    			ans += max(0, min (s[i][j][3] - i, (j - s[i][j][0] + 1) / 2 - 1));
    			ans += max(0, min (s[i][j][3] - i, (s[i][j][1] - j + 1) / 2 - 1));
    			// cerr << i << " " << j << " : " << s[i][j][0] << " " << s[i][j][1] << " " << s[i][j][2] << " " << s[i][j][3] << " : " << ans << endl;
    			// ans += (s[i][j][1] - s[i][j][0]) * (s[i][j][3] - s[i][j][2]);
    		}
    	cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}