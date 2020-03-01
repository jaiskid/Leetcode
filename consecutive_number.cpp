#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	int ans=0;
	for(int n=2;n*(n+1)/2<=N;++n){
		if((N-n*(n+1)/2)%n==0)
			ans++;
	}
	cout<<ans+1;
}

