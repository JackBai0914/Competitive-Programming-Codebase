/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-18 14:14:12
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

string s;
int k;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
    	cin >> s;
    	bool ok = false;
    	for (int i = 0; i <= s.size() && !ok; i ++) {
    		bool check = true;
    		int last = -2;
    		for (int j = 0; j < i; j ++)
    			if (s[j] == '1') {
    				check &= (j != last + 1);
    				last = j;
    			}
    		for (int j = i; j < s.size(); j ++)
    			if (s[j] == '0') {
    				check &= (j != last + 1);
    				last = j;
    			}
    		ok |= check;
    	}
    	cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}