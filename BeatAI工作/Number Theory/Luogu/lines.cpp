#include <iostream>
#include<ctime>

using namespace std;

#define MAXN 301

int N;
bool dp[MAXN][MAXN * (MAXN - 1) / 2 + 1]; //dp[i][j]记录着i条线段能否构成j个交点

/*N条线的情况可以借1...N-1条线的情况加不与上面的哪些线平行的平行线的方式得到*/
int solve(int N) {
    for (int i = 1; i <= N; i++) { //赋初值
        dp[i][0] = true;
    }
    for (register int i = 1; i <= N; i++) {
        for (register int j = 1; j < i; j++) {
            for (register int k = 0, max_k = j * (j - 1) / 2; k <= max_k; k++) {
                if (dp[j][k]) { //状态转移
                    dp[i][k + (i - j) * j] = true; //状态转移
                }
            }
        }
    }
    /*统计合法的case数*/
    int ret = 0;
    for (int i = 0, max_i = N * (N - 1) / 2; i <= max_i; i++) {
        if (dp[N][i]) {
            ret++;
        }
    }
    return ret;
}

int main() {
    cin >> N;
    cout << solve(N) << endl;
    return 0;
}