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
int l, c;
vector<char> cc;
deque<char> s;
void p(int start,int len) {
	if (len == l) {
		int a = 0;
		for (int i = 0; i < l; i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				a++;
			}
		}
		if (a >= 1 && l - a >= 2) {
			for (int i = 0; i < s.size(); i++) {
				cout << s[i];
			}
			cout << endl;
		}
		return;
	}

	for (int i = start; i < c; i++) {
		s.push_back(cc[i]);
		p(i + 1, len + 1);
		s.pop_back();
	}

}

int main(void) {
	fastio;
	cin >> l >> c;
	cc.assign(c,0);
	for (int i = 0; i < c; i++) {
		cin >> cc[i];
	}
	sort(cc.begin(), cc.end());
	p(0, 0);

	return 0;
}