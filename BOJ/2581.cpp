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
	int m, n;
	cin >> m >> n;

	vector<bool> isPrime(n+1, true);

	isPrime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}

	int sum = 0;
	int mmin = -1;
	for (int i = m; i <= n; i++) {
		if (isPrime[i]) {
			if (mmin == -1) mmin = i;
			sum += i;
		}
	}
	if (mmin == -1) {
		cout << -1;
	}
	else {
		cout << sum << endl << mmin;
	}
	return 0;
}