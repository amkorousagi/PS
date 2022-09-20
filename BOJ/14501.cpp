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

int mmax;
vector<int> t;
vector<int> p;
int n;
int sum;
void s(int start) {
	if (start == n) {
		mmax = max(mmax, sum);
	}

	for (int i = start; i < n; i++) {
		if (i + t[i] - 1 < n) {
			sum += p[i];
			s(i + t[i]);
			sum -= p[i];
		}
		else {
			mmax = max(mmax, sum);
		}
	}

}

int main(void) {
	fastio;
	
	cin >> n;

	t.assign(n,0);
	p.assign(n,0);

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	s(0);
	cout << mmax;
	



	return 0;
}