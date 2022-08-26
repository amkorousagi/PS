#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

int main() {
	fastio;
	int t, n;
	cin >> t;
	char c;
	char first, end;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> c;
		deque<char> dq;
		dq.push_back(c);
		first = end = c;
		for (int j = 1; j < n; j++) {
			cin >> c;
			if (first >= c) {
				dq.push_front(c);
				first = c;
			}
			else {
				dq.push_back(c);
				end = c;
			}
		}
		for (int j = 0; j < n; j++) {
			cout << dq[j];
		}
		cout << endl;
	}

	return 0;
}