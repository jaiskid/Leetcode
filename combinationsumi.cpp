#include<bits/stdc++.h>
using namespace std;
void  dfs ( const vector < int > & cdds, int target, vector < int > curr, size_t index, vector <vector < int >> & ret) {
        if (target==0) {ret. push_back (curr); return ;}
        for ( auto i = index ; i <cdds. size (); ++ i)
            if (cdds [i] <= target) {
                curr. push_back (cdds [i]);
                dfs (cdds, target-cdds [i], curr, i, ret);
                curr. pop_back ();
            } else  break ;
    }
vector <vector < int >> combinationSum (vector < int > & candidates, int target) {
        vector <vector < int >> ret;
        sort (candidates. begin (), candidates. end ());
        dfs (candidates, target,vector<int>{}, 0 , ret);
        return ret;   
    }
    
int main(){
	int n;
	cin>>n;
	vector<int> candidate;
	while(n--){
	int data;
	cin>>data;
	candidate.push_back(data);
	}
	int target;
	cin>>target;
	vector<vector<int>> ret;
	ret=combinationSum(candidate,target);
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[i].size();j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}
}