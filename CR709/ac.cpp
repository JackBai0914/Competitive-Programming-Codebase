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
vector <int> ans;

int gcd (int x, int y) {
	return (y ? gcd(y, x % y) : x);
}


int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t --) {
    	cin >> n;
    	for (int i = 0; i < n; i ++) {
    		cin >> a[i];
        }
        // int pt = 0;
        // while (ans.size() != n)
    	
    }

    return 0;
}