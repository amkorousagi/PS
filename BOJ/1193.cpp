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
	int x,cnt=0;
	int dia = 1;
	int row, col;
	cin >> x;
	for (int i = 1;; i++) {
		if (cnt < x && x <= cnt + i) {
			if (dia % 2 == 0) {
				row = 1;
				col = dia;

				for (int j = 1; j < x-cnt; j++) {
					row++;
					col--;
				}
			}
			else {
				row = dia;
				col = 1;

				for (int j = 1; j < x-cnt; j++) {
					row--;
					col++;
				}
			}
			break;
		}
		else {
			dia++;
			cnt += i;
		}
	}
	cout << row << "/" << col;

	return 0;
}