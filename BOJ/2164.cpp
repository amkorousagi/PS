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
	int n, f;
	cin >> n;
	deque<int> d;
	
	for (int i = 1; i <= n; i++)
		d.push_back(i);

	for (;;) {
		if (d.size() == 1) {
			cout << d.front();
			break;
		}
		
		d.pop_front();
		
		f = d.front();
		d.pop_front();

		d.push_back(f);
	}
	return 0;
}