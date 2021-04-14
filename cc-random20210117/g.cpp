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
        cin >> n; int k = n / 2;
        // n = 2 * n - 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n - 2; j ++) {
                bool num = true;
                int x = abs (i - k - 1);
                if (j < x)
                    num = false;
                if (j > x + k - 1)
                    num = false;
                if (num)    cout << j;
                else        cout << ' ';
            }
        }
    }
    return 0;
}