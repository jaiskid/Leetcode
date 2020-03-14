#include<bits/stdc++.h>
using namespace std;
 void dfs(const vector<int> &num, vector<vector<int>> &ret, int target, vector<int> cur, size_t start) {
        if (target == 0) { ret.push_back(cur); return; }
        for (auto i = start; i < num.size(); ++i)
            if (i > start && num[i] == num[i-1]) continue;
            else if (num.at(i) <= target) {
                cur.push_back(num.at(i));
                dfs(num, ret, target - num.at(i), cur, i+1);
                cur.pop_back();
            } else break;
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> ret;
        std::sort(num.begin(), num.end());
        dfs(num, ret, target, vector<int>{}, 0);
        return ret;
    }
int main(){
	int n;cin>>n;
	vector<int> nums;

	while(n--){
		int data;
		cin>>data;
		nums.push_back(data);
	}
	int target;
	cin>>target;
	vector<vector<int>> res;
	res=combinationSum2(nums,target);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}