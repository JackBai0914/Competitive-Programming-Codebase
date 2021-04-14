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
unordered_map<int, bool> vis;

// unordered_map<int, int> pt;
int q[2000020], qst = 1, qed = 0;
int pt[2000020], egf[2000020], egs[2000020], est = 0;
int hp[1000010], hst = 0;

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

    template <typename T> inline void read(T &x) {
    	char ch = inputchar(); int f = 1; x = 0;
    	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = inputchar();}
    	while(ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = inputchar();
    	x *= f;
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
        est ++;
        egf[est] = v;
        egs[est] = pt[u];
        pt[u] = est;
	}
    // cerr << "time taken to input: " << TIME << endl;

    vis[0] = true;
    putchar('[');
    putchar('0');
    // printf("[0");
    int last = 0, x, to;
    int e, i;

    hst = 0;
    for (e = pt[0]; e; e = egs[e]) 
        hp[hst++] = egf[e];
    for (i = hst - 1; i >= 0; i --) {
        to = hp[i];
        if (!vis[to]) {
            vis[to] = true;
            q[++ qed] = to;
        }
    }

    while (qst <= qed) {
        x = q[qst ++];
        putchar(',');
        write(x);
        hst = 0;
        for (e = pt[x]; e; e = egs[e]) 
            hp[hst++] = egf[e];
        for (i = hst - 1; i >= 0; i --) {
            to = hp[i];
            if (!vis[to]) {
                vis[to] = true;
                q[++ qed] = to;
            }
        }
    }
    putchar(']');
    cerr << "time taken to finish: " << TIME << endl;
    return 0;
}