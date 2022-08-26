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

	
	int a, b, c;
	cin >> a >> b >> c;
	if (b >= c) {
		cout << -1;
		return 0;
	}
	
	cout <<(int)floor(((double)a) / (c - b))+1;

	return 0;
}