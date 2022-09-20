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
vector<int> dp;
int n;
int s(int start) {
	if (dp[start] != -1) {
		return dp[start];
	}


	int mmax = 0;
	for (int i = start; i < n; i++) {
		if (i + t[i] <= n) {
			mmax = max(mmax, p[i] + s(i + t[i]));
		}
	}
	dp[start] = mmax;
	return mmax;

}

int main(void) {
	fastio;
	
	cin >> n;

	t.assign(n,0);
	p.assign(n,0);
	dp.assign(n + 1,-1);
	dp[n] = 0;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}

	cout << s(0);
	



	return 0;
}