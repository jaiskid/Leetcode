#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class solution {
public:
	vector<TreeNode*>generateTrees(int n) {
		return generateTrees(1, n + 1);
	}
	vector<TreeNode*>generateTrees(int b, int e) {
		if (e - b < 2) return vector<TreeNode*> {e - b ? new TreeNode(b) : NULL};
		vector<TreeNode*> retv;
		for (int i = b; i < e; ++i) {
			vector<TreeNode*> retLeft = generateTrees(b, i);
			vector<TreeNode*> retRight = generateTrees(i + 1, e);
			for (auto pL : retLeft)
				for (auto pR : retRight) {
					TreeNode* root = new TreeNode(i);
					root->left = pL;
					root->right = pR;
					retv.push_back(root);
				}
		}
		return retv;
	}
};
void bfs(TreeNode*root) {
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		TreeNode*f = q.front();
		if (f == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << f->val << " ";
			q.pop();
			if (f->left) {
				q.push(f->left);
			}
			if (f->right) {
				q.push(f->right);
			}
		}

	}
}
int main() {
	int n;
	cin >> n;
	solution s;
	vector<TreeNode*> res = s.generateTrees(n);
	for (int i = 0; i < res.size(); i++) {
		bfs(res[i]);
		cout << endl;
	}

}