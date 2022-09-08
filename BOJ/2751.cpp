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
int main(void) {
	fastio;
	
	int n;
	cin >> n;
	v.assign(n,0);
	for (int& a : v) {
		cin >> a;
	}
	sort(v.begin(), v.end());
	for (int a : v) {
		cout << a << endl;
	}
	return 0;
}