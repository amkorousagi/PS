#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

int dp[10001];
int main() {
	fastio;
	int t, k;
	cin >> t >> k;
	vector<pair<int, int>> coin;

	int p, n;
	for (int i = 0; i < k; i++) {
		cin >> p >> n;
		coin.push_back({ p,n });
	}

	dp[0] = 1;
	for (int kk = 0; kk < k; kk++) {
		int value = coin[kk].first;
		int count = coin[kk].second;

		for (int tt = t; tt >= 0; tt--) {
			for (int c = 1; c <= count; c++) {
				if (tt - c * value < 0) {
					break;
				}
				dp[tt] += dp[tt - c * value];
			}
		}
	}
	cout << dp[t];

	return 0;
}