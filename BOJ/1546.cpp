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
	int m=-1, sum = 0;
	int n,a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += a;
		m = max(m, a);
	}
	cout << (sum / (double)n) / m * 100;

	return 0;
}