#include<bits/stdc++.h>
using namespace std;
bool canSplit(vector<int>& nums, int m, int sum) {
        int cnt = 1;
        long long curr_sum = 0;
        for (const auto& num : nums) {
            //cout<<num<<" ";
            curr_sum += num;
            if (curr_sum > sum) {
                 //cout<<curr_sum<<" ";
                curr_sum = num;

                ++cnt;
            }
        }
        return cnt <= m;
}
int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (const auto& num : nums) {
            if (left < num) left = num;

            right += num;
        }
         //cout<<left<<" ";
         //cout<<right<<"";
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            cout<<canSplit(nums,m,mid);
            if (canSplit(nums, m, mid)) {
                right = mid - 1;

            } else {
                left = mid + 1;
            }
        }
        return left;
}
int main(){   
int n;
cin>>n;
vector<int> nums;
while(n--){
    int data;
    cin>>data;
    nums.push_back(data);
}
int m;
cin>>m;
cout<<splitArray(nums,m);
}
