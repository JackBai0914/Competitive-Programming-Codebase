#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int n;
int ban[100010];

priority_queue <int, vector <int>, greater<int> > q;
int ans[100010];


vector <int> rem;

void dfs (int num) {
	if (num >= n - 9) {
		rem.resize(0);
		int last = ans[num - 1];
		while (!q.empty()) {
			rem.push_back(q.top());
			q.pop();
		}
		do {
			bool check = true;
			check &= (ban[last] != rem[0]);
			for (int i = 1; i < rem.size(); i ++)
				check &= (ban[rem[i - 1]] != rem[i]);
			if (check) {
				// for (int i = 1; i <= n; i ++)
					// cout << ban[i] << " ";
				// cout << " : ";
				for (int i = 0; i < num; i ++)
					cout << ans[i] << " ";
				for (int i = 0; i < rem.size(); i ++)
					cout << rem[i] << " ";
				cout << endl;
				
				exit(0) ;
			}
		} while (next_permutation (rem.begin(), rem.end()));
		if (num == n - 9) {
			// cerr << "in charge " << endl;
			for (int i = 0; i < rem.size(); i ++)
				if (rem[i] != ban[ans[num - 1]])
					q.push(rem[i]);
			int beg = num - 1;
			while (beg >= 0 && ban[ans[beg]] == ban[ans[num - 1]]) {
				q.push(ans[beg]);
				beg --;
			}
			// cerr << "beg = " << beg << endl;
			ans[beg + 1] = ban[ans[num - 1]];
			dfs (beg + 2);
			exit(0);
		}
		cout << -1 << endl;
		exit(0);
	}
	if (num == 0) {
		ans[num] = 1;
		q.pop();
		dfs (num + 1);
		return ;
	}
	int c = q.top();
	if (ban[ans[num - 1]] != c) {
		ans[num] = c;
		q.pop();
		dfs (num + 1);
	}
	else {
		q.pop();
		int c2 = q.top();
		ans[num] = c2;
		q.pop();
		q.push(c);
		dfs (num + 1);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> ban[i];
		q.push(i);
	}
	dfs (0);
	// int st = 0;
	// do {
	// 	n = 6;
	// 	st ++;
	// 	int ed = st;
	// 	for (int i = 1; i <= n; i ++) {
	// 		ban[i] = ed % 6 + 1;
	// 		ed /= 6;
	// 		q.push (i);
	// 	}
	// 	dfs (0);
	// } while (st < 6 * 6 * 6 * 6 * 6 * 6);


	return 0;
}