/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-26 15:30:48
* @description: 
* /Users/jackbai/Desktop/并行计算/serial_bfs/bfs.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv bfs.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <queue>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

queue <int> q;
unordered_map<int, vector <int> > points;
// vector <int> points[1000010];
string s;
unordered_map<int, int> vis;

int main() {
    cin >> s;
    F0R (i, s.size())
        if (s[i] < '0' || s[i] > '9')
            s[i] = ' ';
    stringstream s2;
    s2 << s;
    int st, ed;
    while (s2 >> st >> ed) {
        points[st].push_back(ed);
        // points[ed].push_back(st);
    }
    // for (int i = 0; i < 1000; i ++)
    // 	for (int j = 0; j < 1000; j ++)
    // 		if (mp[i][j] % 1) {
    // 			cerr << "error! " << i << " " << j << endl;
    // 		}
    q.push(0);
    vis[0] = 1;
    cout << "[0";
    int last = 0;
    // for (int i = 0; i < points[6].size(); i ++)
    	// cerr << 6 << " : " << points[6][i] << endl;
    while (!q.empty()) {
        int x = q.front(), to;
        // if (vis[x] != last) {
        // 	cout << endl;
        // 	last = vis[x];
        // }
        if (x)
	        cout << ',' << x;
        q.pop();
        for (int i = 0; i < points[x].size(); i ++) {
            to = points[x][i];
            if (!vis[to]) {
                vis[to] = vis[x] + 1;
                q.push(to);
                // cerr << x << " -> " << to << endl;
            }
        }
    }
    cout << ']';
    return 0;
}