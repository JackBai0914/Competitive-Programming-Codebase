#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const ld PI = 3.1415926535897932384626;
const ld eps = 1e-14;
const ld oo = 1e15;

ld sqr(ld x) {return x * x;}
bool if_eq (ld a, ld b) {return -eps < a - b && a - b < eps;}
bool limite(ld l, ld v, ld r) {if (l > r) swap(l, r); return l - eps <= v && v <= r + eps;}

struct Point {
	ld x, y;
	Point() : x(0), y(0) {}
	Point(ld x, ld y) : x(x), y(y) {}

	friend istream &operator >> (istream &in, Point &inp) {in >> inp.x >> inp.y; return in;}
	friend ostream &operator << (ostream &out, Point outp) {out << outp.x << " " << outp.y; return out;}
	
	Point operator + (const Point p) const {return Point(x + p.x, y + p.y);}
	Point operator - (const Point p) const {return Point(x - p.x, y - p.y);}
	ld operator * (const Point p) const {return x * p.y - y * p.x;} //cross
	Point operator * (ld k) {return Point(x * k, y * k);}
	Point operator / (ld k) {return Point(x / k, y / k);}
	bool operator < (const Point p) const {return if_eq(x, p.x) ? y < p.y : x < p.x;}
	
	ld dis() const {return hypot(x, y);}
	ld angle() const {return atan2(y, x);}
	Point rotate(ld ang) {return *this = Point(dis() * cos(angle() + ang), dis() * sin(angle() + ang));}
	Point rotate(ld ang, Point o) {return *this = (*this - o).rotate(ang) + o;}
	Point make_point(ld dis, Point ori) {return (ori - *this) * dis / ((ori - *this).dis() + eps) + *this;}  //very important
	Point make_point(ld dis, Point ori, ld ang) {return make_point(dis, ori.rotate(ang, *this));}
	
	Point fix() {x = limite(-eps, x, eps) ? 0 : x; y = limite(-eps, y, eps) ? 0 : y; return *this;}
};

struct Line {
	Point a, b;
	
	Line() {}
	Line(Point a, Point b) : a(a), b(b) {}
	Line(ld ax, ld ay, ld bx, ld by) : a(ax, ay), b(bx, by) {}
	
	bool operator < (const Line l) const {return a < l.a;}
	Line fix() {a.fix(), b.fix();			return *this;}
	Line order() {if (b < a) swap(a, b); 	return *this;}
};

struct Circle {
	Point o;
	ld r;
	Circle() {}
	Circle(Point o, ld r) : o(o), r(r) {}
	Circle(ld x, ld y, ld r) : o(x, y), r(r) {}

	friend istream & operator >> (istream &in, Circle &inc) {in >> inc.o >> inc.r; return in;}
	friend ostream & operator << (ostream &out, Circle &outc) {out << outc.o << " " << outc.r; return out;}

	bool Cover (Circle c) {
		if (r < c.r)
			return c.Cover (*this);
		return (o-c.o).dis() + c.r <= r + eps;
	}
	Line tangent(Point p) {
		ld ang = atan2(sqrt(sqr((p - o).dis()) - sqr(r)), r);
		return Line(o.make_point(r, p, ang), o.make_point(r, p, -ang));
	}
	pair<Line, Line> ex_tangent(Circle c) {
		if (r < c.r)
			return c.ex_tangent(*this);
		ld ang = acos((r - c.r) / (o - c.o).dis());
		Point ans1 = o.make_point(r, c.o, ang), ans2 = o.make_point(r, c.o, -ang);
		Point pre1 = o.make_point(r - c.r, c.o, ang), pre2 = o.make_point(r - c.r, c.o, -ang);
		return make_pair(Line(ans1, c.o + ans1 - pre1), Line(ans2, c.o + ans2 - pre2));
	}
	bool on_cir (Point x) {
		return if_eq(r, (x - o).dis());
	}
};

vector <Point> hull;
namespace ConvexHull {
	vector <Point> ps;
	bool fake[5000050];
	
	bool ord (Point a, Point b) {
		return (if_eq(a.y,b.y) ? a.x < b.x : a.y < b.y);
	}
	ld cha (Point a, Point b) {
		return a.x * b.y - b.x * a.y;
	}

	vector <Point> q1, q2;
	void main() {
		memset(fake, 0, sizeof fake);
		if (ps.empty())
			return ;
	// cerr << "here " << endl;
		
		sort (ps.begin(), ps.end(), ord);
		for (int i = 1; i < ps.size(); i ++)
			if (if_eq(ps[i].x, ps[i - 1].x) && if_eq(ps[i].y, ps[i - 1].y))
				fake[i] = true;
	// cerr << "here " << endl;

		q1.push_back(ps[0]);
		int pt = 1;
		while (pt < ps.size()) {
			if (fake[pt]) {
				pt ++;
				continue ;
			}
			while (q1.size() >= 2 && 
				   cha(q1[q1.size() - 1] - q1[q1.size() - 2], ps[pt] - q1[q1.size() - 2]) < eps) {
				// cout << "pop " << q1[q1.size() - 1] << endl;
				q1.pop_back();
			}

			// cout << "add " << ps[pt] << endl;
			q1.push_back (ps[pt]);
			pt ++;
		}
	// cerr << "here " << endl;

		pt = ps.size() - 2;
		q2.push_back(ps[ps.size() - 1]);
		while (pt >= 0) {
			if (fake[pt]) {
				pt --;
				continue ;
			}
			while (q2.size() >= 2 && 
				   cha(q2[q2.size() - 1] - q2[q2.size() - 2], ps[pt] - q2[q2.size() - 2]) < eps)
				q2.pop_back();
			q2.push_back (ps[pt]);
			pt --;
		}
	// cerr << "here " << endl;

		for (int i = 0; i < q1.size() - 1; i ++)
			hull.push_back (q1[i]);
		for (int i = 0; i < q2.size() - 1; i ++)
			hull.push_back (q2[i]);
	}
}

int n;
Circle cs[1010];

ld fans = 0;
void process (Circle c, Point p1, Point p2) {
	ld ang = atan2(p2.y - c.o.y, p2.x - c.o.x) - atan2(p1.y - c.o.y, p1.x - c.o.x);
	if (ang < 0)
		ang += 2 * PI;
	ld mx = ang * c.r, mn = 2 * PI * c.r - mx;
	if (mx < mn)
		swap (mx, mn);

	if (ConvexHull::cha(p2 - p1, c.o - p1) > eps)
		fans = max (fans, mn);
	else
		fans = max (fans, mx);
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> cs[i];
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++) {
			// if (cs[i].Cover(cs[j]))
			// 	continue ;
			pair<Line, Line> ex_t = cs[i].ex_tangent(cs[j]);
			ConvexHull::ps.push_back (ex_t.F.a);
			ConvexHull::ps.push_back (ex_t.F.b);
			ConvexHull::ps.push_back (ex_t.S.a);
			ConvexHull::ps.push_back (ex_t.S.b);

		}

	ConvexHull::main();
	// cerr << "here " << endl;


	// for (int i = 0; i < hull.size(); i ++)
	// 	cerr << hull[i] << endl;

	for (int i = 0; i < hull.size(); i ++) {
		Point fir = hull[i], sec = (i == hull.size() - 1? hull[0] : hull[i + 1]);
		for (int j = 1; j <= n; j ++)
			if (cs[j].on_cir(fir) && cs[j].on_cir(sec)) {
				process (cs[j], fir, sec);
				break;
			}
	}
	cout << setprecision(20) << fans << endl;
	return 0;
}