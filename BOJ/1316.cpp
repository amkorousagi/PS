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
	int n;
	cin >> n;
	string s[100];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int ch[27];
		memset(ch, -1, sizeof(int) * 27);
		bool g = true;
		for (int j = 0; j < s[i].size();j++) {
			if (ch[s[i][j] - 'a'] == -1) {
				ch[s[i][j] - 'a'] = j;
			}
			else if (j - ch[s[i][j] - 'a'] > 1) {
				g = false;
				break;
			}
			else {
				ch[s[i][j] - 'a'] = j;
			}
		}

		if (g) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}