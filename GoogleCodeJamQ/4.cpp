/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-26 13:37:50
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

int T, N, Q;
int ord[55];

int query (int a, int b , int c) {
	cout << a << " " << b << " " << c << endl;
	int ans;	cin >> ans;	
	// cerr << "got " << ans << endl; 
	return ans;
}
void output () {
	for (int i = 1; i <= N; i ++)
		cout << ord[i] << ' ';
	cout << endl;
	// for (int i = 1; i <= N; i ++)
	// 	cerr << ord[i] << ' ';
	// cerr << endl;
	int ans;	cin >> ans;
}

int iterate (int st, int ed, int id) {
	if (st == ed)
		return st;
	if (st + 1 == ed) {
		if (st) {
			int pans = query(ord[st], ord[ed], id);
			if (pans == id)			return st;
			if (pans == ord[ed])	return ed;
		}
		else {
			int pans = query(ord[ed], ord[ed + 1], id);
			if (pans == ord[ed])return st;
			if (pans == id)		return st + 1;
		}
	}
	int gap = (ed - st + 1) / 3;
	int p1 = st + gap, p2 = st + gap + gap;
	int pans = query (ord[p1], ord[p2], id);
	if (pans == ord[p1])	return iterate(st, p1 - 1, id);
	if (pans == id)			return iterate(p1, p2 - 1, id);
	if (pans == ord[p2])	return iterate(p2, ed, id);
}

void guess (int x) {
	int pos = iterate (0, x - 1, x);
	for (int i = x; i > pos + 1; i --)
		ord[i] = ord[i - 1];
	ord[pos + 1] = x;
	// cerr << " : ";
	// for (int i = 1; i <= x; i ++)
	// 	cerr << ord[i] << ' '; cerr << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T >> N >> Q;
    // cerr << T << " " << N << " " << Q << endl;
    for (int t = 1; t <= T; t ++) {
    	ord[1] = 1, ord[2] = 2;
    	for (int n = 3; n <= N; n ++)
    		guess (n);
    	output();
    }
    return 0;
}