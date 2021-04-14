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

ll d;

bool p[1000010];
bool flag[1000010];

void is_prime () {
	for (int i = 2; i < 100000; i ++) {
		if (!flag[i]) {
			p[i] = true;
			for (int j = 1; i * j < 100000; j ++)
				flag[i * j] = true;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    is_prime();
    while (t --) {
    	cin >> d;
    	int fst = d + 1;
    	while (p[fst] == 0)
    		fst ++;
    	int snd = fst + d;
    	while (p[snd] == 0)
    		snd ++;
    	cout << fst * snd << endl;
    }
    return 0;
}