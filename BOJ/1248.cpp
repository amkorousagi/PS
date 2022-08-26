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
int n;
vector<vector<char>> m;
vector<int> se;
bool f = false;
bool sati(int end) {
	int sum;
	for (int i = 0; i < end; i++) {
		sum = 0;
		for (int j = i; j < end; j++) {
			sum += se[j];
			if (sum == 0 && m[i][j] != '0') return false;
			if (sum > 0 && m[i][j] != '+') return false;
			if (sum < 0 && m[i][j] != '-') return false;
		}
	}
	return true;
}
void dfs(int start) {
	if (sati(start) == false) return;
	if (sati(start) && start == n) {
		f = true;
		return;
	}
	
	if (m[start][start] == '0') {
		se[start] = 0;
		dfs(start + 1);
	}
	else if (m[start][start] == '+') {
		for (int i = 1; i <= 10; i++) {
			se[start] = i;
			dfs(start + 1);
			if (f) return;
		}
	}
	else {
		for (int i = 1; i <= 10; i++) {
			se[start] = i*(-1);
			dfs(start + 1);
			if (f) return;
		}
	}
}

int main(void) {
	fastio;
	cin >> n;
	m.assign(n, vector<char>(n));
	se.assign(n, 0);
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			m[i][j] = s[cnt];
			cnt++;
		}
	}
	dfs(0);

	for (int i = 0; i < n; i++) {
		cout << se[i];
		if (i + 1 != n) {
			cout << " ";
		}
	}


	return 0;
}