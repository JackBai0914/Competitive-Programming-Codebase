#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <queue>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;

queue <int> q;
unordered_map<int, vector <int> > points;
unordered_map<int, bool> vis;

// unordered_map<int, int> pt;
int pt[2000020];
int egf[2000020], egs[2000020];
int est = 0;
int hp[1000010];
int hst = 0;

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
template <typename T, typename... Args> inline void read(T &x, Args &...args) {
	read(x), read(args...);
}



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

    q.push(0);
    vis[0] = true;
    printf("[0");
    int last = 0, x, to;
    int e, i;
    while (!q.empty()) {
        x = q.front();
        if (x)
            printf(",%d", x);
        q.pop();
        hst = 0;
        for (e = pt[x]; e; e = egs[e]) 
            hp[hst++] = egf[e];
        for (i = hst - 1; i >= 0; i --) {
            to = hp[i];
            if (!vis[to]) {
                vis[to] = true;
                q.push(to);
            }
        }
    }
    printf("]");
    // cerr << "time taken to finish: " << TIME << endl;
    return 0;
}