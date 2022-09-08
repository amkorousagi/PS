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

char c[51][51];
int n;
int sweet() {
	int max = -1;
	for (int i = 0; i < n;i++) {
		int cnt = 1;
		for (int j = 0; j +1 < n; j++) {
			if (c[i][j] == c[i][j + 1]) {
				cnt++;
			}
			else {
				if (max < cnt) {
					max = cnt;
				}
				cnt = 1;
			}
		}
		if (max < cnt) {
			max = cnt;
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j + 1 < n; j++) {
			if (c[j][i] == c[j + 1][i]) {
				cnt++;
			}
			else {
				if (max < cnt) {
					max = cnt;
				}
				cnt = 1;
			}
		}
		if (max < cnt) {
			max = cnt;
		}
	}
	return max;
}

int main(void) {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			c[i][j] = s[j];
		}
	}
	int max = -1;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i - 1 >= 0 && c[i-1][j]!=c[i][j]) {
				temp = c[i][j];
				c[i][j] = c[i - 1][j];
				c[i - 1][j] = temp;

				temp = sweet();
				if (temp > max) {
					max = temp;
				}

				temp = c[i][j];
				c[i][j] = c[i - 1][j];
				c[i - 1][j] = temp;
				
			}
			if (i + 1 < n && c[i + 1][j] != c[i][j]) {
				temp = c[i][j];
				c[i][j] = c[i + 1][j];
				c[i + 1][j] = temp;

				temp = sweet();
				if (temp > max) {
					max = temp;
				}

				temp = c[i][j];
				c[i][j] = c[i + 1][j];
				c[i + 1][j] = temp;
			}
			if (j - 1 >= 0 && c[i][j-1] != c[i][j]) {
				temp = c[i][j];
				c[i][j] = c[i][j-1];
				c[i][j-1] = temp;

				temp = sweet();
				if (temp > max) {
					max = temp;
				}

				temp = c[i][j];
				c[i][j] = c[i][j-1];
				c[i][j-1] = temp;
			}
			if (j + 1 < n && c[i][j+1] != c[i][j]) {
				temp = c[i][j];
				c[i][j] = c[i][j+1];
				c[i][j+1] = temp;

				temp = sweet();
				if (temp > max) {
					max = temp;
				}

				temp = c[i][j];
				c[i][j] = c[i][j + 1];
				c[i][j + 1] = temp;
			}
		}
	}
	cout << max;
	return 0;
}