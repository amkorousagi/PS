#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));

using namespace std;
pair<int, int> dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };

typedef struct node {
	char val;
	struct node* prior;
	struct node* next;
} node;

bool leftest;
node* root;
node* current;
void left(){
	if (current == NULL) {
		return;
	}else if (current->prior != NULL) {
		current = current->prior;
	}
	else {
		leftest = true;
	}
}
void right(){
	if (leftest) {
		leftest = false;
		return;
	}
	else if (current == NULL) {
		return;
	}
	else if (current->next != NULL) {
		current = current->next;
	}
}
void del(){
	if (leftest) {
		return;
	}
	else if (current == NULL) {
		return;
	}
	else {
		if (current->prior == NULL && current->next == NULL) {
			delete current;

			current = NULL;
			root = NULL;
		}
		else if (current->prior != NULL && current->next != NULL) {
			current->prior->next = current->next; //1
			current->next->prior = current->prior; //2

			node* t = current->prior;
			delete current;
			current = t;
		}
		else if (current->prior != NULL && current->next == NULL) {
			node* t = current->prior;
			delete current;

			t->next = NULL; //1
			current = t;
		}
		else if (current->prior == NULL && current->next != NULL) {
			node* t = current->next;
			delete current;
			root = t;
			current = t;
			t->prior = NULL; //2
			leftest = true;
		}
	}
}
void insert(char c){
	if (leftest) {
		node* t = new node;
		t->val = c;
		t->prior = NULL;

		t->next = root;
		root->prior = t; // root 가 null 이라면?
		
		root = t;
		current = t;
		leftest = false;
		return;
	}
	if (current == NULL) {
		node* t = new node;
		t->val = c;
		t->prior = NULL;
		t->next = NULL;

		current = t;
		root = t;
	} else {
		node* t = new node;
		t->val = c;
		t->prior = current;
		t->next = current->next;
		if (current->next == NULL) {
			current->next = t;
			current = t;
		}
		else {
			current->next->prior = t;
			current->next = t;
			current = t;
		}
	}
}

void print() {
	node* t = root;
	while (t != NULL) {
		cout << t->val;
		t = t->next;
	}
	cout << endl;
}
int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		root = NULL;
		current = NULL;
		leftest = false;
		for (char c : s) {
			//cout << c << endl;
			if (c == '<') {
				left();
			}
			else if (c == '>') {
				right();
			}
			else if (c == '-') {
				del();
			}
			else {
				insert(c);
			}
		}
		print();
	}

	return 0;
}
