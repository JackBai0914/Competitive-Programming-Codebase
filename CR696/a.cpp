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

string b;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t --) {
    	int n;
    	cin >> n;
    	cin >> b;
    	int lst = -1;
    	for (int i = 0; i <b.size(); i ++) {
    		if (b[i] == '0') {
    			if (lst == 1)	cout << '0', lst = 0;
    			else			cout << '1', lst = 1;
    		}
    		if (b[i] == '1') {
    			if (lst == 2)	cout << '0', lst = 1;
    			else			cout << '1', lst = 2;
    		}
    	}
    	cout << endl;
    }
    return 0;
}