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
inline int read(int& l, char *s){
    int x = 0;
    char c = s[l];
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = s[++l];
    return x; 
}
char s1[1000005], s2[1000005];
int l1, l2;
int lis1[1000005], lis2[1000005], tot1, tot2;
int r1[1000005][2] = {0}, r2[1000005][2] = {0};
int ps(int l, int tp, int& tot, char s[], int lis[], int r[][2]){
    if (s[l] == '['){
        ++l;
        for (; ; ){
            lis[++tot] = read(l, s);
            if (s[l] == ']') break;
            else ++l;
        }
        return l;
    }else if (s[l] == 's'){
        int old_tot = tot;
        int new_tp = (s[l + 1] == 'h' ? 2: 1);
        int rp = ps(l + 6 + new_tp, tp == 0 ? new_tp : tp, tot, s, lis, r);
        if (tp == 0){
            r[old_tot + 1][0] = tot;
            r[old_tot + 1][1] = new_tp;
        }
        return rp + 1;
    }else{
        // concat
        int rp = ps(l + 7, tp, tot, s, lis, r);
        int rp2 = ps(rp + 2, tp, tot, s, lis, r);
        return rp2 + 1;
    }
    return 0;
}
void deal(int tot, int lis[], int r[][2]){
    for (int i = 1; i <= tot; ++i){
        if (r[i][1] != 0){
            sort(lis + i, lis + r[i][0] + 1);
            if (r[i][1] == 1) r[i][0] = r[i][1] = 0;
            else {
                bool flag = false;
                for (int j = i + 1; j <= r[i][0]; ++j)
                    if (lis[j] != lis[j - 1]){
                        flag = true;
                        break;
                    }
                if (!flag) r[i][0] = r[i][1] = 0;
            }
        }
    }
}
void init(){
    scanf("%s%s", s1, s2);
    l1 = strlen(s1), l2 = strlen(s2);

    tot1 = tot2 = 0;
    ps(0, 0, tot1, s1, lis1, r1), deal(tot1, lis1, r1);
    ps(0, 0, tot2, s2, lis2, r2), deal(tot2, lis2, r2);
}
void solve(){
    if (tot1 != tot2){
        printf("not equal\n");
        return ;
    }
    for (int i = 1; i <= tot1; ++i){
        if (r1[i][1] != 0 || r2[i][1] != 0){
            if (r1[i][1] == 0 || r2[i][1] == 0 || r1[i][0] != r2[i][0]){
                printf("not equal\n");
                return ;
            }
            int rb = r1[i][0];
            while (i <= rb){
                if (lis1[i] != lis2[i]){
                    printf("not equal\n");
                    return ;
                }
                ++i;
            }
            --i;
        }else {
            if (lis1[i] != lis2[i]){
                printf("not equal\n");
                return ;
            }
        }
    }
    printf("equal\n");
}
int main(){
    init();
    solve();
    return 0;
}
