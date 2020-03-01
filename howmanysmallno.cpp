//time o(n^2) bruteforce solution space o(1);
#include <iostream>
using namespace std;
int count[100005];
void greatest(int *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]>arr[j]){
                count[i]++;
            }
        }
    }
    for(int i=0;i<n;i++)
    cout<<count[i]<<" ";
}
int main() {
  int n;
  cin>>n;
  int arr[10005];
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
  }
  greatest(arr,n);
} 
