#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <queue>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;

unordered_map<int, vector <int> > points;

int q[2000020], qst = 1, qed = 0;
int hd[2000020], tl[2000020], egf[2000020], egs[2000020], est = 0;
bool fir[2000020], vis[2000020];

namespace IO_opt {
    const int BUF = 65536;
    char buf[BUF + 1];
    char *head = buf, *tail = buf;

    inline char inputchar()
    {
        if(head == tail)
            *(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
        return *head++;
    }
    template <typename T> inline void read(T &x, T &y) {
    	char ch = inputchar(); int f = 1; x = 0;
        while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = inputchar();}
        while(ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = inputchar();
        x *= f;

        ch = inputchar(); f = 1; y = 0;
        while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = inputchar();}
        while(ch >= '0' && ch <= '9') y = y*10+ch-'0', ch = inputchar();
        y *= f;
    }

    #define I_int int
    inline void write(I_int x) {
        if(x<0) putchar('-'),x=-x;
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
    #undef I_int
} using namespace IO_opt;



int main() {
	int u, v;
	while(inputchar() != ']') {
		read(u, v);
        egs[tl[u]] = ++est;
        egf[est] = v;
        tl[u] = est;
        if (fir[u] == false)
            hd[u] = est, fir[u] = true;
	}
    vis[0] = true;

    putchar('[');
    putchar('0');
    int x, e, to;
    for (e = hd[0]; e; e = egs[e])
        if (vis[egf[e]] == false)
            vis[egf[e]] = true, q[++ qed] = egf[e];

    int cst, ced, id;
    while (qst <= qed) {
        // cst = qst, ced = qed;
        // #pragma omp parallel for
        // for (id = cst; id <= ced; id ++) {
            x = q[qst ++];
            putchar(',');
            write(x);
            for (e = hd[x]; e; e = egs[e]) {
                to = egf[e];
                if (vis[to] == false) {
                    vis[to] = true;
                    q[++ qed] = to;
                }
            }
        // }
        // qst = ced + 1;
    }
    putchar(']');
    // cerr << "time taken to finish: " << TIME << endl;
    return 0;
}