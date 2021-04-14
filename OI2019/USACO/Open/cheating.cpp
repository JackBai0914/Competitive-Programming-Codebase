#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

const int N=111;
const int M=1111;

typedef long long LL;

struct Edges
{
    int a,b,c;
    bool operator<(const Edges & x)const
    {
        return c<x.c;
    }
} edge[M];

int n,m;
int mod;
LL f[N],U[N],vist[N];
LL G[N][N],C[N][N];

vector<int>V[N];

int Find(int x,LL f[])
{
    if(x==f[x])
        return x;
    else
        return Find(f[x],f);
}

LL det(LL a[][N],int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j]%=mod;
    int ret=1;
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
            while(a[j][i])
            {
                int t=a[i][i]/a[j][i];
                for(int k=i; k<n; k++)
                    a[i][k]=(a[i][k]-a[j][k]*t)%mod;
                for(int k=i; k<n; k++)
                    swap(a[i][k],a[j][k]);
                ret=-ret;
            }
        if(a[i][i]==0)
            return 0;
        ret=ret*a[i][i]%mod;
    }
    return (ret+mod)%mod;
}

void Solve()
{
    sort(edge,edge+m);
    for(int i=1; i<=n; i++)
    {
        f[i]=i;
        vist[i]=0;
    }

    LL Edge=-1;
    LL ans=1;
    for(int k=0; k<=m; k++)
    {
        if(edge[k].c!=Edge||k==m)
        {
            for(int i=1; i<=n; i++)
            {
                if(vist[i])
                {
                    LL u=Find(i,U);
                    V[u].push_back(i);
                    vist[i]=0;
                }
            }
            for(int i=1; i<=n; i++)
            {
                if(V[i].size()>1)
                {
                    for(int a=1; a<=n; a++)
                        for(int b=1; b<=n; b++)
                            C[a][b]=0;
                    int len=V[i].size();
                    for(int a=0; a<len; a++)
                        for(int b=a+1; b<len; b++)
                        {
                            int a1=V[i][a];
                            int b1=V[i][b];
                            C[a][b]=(C[b][a]-=G[a1][b1]);
                            C[a][a]+=G[a1][b1];
                            C[b][b]+=G[a1][b1];
                        }
                    LL ret=(LL)det(C,len);
                    ans=(ans*ret)%mod;
                    for(int a=0; a<len; a++)
                        f[V[i][a]]=i;
                }
            }
            for(int i=1; i<=n; i++)
            {
                U[i]=f[i]=Find(i,f);
                V[i].clear();
            }
            if(k==m)
                break;
            Edge=edge[k].c;
        }

        int a=edge[k].a;
        int b=edge[k].b;
        int a1=Find(a,f);
        int b1=Find(b,f);
        if(a1==b1)
            continue;
        vist[a1]=vist[b1]=1;
        U[Find(a1,U)]=Find(b1,U);
        G[a1][b1]++;
        G[b1][a1]++;
    }

    int flag=0;
    for(int i=2; i<=n&&!flag; i++)
        if(U[i]!=U[i-1])
            flag=1;
    if(m==0)
        flag=1;
    
    cout << (flag?0:ans%mod) << endl;
    cerr << (flag?0:ans%mod) << endl;

}
int r,c;
int id(int x,int y)
{
    return (x-1)*c+y;
}
int main()
{
    scanf("%d %d",&r,&c);
    n=r*c;
    for(int i=1; i<=r; i++)
        for(int w,j=1; j<c; j++)
        {
            scanf("%d",&w);
            edge[m].a=id(i,j),edge[m].b=id(i,j+1),edge[m].c=w;
            m++;
        }
    for(int i=1; i<=c;i++)
        for(int w,j=1; j<r;j++)
        {
            scanf("%d",&w);
            edge[m].a=id(j,i),edge[m].b=id(j+1,i),edge[m].c=w;
            m++;
        }
    mod=1e9+7;
    Solve();
    return 0;
}
