#include<iostream>
using namespace std;
double myPow(double x,int n){
	if(n<0 and n!=-n){
	return 1.0/myPow(x,n);
	}
	if(n==0){
	return 1;
	}
	double v=myPow(x,n/2);
	if(n%2==0){
	return v*v;
	}
	else{
	return v*v*x;
	}
}
int main(){
	double x,n;
	cin>>x>>n;
	cout<<myPow(x,n);

}