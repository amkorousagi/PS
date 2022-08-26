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
	int n;
	cin >> n;

	long cnt1 = 1, cnt2 = 1, cnt3 = 1;
	long pcnt1 = 1, pcnt2 = 1, pcnt3 = 1;

	for (int i = 1; i < n; i++) {

		cnt1 = pcnt1 + pcnt3;
		cnt2 = pcnt2 + pcnt3;
		cnt3 = pcnt1 * 2 + pcnt3;

		pcnt1 = cnt1 % 9901;
		pcnt2 = cnt2 % 9901;
		pcnt3 = cnt3 % 9901;

	}
	cout << (cnt1+cnt2+cnt3) % 9901;


	return 0;
}