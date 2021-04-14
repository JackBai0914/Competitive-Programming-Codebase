#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<bitset>
#include<cstdio>
#include<string>
#include<time.h>
#include<vector>
#include<cmath>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int N=2e5+5;
long long d[N][3],h[N][3];
bool v[N][3];
int f[N],ne[N<<1],t[N<<1],b,w[N<<1];
priority_queue<pair<long long,pair<int,int> > >q;
void add(int x,int y,int z)
{
    ne[++b]=f[x];
    f[x]=b;
    t[b]=y;
    w[b]=z;
}
void dj()
{
    int x,y;
    memset(d,127,sizeof(d));
    d[1][0]=0;
    q.push(pair<long long,pair<int,int> >(0,pair<int,int>(1,0)));
    while(!q.empty())
    {
        do
        {
            if(q.empty())
                return;
            x=q.top().second.first,y=q.top().second.second;
            q.pop();
        }while(v[x][y]);
        v[x][y]=1;
        for(int i=f[x];i;i=ne[i])
        {
            if(d[t[i]][y]>d[x][y]+w[i])
            {
                d[t[i]][y]=d[x][y]+w[i];
                q.push(pair<long long,pair<int,int> >(-d[t[i]][y],pair<int,int>(t[i],y)));
            }
            if(!y&&d[t[i]][1]>d[x][0])
            {
                d[t[i]][1]=d[x][0];
                q.push(pair<long long,pair<int,int> >(-d[t[i]][1],pair<int,int>(t[i],1)));
            }
            if(!y&&d[t[i]][2]>d[x][0]+w[i])
            {
                d[t[i]][2]=d[x][0]+w[i];
                q.push(pair<long long,pair<int,int> >(-d[t[i]][2],pair<int,int>(t[i],2)));
            }
            if(y==1&&d[t[i]][2]>d[x][1]+(w[i]<<1))
            {
                d[t[i]][2]=d[x][1]+(w[i]<<1);
                q.push(pair<long long,pair<int,int> >(-d[t[i]][2],pair<int,int>(t[i],2)));
            }
        }
    }
}
void rdj()
{
    int x,y;
    memset(v,0,sizeof(v));
    memset(h,127,sizeof(h));
    h[1][0]=0;
    q.push(pair<long long,pair<int,int> >(0,pair<int,int>(1,0)));
    while(!q.empty())
    {
        do
        {
            if(q.empty())
                return;
            x=q.top().second.first,y=q.top().second.second;
            q.pop();
        }while(v[x][y]);
        v[x][y]=1;
        for(int i=f[x];i;i=ne[i])
        {
            if(h[t[i]][y]>h[x][y]+w[i])
            {
                h[t[i]][y]=h[x][y]+w[i];
                q.push(pair<long long,pair<int,int> >(-h[t[i]][y],pair<int,int>(t[i],y)));
            }
            if(!y&&h[t[i]][1]>h[x][0]+(w[i]<<1))
            {
                h[t[i]][1]=h[x][0]+(w[i]<<1);
                q.push(pair<long long,pair<int,int> >(-h[t[i]][1],pair<int,int>(t[i],1)));
            }
            if(!y&&h[t[i]][2]>h[x][0]+w[i])
            {
                h[t[i]][2]=h[x][0]+w[i];
                q.push(pair<long long,pair<int,int> >(-h[t[i]][2],pair<int,int>(t[i],2)));
            }
            if(y==1&&h[t[i]][2]>h[x][1])
            {
                h[t[i]][2]=h[x][1];
                q.push(pair<long long,pair<int,int> >(-h[t[i]][2],pair<int,int>(t[i],2)));
            }
        }
    }
}
int main()
{
    int n,m,u,v,w;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    dj();
    rdj();
    for(int i=2;i<=n;i++)
        printf("%lld ",min(h[i][2],d[i][2]));
}