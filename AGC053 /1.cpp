/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-04-10 13:03:21
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
string s;
int a[110];
int b[10010][110];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    int mn = 1e9;
    for (int i = 0; i <= n; i ++) {
    	cin >> a[i];
    	if (i)
	    	mn = min (mn, abs(a[i] - a[i - 1]));
    }

    for (int i = 0; i <= n; i ++) {
    	for (int j = 1; j <= mn; j ++)
    		b[j][i] = a[i] / mn;
    	for (int j = 1; j <= a[i] - a[i] / mn * mn; j ++)
	    	b[j][i] ++;
    }

    cout << mn << endl;
    for (int i = 1; i <= mn; i ++) {
    	for (int j = 0; j <= n; j ++)
    		cout << b[i][j] << ' ';
    	cout << endl;
    }

    return 0;
}