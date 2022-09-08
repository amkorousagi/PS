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
	int a[6] = { 1,1,2,2,2,8 };
	int b;
	for (int& aa : a) {
		cin >> b;
		cout << (aa - b)<<" ";
	}

	return 0;
}