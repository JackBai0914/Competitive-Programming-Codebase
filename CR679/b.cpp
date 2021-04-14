/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-25 11:02:40
* @description: 
* /Users/jackbai/Desktop/CR679/b.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv b.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
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

int n;
int rec[200020][2];

stack <int> s;


int ans[200020];

priority_queue <int> q;

int main() {
	cin >> n;

	char inp;	int x; int id = 0;
	for (int i = 1; i <= 2 * n; i ++) {
		cin >> inp;
		if (inp == '+') {
			s.push(++ id);
			rec[i][0] = 0;
		}
		else {
			cin >> x;
			if (s.empty()) {
				cout << "NO" << endl;
				return 0;
			}
			ans[s.top()] = x;
			s.pop();
			rec[i][0] = 1, rec[i][1] = x;
		}
	}

	int c; id = 0;
	for (int i = 1; i <= 2 * n; i ++) {
		if (rec[i][0]) {
			c = -q.top();
			q.pop();
			// cerr << c << " : " << rec[i][1] << endl;
			if (c != rec[i][1]) {
				cout << "NO" << endl;
				return 0;
			}
		}
		else
			q.push(-ans[++id]);
	}

	cout << "YES" << endl;
	for (int i = 1; i <= n; i ++)
		cout << ans[i] << ' ';
	cout << endl;

    return 0;
}