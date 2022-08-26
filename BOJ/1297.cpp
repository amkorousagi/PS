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

	int d, h, w;
	cin >> d >> h >> w;
	
	double s = sqrt(h * h + w * w);

	cout << floor(h * d / s) << " " << floor(w * d / s);

	return 0;
}