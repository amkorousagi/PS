/**
 * @file template.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-11-18 16:29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int seven_d[101];
int main(void) {
	fastio;
	int dwarf[9];
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
	}
	bool find_answer = false;

	for (int i1 = 0; i1 < 9 && !find_answer; i1++)
		for (int i2 = i1+1; i2 < 9 && !find_answer; i2++)
			for (int i3 = i2+1; i3 < 9 && !find_answer; i3++)
				for (int i4 = i3+1; i4 < 9 && !find_answer; i4++)
					for (int i5 = i4+1; i5 < 9 && !find_answer; i5++)
						for (int i6 = i5+1; i6 < 9 && !find_answer; i6++)
							for (int i7 = i6 + 1; i7 < 9 && !find_answer; i7++) {
								if (dwarf[i1] + dwarf[i2] + dwarf[i3] + dwarf[i4] + dwarf[i5] + dwarf[i6] + dwarf[i7] == 100) {
									find_answer = true;
									seven_d[dwarf[i1]]++;
									seven_d[dwarf[i2]]++;
									seven_d[dwarf[i3]]++;
									seven_d[dwarf[i4]]++;
									seven_d[dwarf[i5]]++;
									seven_d[dwarf[i6]]++;
									seven_d[dwarf[i7]]++;
								}
							}

	for (int i = 1; i <= 100; i++) {
		if (seven_d[i] > 0) {
			cout << i << endl;
		}
	}

	return 0;
}