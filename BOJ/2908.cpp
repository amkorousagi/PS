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
	string n, m;
	cin >> n >> m;
	
	if (n[2] > m[2]) {
		cout << n[2] << n[1] << n[0];
	}
	else if (n[2] < m[2]) {
		cout << m[2] << m[1] << m[0];
	}
	else {
		if (n[1] > m[1]) {
			cout << n[2] << n[1] << n[0];
		}
		else if (n[1] < m[1]) {
			cout << m[2] << m[1] << m[0];
		}
		else {
			if (n[0] > m[0]) {
				cout << n[2] << n[1] << n[0];
			}
			else if (n[0] < m[0]) {
				cout << m[2] << m[1] << m[0];
			}
		}
	}

	return 0;
}