#include<bits/stdc++.h>
using namespace std;
void remove(char *s){
    int n;
    n=strlen(s);
    int k=0;
    char prev='\0';
    //loop through the string
    for(int i=0;i<n;i++){
        //if current char is different than the previous char
    if(prev!=s[i])
        //set distinct char at index k and increment it
    s[k++]=s[i];
        // update previous char to current char for next iteration of loop
    prev=s[i];
    }
    //null terminate the resultant string 
    s[k]='\0';
} 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char s[1005];
        cin>>s;
        remove(s);
        cout<<s;
        int x=0,y=0;
        for(int i=0;s[i]!='\0';i++){
            char ch=s[i];
            if(ch=='L'){
                x=x-1;
            }
            if(ch=='R'){
                x=x+1;
            }
            if(ch=='U'){
                y=y+1;
            }
            if(ch=='D'){
                y=y-1;
            }
        }
        cout<<x<<" "<<y<<endl;
    }
}