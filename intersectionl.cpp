#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
void intail(ListNode*&head, int data) {
	if (head == NULL) {
		head = new ListNode(data);
		return;
	}
	ListNode*tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}

	tail->next = new ListNode(data);
	return;
}
void buildlist(ListNode*&head) {
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		intail(head, data);
	}
}
void print(ListNode*n) {
	while (n != NULL) {
		cout << n->val << " ";
		n = n->next;
	}
}
ListNode* intersection(ListNode*headA, ListNode*headB) {
	ListNode*curA = headA, *curB = headB;
	ListNode*begin = NULL, *tailA = NULL, *tailB = NULL;
	while (curA and curB) {
		if (curA == curB) {
			begin = curA;
			break;
		}
		if (curA->next) {
			curA = curA->next;
		} else if (!tailA) {
			tailA = curA;
			curA = headB;
		} else {
			break;
		}
		if (curB->next) {
			curB = curB->next;
		}
		else if (!tailB) {
			tailB = curB;
			curB = headA;
		} else {
			break;
		}
	}
	return begin;
}
int main() {
	ListNode*n1 = NULL;
	buildlist(n1);
	ListNode*n2 = NULL;
	buildlist(n2);
	cout << endl;
	ListNode *result = intersection(n1, n2);
	cout << result->val;
}