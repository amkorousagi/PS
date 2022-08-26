#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int N, T;
int k[101], s[101];
int dp[10001];
int main(void) {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> k[i] >> s[i];
	}
	for (int i = 0; i < N; i++) {
		for (int t = T; t >= 1; t--) {
			if(k[i]<=t)
				dp[t] = max(dp[t - k[i]] + s[i],dp[t]);
		}
	}
	cout << dp[T];

	return 0;
}