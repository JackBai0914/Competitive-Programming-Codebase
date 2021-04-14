#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
#define double long double
using namespace std;
const int maxn = 55;
const double limit = CLOCKS_PER_SEC * 10.0;
const double c = 1e-3, delta = 1e-7;
int n;
double sqr(const double &v)
{
	return v * v;
}
struct Point
{
	double x, y;
	Point(const double &x = 0, const double &y = 0) : x(x), y(y) {}
	friend ostream &operator<<(ostream &out, const Point &p)
	{
		out << p.x << " " << p.y;
		return out;
	}
	Point operator-(const Point &a)const
	{
		return Point(x - a.x, y - a.y);
	}
	double operator*(const Point &a)const
	{
		return x * a.y - y * a.x;
	}
	double operator^(const Point &a)const
	{
		return x * a.x + y * a.y;
	}
	Point normal()const
	{
		return Point(-y, x);
	}
	double dis()const
	{
		return sqrt(sqr(x) + sqr(y));
	}
	double dis(const Point &a)const
	{
		return (a - *this).dis();
	}
	double dis(const Point &a, const Point &b)const
	{
		Point n = (b - a).normal();
		return abs(((*this - a) ^ n) / n.dis());
	}
}p[maxn], mx[maxn];
Point A(-0.5, 0), B(0, sqrt(3) * 0.5), C(0.5, 0);
double evaluate()
{
	double ans = 1;
	for(int i = 1; i <= n; i ++)
		ans = min(min(ans, p[i].dis(A, B)), min(p[i].dis(B, C), p[i].dis(C, A)));
	for(int i = 1; i <= n; i ++)
		for(int j = i + 1; j <= n; j ++)
			ans = min(ans, p[i].dis(p[j]) / 2);
	return ans * 2;
}
double partialx(const int &now)
{
	p[now].x += delta / 2;
	double tmp = evaluate();
	p[now].x -= delta;
	tmp -= evaluate();
	p[now].x += delta / 2;
	return tmp / delta;
}
double partialy(const int &now)
{
	p[now].y += delta / 2;
	double tmp = evaluate();
	p[now].y -= delta;
	tmp -= evaluate();
	p[now].y += delta / 2;
	return tmp / delta;
}
void descend(const int &now)
{
	p[now].x += c * partialx(now);
	p[now].y += c * partialy(now);
}
bool check(const Point &p)
{
	return (C - A) * (p - A) > 0 && (B - C) * (p - C) > 0 && (A - B) * (p - B) > 0;
}
Point Rand()
{
	Point p(0, 0);
	while(!check(p))
	{
		p.x = (double)rand() / RAND_MAX - 0.5;
		p.y = (double)rand() / RAND_MAX;
	}
	return p;
}
int main()
{
	std::ios::sync_with_stdio(false);
	//srand(time(0));
	srand(85935396);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		p[i] = Rand();
	while((double)clock() < limit)
	{
		int now = rand() % n + 1;
		descend(now);
	}
	cout << "ans : " << evaluate() << endl;
	for(int i = 1; i <= n; i ++)
		cout << p[i] << endl;
	
	return 0;
}

