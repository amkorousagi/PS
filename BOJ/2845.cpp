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
	int n, m;
	cin >> n >> m;
	int a;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		cout << a - m * n<<" ";
	}

	return 0;
}