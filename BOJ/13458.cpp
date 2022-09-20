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
	long long n, b, c;
	cin >> n;
	vector<long long> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - b > 0)
			sum+= (a[i] - b) % c ? (a[i] - b) / c + 2 : (a[i] - b) / c + 1;
		else
			sum+= 1;
	}
	cout << sum;
	return 0;
}