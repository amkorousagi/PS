#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

int s, n, k, r1, r2, c1, c2;

int get_color(int len, int row, int col) {
	if (len == 1) return 0;

	int unit = len / n;
	int k_min = (n - k) / 2 * unit;
	int k_max = len - k_min;

	if (k_min <= row && row < k_max) {
		if (k_min <= col && col < k_max) {
			return 1;
		}
	}

	return get_color(unit, row % unit, col % unit);
	
}
int main() {
	fastio;
	cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
	int len = pow(n, s);

	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			cout << get_color(len, i, j);
		}
		if (i != r2)
			cout << endl;
	}
	return 0;
}