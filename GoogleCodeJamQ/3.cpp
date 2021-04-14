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

int n, c;
int a[110];

void reverse (int x, int y) {
    for (int i = x; i <= y; i ++)
        if (i <= y - (i - x))
            swap (a[i], a[y - (i - x)]);
}

void putback (int x) {
    for (int i = x; i < n; i ++)
        a[i] = a[i + 1];
    a[n] = x;
}

bool dfs (int x, int c) {
    // cerr << "dfs: " << x << " " << c << endl;
    if (c < 0)
        return false;
    if (x == 0)
        return c == 0;
    if (c >= n - x) {
        reverse(x + 1, n);
        putback(x);
        return dfs (x - 1, c - (n - x));
    }
    else {
        reverse(x + 1, x + c);
        for (int i = x; i < x + c; i ++)
            a[i] = a[i + 1];
        a[x + c] = x;
        return dfs (x - 1, 0);
    }
}

void count () {
    int ans = 0;
    for (int i = 1; i <= n - 1; i ++) {
            int mn = 1e9, id = -1;
            for (int j = i; j <= n; j ++)
                if (mn > a[j])
                    mn = a[j], id = j;
            reverse(i, id);
            ans += id - i + 1;
        }
    cout << " : " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t ++) {
        cin >> n >> c;

        a[n] = n;
        bool doable = dfs (n - 1, c - (n - 1));

    	cout << "Case #" << t << ": ";
        if (doable)
            for (int i = 1; i <= n; i ++)
                cout << a[i] << ' ';
        else
            cout << "IMPOSSIBLE";
        cout << endl;
        // count();
    }
    return 0;
}