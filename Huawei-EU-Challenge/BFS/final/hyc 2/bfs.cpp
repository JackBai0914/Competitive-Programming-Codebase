#include <iostream>
#include <time.h>
using namespace std;

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
#define MAXN 2000050
	int pt[MAXN], egf[MAXN], egs[MAXN], est = 0;
	int hp[MAXN], hst = 0;
	int V;
	void addEdge(int u, int v)
	{
		est ++;
        egf[est] = v;
        egs[est] = pt[u];
        pt[u] = est;
	}
	int q[MAXN], qst = 1, qed = 0;
	int ans[MAXN], anstot;
	bool vis[MAXN];
	int L[MAXN], L2[MAXN]; 
	void PBFS(int s)
	{
		int *F, *G;
		F = L, G = L2;
		L[0] = L2[0] = 0;
		vis[0] = 1; L[++L[0]] = s;
		cout << '[' << s;
		while(*F)
		{
	#pragma omp parallel for
			for (int i = 1; i <= F[0]; i++)
			{
				int x = F[i];
	#pragma omp critical
				{
  				    for (int e = pt[x]; e; e = egs[e]) {
            			int to = egf[e];
            			if (!vis[to]) {
							ans[++ans[0]] = to;
               			 	vis[to] = true;
                			G[++G[0]] = to;
           				}
        			}
				}
			}
			swap(F, G), G[0] = 0;
		}
		// cerr << (double)clock() / CLOCKS_PER_SEC << endl;
		for(int i = 1; i <= ans[0]; i++) printf(",%d", ans[i]);
		cout << ']';
	}
void ReadEdges()
{
	int u, v;
	while(inputchar() != ']') {
		read(u, v);
        addEdge(u, v);
	}
}

int main()
{
	ReadEdges();
	PBFS(0);
}