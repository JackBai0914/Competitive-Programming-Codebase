/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-16 12:04:46
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

int n, k;
int a[1000010];
int b[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	b[a[i]] ++;
    }

    int lst = k;
    ll contri = 0;

    for (int i = 0; i < n; i ++) {
    	lst = min (lst, b[i]);
    	contri += lst;
    }

    cout << contri << endl;

    return 0;
}