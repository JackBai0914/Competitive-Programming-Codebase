/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-26 13:04:12
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
const ll oo = 1e14;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int x, y;
string s;
ll dp[100010][2];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t ++) {
    	cin >> x >> y >> s;
    	for (int j = 0; j < s.size(); j ++) {
            char c = s[j];
            dp[j][0] = dp[j][1] = oo;
            if (j == 0) {
                if (c == 'C' || c == '?')   dp[0][0] = 0;
                if (c == 'J' || c == '?')   dp[0][1] = 0;
                continue ;
            }
            if (c == 'C' || c == '?')   dp[j][0] = min (dp[j - 1][0], dp[j - 1][1] + y);
            if (c == 'J' || c == '?')   dp[j][1] = min (dp[j - 1][1], dp[j - 1][0] + x);
        }
    	cout << "Case #" << t << ": " << min (dp[s.size() - 1][0], dp[s.size() - 1][1]) << endl;
    }
    return 0;
}