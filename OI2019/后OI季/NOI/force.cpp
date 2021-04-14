// luogu-judger-enable-o2
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int n, ins[10010];

int cnt (int *xx) {
    int x[10010];
    for (int i = 1; i <= n; i ++)
        x[i] = xx[i];
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j < n; j ++)
            if (x[j] > x[j + 1]) {
                swap (x[j], x[j + 1]);
                cnt ++;
            }
    return cnt;
}

int count (int *x) {
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        cnt += abs (i - x[i]);
    return cnt / 2;
}

bool flag[10010];
int y[10010], ans = 0;
void dfs (int lyer, int large) {
    if (lyer == n + 1) {
        // cerr << ": " << y[1] << " " << y[2] << " " << y[3] << " " << large << endl;
        if (count(y) == cnt (y) && large == 1)
            ans ++;
        return ;
    }
    for (int i = 1; i <= n; i ++)
        if (!flag[i]) {
            y[lyer] = i;
            flag[i] = 1;
            int new_large = large;
            if (i < ins[lyer] && large == 0)		new_large = -1;
            if (i > ins[lyer] && new_large != -1)	new_large = 1;
            // cerr << "ch: " << lyer << " " << i << endl;
            dfs (lyer + 1, new_large);
            flag[i] = 0;
        }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T --) {
        ans = 0;
        memset(flag, 0, sizeof flag);
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> ins[i];
        dfs (1, 0);
        cout << ans << endl;
    }

    return 0;
}