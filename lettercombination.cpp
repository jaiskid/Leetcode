vector <string> letterCombinations (string digits) {
unordered_map<char,string> dict{
	{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
};
int total=digits.size()==0?0:1;
for(auto s:digits)
total*=dict[s].size();
vector<string> result(total);
for(int i=0;i<total;i++){
	int temp=i;
	for(int j=0;j<digits.size();j++){
	int cur=dict[digits[j]].size();
	 result[i].push_back(dict[digits[j]][tmp % cur]);
                tmp /= cur;
	}
}
return result;
}