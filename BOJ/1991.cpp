#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));

using namespace std;
pair<int, int> dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };

typedef struct node {
	char val;
	struct node* leftc;
	struct node* rightc;
} node;

node* nodes[26];

void preorder(node* n) {
	if (n == NULL) {
		return;
	}
	cout << n->val;
	preorder(n->leftc);
	preorder(n->rightc);
}
void inorder(node* n) {
	if (n == NULL) {
		return;
	}
	inorder(n->leftc);
	cout << n->val;
	inorder(n->rightc);
}
void postorder(node* n) {
	if (n == NULL) {
		return;
	}
	postorder(n->leftc);
	postorder(n->rightc);
	cout << n->val;
}

int main() {
	fastio;
	int n;
	cin >> n;

	char c1, c2, c3;
	for (int i = 0; i < n; i++) {
		cin >> c1 >> c2 >> c3;
		if (c2!='.' && nodes[c2 - 'A'] == NULL) {
			nodes[c2 - 'A'] = new node;
			nodes[c2 - 'A']->val = c2;
			nodes[c2 - 'A']->leftc = NULL;
			nodes[c2 - 'A']->rightc = NULL;
		}
		if (c3!='.' && nodes[c3 - 'A'] == NULL) {
			nodes[c3 - 'A'] = new node;
			nodes[c3 - 'A']->val = c3;
			nodes[c3 - 'A']->leftc = NULL;
			nodes[c3 - 'A']->rightc = NULL;
		}

		if (nodes[c1 - 'A'] == NULL) {
			nodes[c1 - 'A'] = new node;
			nodes[c1 - 'A']->val = c1;
			if (c2 != '.')
				nodes[c1 - 'A']->leftc = nodes[c2 - 'A'];
			if (c3 != '.')
				nodes[c1 - 'A']->rightc = nodes[c3 - 'A'];
		}
		else {
			if(c2!='.')
				nodes[c1 - 'A']->leftc = nodes[c2 - 'A'];
			if(c3!='.')
				nodes[c1 - 'A']->rightc = nodes[c3 - 'A'];
		}
	}
	node* root = nodes[0];
	preorder(root); cout << endl;
	inorder(root); cout << endl;
	postorder(root); cout << endl;

	return 0;
}