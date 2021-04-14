/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-16 13:00:20
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

char inv (char x) {return (x == 'A' ? 'B' : 'A');}
string inv (string x) {string y = x; for (int i = 0; i < x.size(); i++) y[i] = inv(y[i]); return y;}

vector <string> v, lst;
void dfs (int d) {
	if (d == 1) {
		v.push_back("AB");
		lst = v;
		return ;
	}
	dfs (d - 1);
	v.resize(0);
	for (int i = 0; i < lst.size(); i ++)
		v.push_back(lst[i] + lst[i]);
	for (int i = 0; i < lst.size(); i ++)
		v.push_back(lst[i] + inv(lst[i]));
	// debug("?");
	string c = "";
	for (int i = 0; i < v[0].size() / 2; i ++)	c += 'A';
	for (int i = 0; i < v[0].size() / 2; i ++)	c += 'B';
	// debug("?");
	v.push_back(c);
	lst = v;
} 

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    dfs (n);
    cout << lst.size() << endl;
    for (int i = 0; i < lst.size(); i ++)
    	cout << lst[i] << '\n';
    return 0;
}