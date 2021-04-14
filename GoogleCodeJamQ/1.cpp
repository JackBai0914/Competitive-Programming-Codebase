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
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n;
int l[1000010];

void reverse (int a, int b) {
	for (int i = a; i <= b; i ++)
		if (i <= b - (i - a))
			swap (l[i], l[b - (i - a)]);
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t ++) {
    	cin >> n;
    	int ans = 0;
    	for (int i = 0; i < n; i ++)
    		cin >> l[i];
    	for (int i = 0; i < n - 1; i ++) {
    		int mn = 1e9, id = -1;
    		for (int j = i; j < n; j ++)
    			if (mn > l[j])
    				mn = l[j], id = j;
    		reverse(i, id);
    		ans += id - i + 1;
    	}
    	cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}