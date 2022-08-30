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

	int n, mmax = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mmax = max(v[i], mmax);
	}
	vector<bool> isPrime(mmax + 1, true);
	isPrime[1] = false;
	for (int i = 2; i * i <= mmax; i++) {
		if (!isPrime[i]) {
			continue;
		}
		for (int j = i * 2; j <= mmax; j += i) {
			isPrime[j] = false;
		}
	}
	int cnt = 0;
	for (int a = 0; a < n; a++) {
		if (isPrime[v[a]]) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}