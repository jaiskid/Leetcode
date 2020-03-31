#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
	void push(int Number) {
		if (element_.empty()) {
			element_.emplace(0);
			stack_min_ = Number;
		} else {
			element_.emplace(static_cast<int64_t>(Number) - stack_min_);
			if (Number < stack_min_) {
				stack_min_ = Number; //update min

			}
		}
	}
	void pop() {
		auto diff = element_.top();
		element_.pop();
		if (diff < 0)
			stack_min_ -= diff; //restore previous min
	}
	int top() {
		if (element_.top() > 0) {
			return stack_min_ + element_.top();
		} else {
			return stack_min_;
		}
	}
	int getmin() {
		return stack_min_;
	}
private:
	stack<int64_t> element_;
	int stack_min_;
};
int main() {
	MinStack m;
	m.push(5);
	m.push(4);
	cout << m.top();
}