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

	int n[2001];
	int cnt = 1;
	int sum = 0;
	int a, b;
	cin >> a >> b;

	for (int i = 1; i <= 1000;) {
		for (int j = 0; j < cnt; j++) {
			n[i + j] = cnt;
			if (a <= i + j && i + j <= b) {
				sum += cnt;
			}
		}
		i += cnt;
		cnt++;
		
	}
	cout << sum;
	

	return 0;
}