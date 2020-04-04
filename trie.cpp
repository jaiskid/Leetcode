#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char,node*>
class node {
public:
	char data;
	hashmap h;
	bool isterminal;
	node(char d) {
		data = d;
		isterminal = false;
	}
};
class trie {
	node* root;
public:
	trie() {
		root = new node('\0');
	}

	void addwords(char* word) {
		//this means temp have null node
		node *temp = root;
		for (int i = 0; word[i] != '\0'; i++) {
			char ch = word[i];
			if (temp->h.count(ch) == 0) {
				node* child = new node(ch);
				//this is initial point of this game
				temp->h[ch] = child;
				temp = child;
			}
			else {
				temp = temp->h[ch];
			}
			temp->isterminal = true;
		}
	}
	bool search(char *word) {
		node* temp = root;
		for (int i = 0; word[i] != '\0'; i++) {
			char ch = word[i];
			if (temp->h.count(ch)) {
				temp = temp->h[ch];
			}
			else {
				return false;
			}
			cout << temp->data << " ";
		}
		return temp->isterminal;
	}
};
int main() {
	char word[10][100] = {"apple", "ape", "coder", "coding blocks", "no"};
	trie t;
	for (int i = 0; i < 5; i++) {
		t.addwords(word[i]);
	}
	char search_[100];
	cin.getline(search_, 100);
	cout << endl;
	if (t.search(search_)) {
		cout << endl;
		cout << search_ << endl;
		cout << "found" << endl;
	} else {
		cout << "Not found !" << endl;
	}
}