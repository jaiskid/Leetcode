include < bits / stdc++.h >
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> sn;
    for (auto s : tokens) {
        if (s.size() > 1 || isdigit(s[0]))
            sn.push(stoi(s));
        else {
            auto x2 = sn.top(); sn.pop();
            auto x1 = sn.top(); sn.pop();
            switch (s[0]) {
            case '+': x1 += x2; break;
            case '-': x1 -= x2; break;
            case '*': x1 *= x2; break;
            case '/': x1 /= x2; break;
            }
            sn.push(x1);
        }
    }
    return sn.top();
}
int main() {
    int n;
    cin >> n;
    vector<int> string;
    string.resize(n);
    for (int i = 0; i < n; i++)
        cin >> string[i];
    cout << evalRPN(string);
}