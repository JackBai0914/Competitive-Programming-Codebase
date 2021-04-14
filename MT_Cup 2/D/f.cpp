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
#define M 2000200
namespace small{
	int n,p[M];
	inline void solve(){
		n=read();
		for(int i=1;i<=n;i++) p[i]=read();
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(p[i]>p[j])
			ans+=i^j;
		printf("%d\n",ans);
	}
}
namespace large{
	int org[]=
	{
		293309062,96701749,
		694916487,371591203,
		450903345,936470975,
		360036365,596019536,
		362870120,978299587,
		72615453,677215478,
		297218049,296795024,
		703206614,117310233,
		243106488,303113802,
		602459530,151925105,
		47183452,590812021,
		886995042,967943647,
		1040249104,802320701,
		554202194,839697519,
		607415572,770010993,
	};
	int w[M];
	int tar[40]={
		232264754,
		770111598,
		1053074562,
		930396495,
		250378505,
		1067932760,
		753807877,
		658212573,
		779218342,
		817055948,
		807199440,
		901566674,
		366155524,
		95731966,
		154015196,
		947651218,
		927919164,
		968332050,
		589611574,
		460292431,
		567369613,
		290023552,
		117666292,
		639404739,
		982055747,
		931465428,
		561895083,
		569911183,
		1039691054,
		680154692,
		495521764,
		1060493563,
		145432758,
		1048859616,
		543925510,
		768894444,
		996361644,
		561203497,
		328769214,
		645778173
	};
	int n,in[M],p[20],dt[20],my[M];
	int calc(int lev,int x){
		if(x==0) return x;
		if(x&1) return calc(lev+1,x>>1)^w[lev];
		return calc(lev+1,x>>1);
	}
	inline int trans(int x,int res=0){
		for(int i=0;i<12;i++) dt[i]=x%10,x/=10;
		for(int i=11;i>=0;i--) res*=10,res+=p[dt[i]];
		return res;
	}
	inline void dfs(){
		p[0]=0,p[1]=1;
		for(int i=2;i<=9;i++) p[i]=i;
		n=read();
		for(int i=0;i<n;i++) in[i]=read();
		bool ok;
		do{
			ok=true;
			for(int i=0;i<30;i++) w[i]=trans(org[i]);
			for(int i=0;i<n;i++) my[i]=calc(0,in[i]);
			for(int i=0;i<n;i++) ok&=(my[i]==tar[i]);
			if(ok) break;
		}while(next_permutation(p+2,p+10));
		debug(ok)el;
		for(int i=2;i<=9;i++) debug(i)sp,debug(p[i])el;
		fgx;
	}
	inline void solve(){
		n=read();
		for(int i=0;i<30;i++) w[i]=org[i];
		for(int i=0;i<n;i++){
			int x=read();
			printf("%d\n",calc(0,x));
		}
	}
}
int main(){
	int op=read();
	if(op==1) small::solve();
	if(op==2) large::solve();
	// large::dfs();
	return 0;
}