#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#define F first
#define S second
#define MP make_pair
using namespace std;

namespace Hash {
	typedef long long ll;
	const int mod1 = 1e9 + 9;
	const int mod2 = 1e9 + 7;
	const int C = 233;
	ll iC1, iC2;
	typedef pair <ll, ll> hash_element;
	bool _equal(hash_element a, hash_element b)
	{return a.F == b.F && a.S == b.S;}
	hash_element operator * (const hash_element a, const hash_element b) {
		return MP (b.F * a.F % mod1, b.S * a.S % mod2);
	}
	hash_element operator - (const hash_element a, const hash_element b) {
		return MP ((a.F - b.F + mod1) % mod1, (a.S - b.S + mod2) % mod2);
	}

	ll pow1[1000010], pow2[1000010];
	ll ipow1[1000010], ipow2[1000010];

	ll kmi (ll x, ll t, ll mod) {
		ll ans = 1;
		for (x %= mod; t; (x *= x) %= mod, t >>= 1)
			if (t & 1)
				(ans *= x) %= mod;
		return ans;
	}
	ll inv (ll x, ll mod) {return kmi (x, mod - 2, mod);}
	void ini () {
		pow1[0] = pow2[0] = ipow1[0] = ipow2[0] = 1;
		iC1 = inv(C, mod1);
		iC2 = inv(C, mod2);
		for (int i = 1; i <= 1e6; i ++) {
			pow1[i] = pow1[i - 1] * C % mod1;
			pow2[i] = pow2[i - 1] * C % mod2;		
			ipow1[i] = ipow1[i - 1] * iC1 % mod1;
			ipow2[i] = ipow2[i - 1] * iC2 % mod2;			
		}
	}

	struct hash_info {
		vector <hash_element> v;
		hash_info() {}
		hash_info (string s) {
			ll cur1 = 0, cur2 = 0;
			v.resize(0);
			for (int i = 0; i < s.size(); i ++) {
				cur1 = (cur1 * C + s[i]) % mod1;
				cur2 = (cur2 * C + s[i]) % mod2;
				v.push_back(MP(cur1, cur2));
			}
		}
		hash_element extract(int l, int r) {
			// if (l) {
			// 	cerr << ":" << v[l - 1].F << " " << v[l - 1].S << endl;
			// 	cerr << "!" << MP(pow1[r - l], pow2[r - l]).F << " " << MP(pow1[r - l], pow2[r - l]).S << endl;
			// 	cerr << "@" << (MP(pow1[r - l], pow2[r - l]) * v[l - 1]).F << " " << (MP(pow1[r - l], pow2[r - l]) * v[l - 1]).S << endl;
			// }	
			if (!l)	return v[r];
			else	return v[r] - (v[l - 1] * MP(pow1[r - l + 1], pow2[r - l + 1]));
		}
	};
} using namespace Hash;

int main() {
	ini();

	
	string s;
	cin >> s;
	hash_info s_info(s);

	
		



	return 0;
}