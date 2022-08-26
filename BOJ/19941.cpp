#include <iostream>
#include <deque>

using namespace std;


char s[20001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != 'P') continue;
		for (int j = i - k; j <= i + k; j++) {
			if (0 <= j && j < n && s[j] == 'H') {
				s[j] = '*';
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
