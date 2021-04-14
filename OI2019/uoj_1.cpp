#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	cout<<n/2<<endl;
	for(int t=1;t+1<=n;t+=2){
		int x=t,y=t+1;
		for(int i=1;i<=n;i++) {
			if(i<x&&(x-i)%2||i>x&&!((x-i)%2))
				cout<<x<<" "<<i<<" ";
			if(i<y&&(y-i)%2||i>y&&!((y-i)%2))
				cout<<y<<" "<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}