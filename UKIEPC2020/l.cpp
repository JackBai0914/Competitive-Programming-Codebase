#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1 << 20;
const double PI=acos(-1);

struct cp
{
    double re,im;
    cp(double _re=0.0,double _im=0.0) { re=_re; im=_im; }
    cp operator+(const cp& b) const { return cp(re+b.re,im+b.im); }
    cp operator-(const cp& b) const { return cp(re-b.re,im-b.im); }
    cp operator*(const cp& b) const { return cp(re*b.re-im*b.im,re*b.im+im*b.re); }
} a[N],a2[N],a3[N],b[N],b2[N],b3[N],c1[N],c2[N],c3[N];

void fft(cp* A,int type);

int n,m,lim,L,r[N];
int s[N],t[N];
vector<int> ans;

int main()
{
    int i;

    cin >> n >> m;

    string x; int y;
    for (i=0;i<n;++i) {
			cin >> x;
			if (x == "?")
				t[i] = 0;
			else {
				if (x == "n")	t[i] = 1;
				if (x == "s")	t[i] = 2;
				if (x == "e")	t[i] = 3;
				if (x == "w")	t[i] = 4;
				cin >> y;
				t[i] += 4 * y;
			}
		}
	for (i=0;i<m;++i) {
		cin >> x;
		if (x == "?")
			s[i] = 0;
		else {
			if (x == "n")	s[i] = 1;
			if (x == "s")	s[i] = 2;
			if (x == "e")	s[i] = 3;
			if (x == "w")	s[i] = 4;
			cin >> y;
			s[i] += 4 * y;
		}
	}

    for (i=0;i<n;++i)
    {
        if (m-i>0&&s[m-i-1]!=0)
        {
            a[i].re=s[m-i-1];
            a2[i].re=a[i].re*a[i].re;
            a3[i].re=a[i].re*a2[i].re;
        }
        if (t[i]!=0)
        {
            b[i].re=t[i];
            b2[i].re=b[i].re*b[i].re;
            b3[i].re=b[i].re*b2[i].re;
        }
    }

    for (lim=0,L=1;L<=n;++lim,L<<=1);
    for (i=1;i<L;++i) r[i]=(r[i>>1]>>1)|((i&1)<<(lim-1));

    fft(a,1);
    fft(a2,1);
    fft(a3,1);
    fft(b,1);
    fft(b2,1);
    fft(b3,1);

    for (i=0;i<L;++i)
    {
        c1[i]=a[i]*b3[i];
        c2[i]=a2[i]*b2[i];
        c3[i]=a3[i]*b[i];
    }

    fft(c1,-1);
    fft(c2,-1);
    fft(c3,-1);


    for (i=m-1;i<n;++i)
    {
        if (c1[i].re-2*c2[i].re+c3[i].re<0.5)
        {
            ans.push_back(i-m+2);
        }
    }

    printf("%d\n",int(ans.size()));
    // for (i=0;i<ans.size();++i) printf("%d ",ans[i]);

    return 0;
}

void fft(cp* A,int type)
{
    int i,j,k;
    for (i=1;i<L;++i) if (i<r[i]) swap(A[i],A[r[i]]);
    for (i=1;i<L;i<<=1)
    {
        cp w1(cos(PI/i),type*sin(PI/i));
        for (j=0;j<L;j+=2*i)
        {
            cp w(1,0);
            for (k=j;k<i+j;++k,w=w*w1)
            {
                cp t=A[k+i]*w;
                A[k+i]=A[k]-t;
                A[k]=A[k]+t;
            }
        }
    }
    if (type==-1) for (i=0;i<L;++i) A[i].re=A[i].re/L;
}
