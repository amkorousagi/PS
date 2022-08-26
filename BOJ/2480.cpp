#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
	int a[3];
	int cnt[7] = { 0 };
	int max_cnt=0;
	int max_val=0;
	int eq = 0;

	for (int i = 0; i < 3; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 6; i > 0; i--) {
		if (cnt[i] >= max_cnt) {
			max_cnt = cnt[i];
			eq = i;
		}

		if (cnt[i] > 0) {
			if (max_val < i) {
				max_val = i;
			}
		}
	}

	if (max_cnt == 3) {
		cout << 10000 + eq * 1000;
	}
	else if (max_cnt == 2) {
		cout << 1000 + eq * 100;
	}
	else {
		cout << max_val * 100;
	}

	return 0;
}