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

int n, k1, k2;
int w, b;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
    	cin >> n >> k1 >> k2;
    	cin >> w >> b;
    	int x1 = k1 / 2 + k2 / 2 + ((k1 % 2 == 1) & (k2 % 2 == 1)); 
    	int x2 = (n - k1) / 2 + (n - k2) / 2 + (((n - k1) % 2 == 1) & ((n - k2) % 2 == 1)); 
    	if (x1 >= w && x2 >= b)
    		cout << "YES" << endl;
    	else
    		cout << "NO" << endl;
    }
    return 0;
}