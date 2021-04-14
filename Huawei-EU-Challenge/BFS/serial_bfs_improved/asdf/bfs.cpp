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
string s;
unordered_map<int, bool> vis;

inline char gc(){
    static const int IN_LEN=1<<18|1;
    static char buf[IN_LEN],*s,*t;
    return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
}

template <typename T> inline void read(T &x) {
	char ch = gc(); int f = 1; x = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = gc();}
	while(ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = gc();
	x *= f;
}
template <typename T, typename... Args> inline void read(T &x, Args &...args) {
	read(x), read(args...);
}

int main() {
	int u, v;
	while(gc() != ']') {
		read(u, v);
		points[u].push_back(v);
	}
    cerr << "time taken to input: " << TIME << endl;

    q.push(0);
    vis[0] = 1;
    printf("[0");
    int last = 0;
    while (!q.empty()) {
        int x = q.front(), to;
        if (x)
            printf(",%d", x);
        q.pop();
        for (int i = 0; i < points[x].size(); i ++) {
            to = points[x][i];
            if (!vis[to]) {
                vis[to] = vis[x] + 1;
                q.push(to);
            }
        }
    }
    printf("]");
    cerr << "time taken to finish: " << TIME << endl;
    return 0;
}