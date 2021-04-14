#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <time.h>
#include "Graph.h"
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

void ReadEdges(Graph &g)
{
	int u, v;
	while(inputchar() != ']') {
		read(u, v);
        g.addEdge(u, v);
	}
}

int main()
{
	// freopen("graph_1000000_nodes.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	Graph g(2000000);
	ReadEdges(g);
	clock_t start = clock();
	// cout << "[";
	g.BAGPBFS(0);
	// cout << "]";
	clock_t end = clock();
	cout << "Process time: " << (end - start) << endl;
}