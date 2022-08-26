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

vector<int> v;
bool bs(int s, int e, int a) {
	if (s > e) return false;
	int mid = (s + e) / 2;
	if (v[mid] == a) {
		return true;
	}
	else if (v[mid]>a){
		return bs(s, mid - 1, a);
	}
	else {
		return bs(mid+1, e, a);
	}
}
int main(void) {
	fastio;
	int m, n;
	long long a;
	cin >> n;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[i] = a;
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (bs(0, n-1, a)) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}

	}

	return 0;
}
//2147483647