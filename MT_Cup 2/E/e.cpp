#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define pli pair<LL,int>
#define mp make_pair
#define pb push_back
#define nd second
#define ds first
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
#define M 2020200
LL ans=1,sum[26];
int n;
char ch[M];
namespace SAM{
	int len[M],fa[M],t[M][26];
	int now,cnt,ed,kd[M];
	void init(){cnt=ed=1,now=0;}
	inline void upd(int x){sum[kd[x]]+=len[x]-len[fa[x]];}
	inline void dec(int x){sum[kd[x]]-=len[x]-len[fa[x]];}
	void ins(int c){
		int x=ed; len[ed=++cnt]=++now,kd[ed]=c;
		while(x&&!t[x][c]) t[x][c]=ed,x=fa[x];
		if(!x){fa[ed]=1;upd(ed);return;} int y=t[x][c];
		if(len[y]==len[x]+1){fa[ed]=y;upd(ed);return;}
		len[++cnt]=len[x]+1,kd[cnt]=c,dec(y);
		fa[cnt]=fa[y],fa[y]=fa[ed]=cnt,upd(cnt),upd(y),upd(ed);
		memcpy(t[cnt],t[y],sizeof(t[y]));
		while(x&&t[x][c]==y) t[x][c]=cnt,x=fa[x];
	}
}
int main(){
	scanf("%s",ch+1),n=strlen(ch+1); SAM::init();
	for(int i=n;i>=1;--i){
		SAM::ins(ch[i]-'a'),ans++;
		for(int k=0;k<26;k++) if(k!=ch[i]-'a') ans+=sum[k];
	}
	printf("%lld\n",ans);
	return 0;
}