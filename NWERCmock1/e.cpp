/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-26 19:54:40
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
bool isDigit(char c) {return '0' <= c && c <= '9';}
string A, B;

typedef struct node {
	vector <int> box;
	node *l, *r;
	int stat; //0: random, 1: fixed, 2: sorted
} *pnode;

int ed = 0;
pnode build (const string &s, int st) {
	if (s[st] == '[') {
		//bottom
		pnode ne = new node();
		ne->stat = 1;
		int c = 0;
		for (int i = 1; s[i] != ']'; ++ i, ed = i) {
			if (isDigit(s[i]))
				c = c * 10 + s[i] - '0';
			else {
				ne->box.push_back(c);
				c = 0;
			}
		}
		ne->box.push_back(c);
		return ne;
	}
	else if (s[st] == 's' && s[st + 1] == 'o') {
		pnode ne = build(s, st + 8);
		ne->stat = 2;
		ed ++;
		return ne;
	}
	else if (s[st] == 's' && s[st + 1] == 'h') {
		pnode ne = build(s, st + 8);
		ne->stat = 0;
		ed ++;
		return ne;
	}
	else {
		pnode l = build(s, st + 7);
		pnode r = build(s, ed + 2);
		pnode ne = new node();
		ne->l = l; ne->r = r;
		return ne;
	}
}
pnode ra, rb;

vector <int> extract (pnode ra) {

}

bool equal (vector <int> a, vector <int> b) {

}

bool allEqual (vector <int> a) {

}

bool compare(pnode ra, pnode rb) {
	if (ra->stat > rb->stat)
		swap(ra , rb);
	if (ra->stat == 0 && rb->stat == 0) {
		vector <int> va = extract(ra);
		vector <int> vb = extract(rb);
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		return equal(va, vb);
	}
	if (ra->stat == 0 && ra->stat == 2) {
		vector <int> va = extract(ra);
		vector <int> vb = extract(rb);
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		if (!equal(va, vb) || !allEqual(va))
			return false;
		else
			return true;
	}
	
}

int main() {
    ios::sync_with_stdio(false);
    cin >> A >> B;
    ra = build(A, 0);
    rb = build(B, 0);
    bool ans = compare(ra, rb);
    return 0;
}