#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;

namespace Input_Opt {
	namespace Input {
		const int BUF = 65536;
		char buf[BUF];
		char *head = buf, *tail = buf;
	}
	inline char inputchar() {
		using namespace Input;
		if (head == tail)
			*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
		return *head ++;
	}
	inline void inputstring(string &st1)
	{
		char ch = inputchar();
		st1 = "";
		while (!((ch>='a')&&(ch<='z')))
		  ch=inputchar();
		while ((ch>='a')&&(ch<='z')) 
		  st1+=ch,ch=inputchar();
	}
}using namespace Input_Opt;
string s, t;

const ll B = 233, iB = 90128756, iB2 = 266094423;
ll facs[200020], ifacs[200020];
ll facs2[200010], ifacs2[200020];
ll kmi (ll x, ll t, ll mod) {
	ll ans = 1;
	while (t) {
		if (t & 1)	ans = ans * x % mod;
		x = x * x % mod;
		t >>= 1;
	}
	return ans;
}
ll inv (ll x, ll mod)	{return kmi (x, mod - 2, mod);}

int cnt[26];
ull Hash (string s) {
	memset (cnt, 0, sizeof cnt);
	for (int i = 0; i < s.size(); i ++)
		cnt[s[i] - 'a'] ++;
	ull base = 0;
	for (int i = 0; i < 26; i ++)
		base += facs[i] * cnt[i];
	return base;	
}
ull modify (int val, int dt) {
	return facs[val - 'a'] * dt;
}


ll sum[200020];
ll sum2[200020];
void prep_hash () {
	sum[0] = facs[0] * t[0];
	sum2[0] = facs2[0] * t[0];
	for (int i = 1; i < t.size(); i ++) {
		sum[i] = (sum[i - 1] + facs[i] * t[i]) % mod;
		sum2[i] = (sum2[i - 1] + facs2[i] * t[i]) % mod2;
	}
}
pair <ll, ll> seg (int st, int ed) {
	if (st == 0)
		return make_pair (sum[ed], sum2[ed]);
	ll s1 = (sum[ed] - sum[st - 1] + mod) * ifacs[st] % mod;
	ll s2 = (sum2[ed] - sum2[st - 1] + mod2) * ifacs2[st] % mod2;
	return make_pair (s1, s2);
}

map <pair <ll, ll>, int> mp;
int fans = 0;

int main() {
	/*
	facs[0] = facs2[0] = ifacs[0] = ifacs2[0] = 1;
	for (int i = 1; i <= 200000; i ++) {
		facs[i] = facs[i - 1] * B % mod;
		ifacs[i] = ifacs[i - 1] * iB % mod;
		facs2[i] = facs2[i - 1] * B % mod2;
		ifacs2[i] = ifacs2[i - 1] * iB2 % mod2;
	}

	// inputstring(s);
	// inputstring(t);
	s.resize(200000);
	t.resize(200000);
	scanf("%s", &s);
	scanf("%s", &t);


	// cin >> s >> t;
	// cerr << t << " " << s << endl;
	if (s.size() > t.size()) {
		cout << 0 << endl;
		return 0;
	}
	prep_hash();

	ull hash_s = Hash (s);

	ull cur = Hash (t.substr(0, s.size()));
	int ep = s.size() - 1;
	do {
		ep ++;
		if (cur == hash_s) {
			pair <ll, ll> hash_cur = seg (ep - s.size(), ep - 1);
			fans += (!mp[hash_cur]);
			mp[hash_cur] = 1;
		}
		if (ep != t.size()) {
			cur += modify (t[ep - s.size()], -1);
			cur += modify (t[ep], 1);
		}
	} while (ep != t.size());

	cout << fans << endl;
	*/
	char *s;
	scanf ("%s", s);
	cout << s.len() << endl;
	return 0;
}