#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;
string s1, s2;
int cnt;
int recursive(int cursor1, int cursor2) { 
	int len = 0;
	
	for (int i = cursor1; i < s1.size(); i++) {
		for (int j = cursor2; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				cnt++;
				len = max(len, 1 + recursive(i + 1, j + 1));
			}
		}
	}
	return len;
}

int dp[1001][1001];
int memoization(int cursor1, int cursor2) {
	if (dp[cursor1][cursor2] != -1) {
		//cout << "dp" << dp[cursor1][cursor2] << endl;
		return dp[cursor1][cursor2];
	}
	int len = 0;

	for (int i = cursor1; i < s1.size(); i++) {
		for (int j = cursor2; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				//cout << i << j << endl;
				cnt++;
				len = max(len, 1 + memoization(i + 1, j + 1));
			}
		}
	}
	dp[cursor1][cursor2] = len;
	return len;
}

int table[1001][1001];
int lcs() {
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i-1] == s2[j-1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else {
				table[i][j] = max(table[i][j - 1], table[i - 1][j]);
			}
		}
	}
	return table[s1.size()][s2.size()];
}

int main() {
	fastio;
	cin >> s1;
	cin >> s2;
	memset(dp, -1, sizeof(dp));

	//cout<<recursive(0, 0);
	//cout<<memoization(0,0);
	cout << lcs();
	return 0;
}