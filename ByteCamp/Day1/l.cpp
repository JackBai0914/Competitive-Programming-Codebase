#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> Point;
const ld eps = 1e-7;
const ld ERROR = 666666;
const Point ERRORP = MP(ERROR, ERROR);
bool if_same (ld a, ld b) {
	return -eps <= (a - b) && (a - b) <= eps;
}
bool if_same (Point a, Point b) {
	return if_same(a.F, b.F) && if_same(a.S, b.S);
}

struct Line {
	ld a, b, c;
	Line() {}
	Line(ld A, ld B, ld C) {a = A, b = B, c = C;}
	Point on_Line (ld x) {
		return MP(x, -(c + a * x) / b);
	}
	Point on_Line_y (ld y) {
		return MP(-(c + b * y) / a, y);
	}
	bool if_on (Point x) {
		return if_same (0, a * x.F + b * x.S + c);
	}
}l[22];
Point cross_point (Line A, Line B) {
	// cerr << "calc cp: " << A.a << " " << A.b << " " << A.c << " , " << B.a << " " << B.b << " " << B.c << endl;
	if (if_same(0, A.a * B.b - B.a * A.b))
		return ERRORP;
	return A.on_Line ((B.c * A.b - A.c * B.b) / (A.a * B.b - B.a * A.b));
}

struct Curve {
	ld a, b, c; //ax^2+bx+c;
	Curve () {}
	Curve (ld aa, ld bb, ld cc) {a = aa, b = bb, c = cc;}
	ld delta() {
		ld ans = b*b-4*a*c;
		if (if_same(ans, 0))
			return 0;
		return ans;
	}
	Point find_zero () {
		if (delta() < 0 - eps)
			return ERRORP;
		return MP((-b-sqrt(delta()))/(2*a), (-b+sqrt(delta()))/(2*a));
	}
};

struct Hypo {
	ld q0, q1, q2, q3, q4, q5;
	Point subs(bool tp, ld a, ld b) {
		if (tp == 0) { // x
			Curve c = Curve(q0 * a * a + q1 * a + q2, q0 * 2 * a * b + q1 * b + q3 * a + q4, q0 * b * b + q3 * b + q5);
			return c.find_zero();
		}
		else {
			Curve c = Curve(q2 * a * a + q1 * a + q0, q2 * 2 * a * b + q1 * b + q4 * a + q3, q2 * b * b + q4 * b + q5);
			return c.find_zero();
		}
	}
	ld delta () {return q1*q1-q0*q2;}
	bool if_on (Point p) {
		return if_same (0, q0 * p.F * p.F + q1 * p.F * p.S + q2 * p.S * p.S + q3 * p.F + q4 * p.S + q5);
	}

}h;

vector <Point> cps;
int n;
int e_num[22];
bool fake[22];

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin >> n;
	cin >> h.q0 >> h.q1 >> h.q2 >> h.q3 >> h.q4 >> h.q5;
	for (int i = 1; i <= n; i ++) {
		cin >> l[i].a >> l[i].b >> l[i].c;
		for (int j = 1; j < i; j ++) {
			if (if_same(0, l[i].a)) {
				if (if_same(0, l[j].a))
					continue ;
				if (if_same(l[i].c / l[i].b, l[j].c / l[j].b)) {
					fake[i] = true;
					break;
				}
			}
			else {
				if (if_same(0, l[j].a))
					continue ;
				ld X1 = l[i].c / l[i].a;
				ld Y1 = l[i].b / l[i].a;
				ld X2 = l[j].c / l[j].a;
				ld Y2 = l[j].b / l[j].a;
				if (if_same(X1, X2) && if_same (Y1, Y2)) {
					fake[i] = true;
					break;
				}
			}
		}
		// cerr << i << " : " << fake[i] << endl;
	}


	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++) {
			if (fake[i] || fake[j])
				continue ;
			Point cp = cross_point(l[i], l[j]);
			if (cp != ERRORP) {
				// cerr << "LL cp : " << cp.F << " " << cp.S << endl;
				cps.push_back(cp);
			}
		}
	for (int i = 1; i <= n; i ++) {
		if (fake[i])
			continue ;
		if (h.delta() > 0 + eps) {
			if ()
		}
		if (if_same(0, l[i].a)) {
			Point cp = h.subs(1, 0, -l[i].c / l[i].b);
			if (cp != ERRORP) {
				cps.push_back(l[i].on_Line(cp.F));
				cps.push_back(l[i].on_Line(cp.S));
			}
		}
		else {
			Point cp = h.subs(0, -l[i].b / l[i].a, -l[i].c / l[i].a);
			if (cp != ERRORP) {
				// cerr << "LH cp: " << cp.F << " " << cp.S << endl;
				cps.push_back(l[i].on_Line_y(cp.F));
				cps.push_back(l[i].on_Line_y(cp.S));
			}
		}
	}


	int p_num = 0;
	sort (cps.begin(), cps.end());
	for (int i = 0; i < cps.size(); i ++) {
		if (i && if_same (cps[i], cps[i - 1]))
			continue ;
		// cerr << "a cp: " << cps[i].F << " " << cps[i].S << endl;
		p_num ++;
		for (int j = 1; j <= n; j ++)
			if (l[j].if_on(cps[i]))
				e_num[j] ++;
		if (h.if_on(cps[i]))
			e_num[0] ++;
	}

	// for (int i = 0; i <= n; i ++) 
		// cerr << i << " : " << e_num[i] << endl;
	//v-e+f=1
	int fans = 1;
	for (int i = 1; i <= n; i ++) {
		if (fake[i])
			continue ;
		fans += e_num[i] + 1;
	}
	fans -= p_num;

	if (if_same (0, h.delta())) {
		// cerr << "should be here " << endl;
		fans += e_num[0] + 1;
	}
	else if (h.delta() < 0) {
		if (e_num[0] == 0)	fans ++;
		else				fans += e_num[0];
	}
	else if (h.delta() > 0) {
		fans += e_num[0] + 2;
	}

	cout << fans << endl;
	return 0;

}