/**
 * @template file author kadrick (kbk2581553@gmail.com)
 *
 * author:amkorousagi (hasmi5452@gmail.com)
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'
typedef struct node {
	char c;
	struct node* l;
	struct node* r;
} node;
string s;
int main(void) {
	fastio;
	cin >> s;
	node* prior = NULL;
	for (int i = 0; i < s.size(); i++) {
		node* temp = (node*)malloc(sizeof(node));
		temp->c = s[i];
		if (prior == NULL) {
			temp->l = NULL;
			temp->r = NULL;
		}
		else {
			temp->l = prior;
			temp->r = NULL;
			prior->r = temp;
		}
		prior = temp;
	}
	node* cursor = prior;
	bool r = true;
	int m;
	char c;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (c == 'P') {
			cin >> c;
			node* temp = (node*)malloc(sizeof(node));
			temp->c = c;

			if (cursor == NULL) {
				cursor = temp;
				r = true;
			}
			else if (r) {
				if (cursor->r == NULL) {
					temp->r = NULL;
					temp->l = cursor;
					cursor->r = temp;

					cursor = cursor->r;
				}
				else {
					cursor->r->l = temp;
					temp->r = cursor->r;
					temp->l = cursor;
					cursor->r = temp;

					cursor = cursor->r;
				}
			}
			else {
				if (cursor->l == NULL) {
					temp->l = NULL;
					temp->r = cursor;
					cursor->l = temp;

				}
				else {
					cursor->l->r = temp;
					temp->l = cursor->l;
					temp->r = cursor;
					cursor->l = temp;

				}
			}
		}
		else if (c == 'L') {
			if (cursor == NULL) continue;

			if (r) r = false;
			else {
				if (cursor->l == NULL) {
					continue;
				}
				else {
					cursor = cursor->l;
				}
			}
		}
		else if (c == 'D') {
			if (cursor == NULL) continue;

			if (!r) r = true;
			else {
				if (cursor->r == NULL) {
					continue;
				}
				else {
					cursor = cursor->r;
				}
			}
		}
		else if (c == 'B') {
			if (cursor == NULL) continue;

			if (!r) {
				if (cursor->l == NULL) {
					continue;
				}
				else {
					node* t = cursor->l;
					cursor->l = cursor->l->l;
					if (cursor->l != NULL) cursor->l->r = cursor;
					free(t);
				}
			}
			else {
				node* t = cursor;
				if (cursor->l == NULL) {
					if (cursor->r == NULL) {
						cursor = NULL;
						free(t);
					}
					else {
						r = false;
						cursor = cursor->r;
						cursor->l = NULL;
						free(t);
					}
				}
				else {
					if (cursor->r == NULL) {
						cursor = cursor->l;
						cursor->r = NULL;
						free(t);
					}
					else {
						cursor = cursor->l;
						cursor->r = t->r;
						t->r->l = cursor;
						free(t);
					}
				}
			}
		}
	}
	node* head = cursor;
	for (;;) {
		if (head->l == NULL) {
			break;
		}
		head = head->l;
	}

	for (;;) {
		if (head == NULL) {
			break;
		}
		cout << head->c;
		head = head->r;
	}

	return 0;
}