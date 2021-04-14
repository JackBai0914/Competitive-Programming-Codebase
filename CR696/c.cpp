/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-19 14:33:26
* @description: 
*  
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 
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
const int mod = 1000000007; 
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n;
int a[1000010];

bool flag[1000010];
vector<int> bar[1000010];
int pter[1000010];
vector <pair <int, int> > rec;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t --) {
		cin >> n;
    	rec.resize(2 * n + 10);
		for (int i = 1; i <= 2 * n; i ++) {
			cin >> a[i];
			
		}
		sort(a + 1, a + 2 * n + 1);

		for (int i = 1; i <= 2 * n; i ++)
			bar[a[i]].push_back(i);
		bool found = false;
		int ans = 0;
		for (int s = 1; s < 2 * n; s ++) {
			for (int i = 1; i <= 2 * n; i ++)
				flag[i] = false, pter[a[i]] = 0;
			int x = a[s] + a[2 * n], pt = 2 * n;
			bool ok = true;
			int rst = 0;
			while (pt != 0) {
				// cerr << "next loop" << endl;
				while (pt && flag[pt])
					pt --;
				if (pt == 0)
					break;
				flag[pt] = true;
				int o = x - a[pt];
				// cerr << "start with" << a[s] + a[2 * n] << ", have " << a[pt] << " , found" << o << endl;
				if (o <= 0) {
					ok = 0;
					break;
				}
				while (pter[o] < bar[o].size() && flag[bar[o][pter[o]]] == true)
					pter[o] ++;
				if (pter[o] >= bar[o].size()) {
					ok = 0;
					break;
				}
				// cerr << "find a " << o << endl;
				flag[bar[o][pter[o] ++]] = true;
				x = a[pt];
				rec[++ rst] = MP(a[pt], o);
			}
			if (!ok)
				continue;
			else {
				ans = s;
				found = true;
				break;
			}
			
		}    	
		if (found) {
			cout << "YES" << endl;
			cout << a[ans] + a[2 * n] << endl;
			for (int i = 1; i <= n; i ++)
				cout << rec[i].F << " " << rec[i].S << endl;
		}
		else {
			cout << "NO" << endl;
		}

		for (int i = 1; i <= 2 * n; i ++) {
			bar[a[i]].resize(0);
			pter[a[i]] = 0;
		}
    }
    return 0;
}