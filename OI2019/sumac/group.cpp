#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#define SQRT3 1.7320508075688772
#define SQRT2 1.4142135623730951
using namespace std;
const int mx = 1010;
const int oo = 1e9;
int n;
int dis[mx][mx]; //the adjacent matrix
int point[mx], te = 0; //the adjacent chain
struct e {int to, next;} edge[mx * 20 * 2]; //storing edges
void add (int x, int y)  //adding an edge
{edge[++ te].to = y; edge[te].next = point[x]; point[x] = te;}

void build_graph () {
	//inicialize the graph
	te = 0;
	for (int i = 0; i < (1 << n); i ++)
		for (int j = 0; j < (1 << n); j ++)
			dis[i][j] = (i == j ? 0 : oo);
	//build the edges
	for (int i = 0; i < (1 << n); i ++)
		for (int j = 0; j < n; j ++)
			dis[i][i ^ (1 << j)] = 1, add(i, i ^ (1 << j));
	//using Floyd algorithm to find the shortest distances.
	for (int k = 0; k < (1 << n); k ++)
		for (int i = 0; i < (1 << n); i ++)
			for (int j = 0; j < (1 << n); j ++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

//Dec_to_Bi() transforms a decimal number to a binary string
string Dec_to_Bi (int x) {
	string y;
	while (x) y += 'a' + x % 2, x /= 2; 
	while (y.size() < n) y += 'a';
	return y;
}

namespace Max_Ind {
	int ans = 0; //recording answer
	int rec[mx];
	long long cnt = 0;
	void dfs(vector <int> legal, vector <int> chosed) {
		if (legal.size() + chosed.size() <= ans)
			return ;//searching optimization
		if (legal.empty()) { //find an answer
			ans = chosed.size();
			for (int i = 0; i < ans; i ++)
				rec[i] = chosed[i];
			return ;
		}
		int key = legal[0];
		for (int i = 0; i < legal.size(); i ++) {
			int c = legal[i];
			//key optimization of Bron-Kerbosch Algorithm
			if (dis[c][key] > 2)
				continue;
			vector <int> _legal, _chosed;
			_chosed = chosed;
			_chosed.push_back(c);
			for (int j = i + 1; j < legal.size(); j ++)
				if (dis[c][legal[j]] > 2)
					_legal.push_back(legal[j]);
			//iteration
			dfs(_legal, _chosed);
		}
	}

	void main() {
		ans = 0;
		vector <int> _legal, _chosed;
		for (int i = 0; i < (1 << n); i ++)
			_legal.push_back(i);
		dfs(_legal, _chosed);
		cout << "Max Independent Point Set(n=" << n << "): size=" << ans << endl;
		for (int i = 0; i < ans; i ++)
			cout << Dec_to_Bi(rec[i]) << " ";
		cout << endl;
	}
}

int main() {
	for (int i = 1; i <= 7; i ++) {
		n = i;
        build_graph();
        Max_Ind::main();
    }
	return 0;
}