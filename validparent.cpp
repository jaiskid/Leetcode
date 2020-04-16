class Solution {
public:
    bool checkValidString(string s) {
        int lower=0;
        int upper=0;
        for(const auto &c: s){
            lower+=(c=='(') ? 1 : -1;
            upper-=(c==')') ? 1 : -1;
            if(upper<0) break;
            lower =max(lower,0);
        }
        return lower==0;
    }
};