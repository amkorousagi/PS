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

int dp[100001];
int r(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 3;
	
	if (dp[n] == 0) {
		int a = floor(sqrt(n));
		int m = INT_MAX;
		for (int i = 1; i <= a; i++) {
			m = min(m, 1 + r(n - i * i));
		}
		dp[n] = m;
	}
	return dp[n];
}

int main(void) {
	fastio;
	int n;
	cin >> n;
	cout << r(n);

	return 0;
}