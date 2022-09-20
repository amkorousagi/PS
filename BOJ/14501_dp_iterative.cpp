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

vector<int> t;
vector<int> p;
vector<int> dp;
int n;
int main(void) {
	fastio;
	
	cin >> n;

	t.assign(n,0);
	p.assign(n,0);
	dp.assign(n + 1,0);
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}

	int mmax;
	for (int i = n-1; i >= 0; i--) {
		mmax = 0;
		for (int j = i; j < n; j++) {
			if(j + t[j]<=n)
				mmax = max(mmax, p[j] + dp[j + t[j]]);
		}
		dp[i] = mmax;
	}


	cout << dp[0];
	



	return 0;
}