#include<bits/stdc++.h>
using namespace std;
const int N=6e5+1;
bool v[N];
int T,n,m,a[N],b[N],A[N],t;
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--&&cin>>n>>m)
	{
		for(int i=1;i<=m;i++)
			cin>>a[i]>>b[i];
		for(int i=1;i<=3*n;i++)
			v[i]=false;
		t=0;
		for(int i=1;i<=m;i++)
			if(!v[a[i]]&&!v[b[i]])
				v[a[i]]=v[b[i]]=true,A[++t]=i;
		if(t>=n)
		{
			cout<<"Matching"<<'\n';
			for(int i=1;i<=n;i++)
				cout<<A[i]<<" ";
			cout<<'\n';
			continue;
		}
		t=0;
		for(int i=1;i<=3*n;i++)
			if(!v[i])
				A[++t]=i;
		cout<<"IndSet"<<'\n';
		for(int i=1;i<=n;i++)
			cout<<A[i]<<" ";
		cout<<'\n';
	}
	return 0;
}