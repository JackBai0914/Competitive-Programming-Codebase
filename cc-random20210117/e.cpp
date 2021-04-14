/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-17 11:42:50
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

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t --) {
    	cin >> n;
        int tot = n * 2 - 1;
    	for (int i = 1; i <= n; i ++) {
            int l = i * 2 - 1;
            int cnt = 0;
            for (int j = 1; j <= tot; j ++) {
                if ((tot - l) / 2 < j && j <= tot - (tot - l) / 2) {
                    cnt ++;
                    if (cnt % 2)
                        cout << cnt / 2 + 1;
                    else
                        cout << ' ';
                }
                else
                    cout << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}