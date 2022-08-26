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

int main(void) {
	fastio;
	string s;
	cin >> s;
	vector<int> n;
	for (int i = 0; i < s.size(); i++) {
		n.push_back(s[i]-'0');
	}
	sort(n.begin(), n.end(), greater<>());
	for (int i = 0; i < s.size(); i++) {
		cout << n[i];
	}

	return 0;
}