/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-11 15:18:36
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

int T;
int n, k;
ll a[3000010], b[3000010];

vector <ll> cand1, cand2, cand3, cand4;
vector <ll> s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; t ++) {
    	cin >> n >> k;
    	memset(a, 0, sizeof a);
    	memset(b, 0, sizeof b);
    	for (int i = 0; i < n; i ++)	cin >> a[i];
    	for (int i = 0; i < n; i ++)	cin >> b[i];
    	sort(a, a + n);
    	sort(b, b + n);
    	ll ans0 = 0, ans1 = 0;
        cand1.resize(0);
        cand2.resize(0);
        cand3.resize(0);
        cand4.resize(0);
    	for (int i = 0; i < n && a[i] <= 0 && b[n - i - 1] > 0; i ++)
            cand1.push_back(-a[i] * b[n - i - 1]);
        for (int i = n - 1; i >= 0 && a[i] > 0 && b[n - i - 1] <= 0; i --)
            cand2.push_back(-a[i] * b[n - i - 1]);
        int k2 = 0, pt1 = 0, pt2 = 0;
        while (pt1 != cand1.size() && pt2 != cand2.size() && k2 != k) {
            ll c1 = abs(cand1[pt1]);
            ll c2 = abs(cand2[pt2]);
            if (c1 > c2) {ans0 += c1; pt1 ++; k2 ++;}
            else {ans0 += c2; pt2 ++; k2 ++;}
        }
        while (pt1 != cand1.size() && k2 != k) {ans0 += cand1[pt1]; pt1 ++; k2 ++;}
        while (pt2 != cand2.size() && k2 != k) {ans0 += cand2[pt2]; pt2 ++; k2 ++;}
        if (k2 < k) {
            for (int i = cand1.size(); i < n && a[i] <= 0; i ++) {
                // cerr << ":3 " << -a[i] << endl;
                cand3.push_back(-a[i]);
            }
            for (int i = cand1.size(); i < n && b[n - i - 1] > 0; i ++) {
                // cerr << ":4 " << b[n - i - 1] << endl;
                cand4.push_back(b[n - i - 1]);
            }
            for (int i = n - cand2.size() - 1; i >= 0 && a[i] > 0; i --) {
                // cerr << ":5 " << a[i] << endl;
                cand3.push_back(a[i]);
            }
            for (int i = n - cand2.size() - 1; i >= 0 && b[n - i - 1] <= 0; i --) {
                // cerr << ":6 " << -b[n - i - 1] << endl;
                cand4.push_back(-b[n - i - 1]);
            }
            sort(cand3.begin(), cand3.end());
            sort(cand4.begin(), cand4.end());
            for (int i = 0; i < cand3.size() && i < k - k2; i ++)
                ans0 -= cand3[i] * cand4[k - k2 - i - 1];
        }

    	cand1.resize(0);
        cand2.resize(0);
        cand3.resize(0);
        cand4.resize(0);
    	for (int i = 0; i < n && a[i] <= 0 && b[i] <= 0; i ++)
    		cand1.push_back(a[i] * b[i]);
        for (int i = n - 1; i >= 0 && a[i] > 0 && b[i] > 0; i --) {
            // cerr << ":8 " << a[i] << " " << b[i] << endl;
            cand2.push_back(a[i] * b[i]);
        }
        k2 = 0, pt1 = 0, pt2 = 0;
        while (pt1 != cand1.size() && pt2 != cand2.size() && k2 != k) {
            ll c1 = cand1[pt1];
            ll c2 = cand2[pt2];
            if (c1 > c2) {ans1 += c1; pt1 ++; k2 ++;}
            else {ans1 += c2; pt2 ++; k2 ++;}
        }
        while (pt1 != cand1.size() && k2 != k) {ans1 += cand1[pt1]; pt1 ++; k2 ++;}
        while (pt2 != cand2.size() && k2 != k) {ans1 += cand2[pt2]; pt2 ++; k2 ++;}

        if (k2 < k) {
            for (int i = cand1.size(); i < n && a[i] <= 0; i ++)
                cand3.push_back(-a[i]);
            for (int i = cand1.size(); i < n && b[i] <= 0; i ++)
                cand4.push_back(-b[i]);
            for (int i = n - cand2.size() - 1; i >= 0 && a[i] > 0; i --)
                cand3.push_back(a[i]);
            for (int i = n - cand2.size() - 1; i >= 0 && b[i] > 0; i --)
                cand4.push_back(b[i]);
            sort(cand3.begin(), cand3.end());
            sort(cand4.begin(), cand4.end());
            for (int i = 0; i < cand3.size() && i < k - k2; i ++)
                ans1 -= cand3[i] * cand4[k - k2 - i - 1];
        }
        
        // for (int i = 0; i <= k; i ++) {
        //     if (i > cand1.size() || k - i > cand2.size())
        //         continue ;
        //     ans1 = max (ans1, s1[i] + s2[k - i]);
        // }
    	cout << "Case #" << t << ": " << -ans0 << " " << ans1 << endl;
    }
    return 0;
}