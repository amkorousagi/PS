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
int n;
vector<vector<int>> paper;
int n_1, n0, n1;
void pp(int sr,int sc,int er,int ec) {
	int a = paper[sr][sc];

	bool s = true;
	for (int i = sr; i <= er; i++) {
		for (int j = sc; j <= ec; j++) {
			if (a != paper[i][j]) {
				s = false;
				break;
			}
		}
		if (!s) break;
	}

	if (s) {
		if (a == -1) {
			n_1++;
		}
		else if (a == 0) {
			n0++;
		}
		else {
			n1++;
		}
	}
	else {
		int step = ((er - sr) + 1)/3;
		
		pp(sr, sc, sr + step - 1, sc + step - 1);
		pp(sr, sc + step, sr + step - 1, sc + step * 2 - 1);
		pp(sr, sc + step * 2, sr + step - 1, ec);

		pp(sr + step, sc, sr + step*2 - 1, sc + step - 1);
		pp(sr + step, sc + step, sr + step*2 - 1, sc + step * 2 - 1);
		pp(sr + step, sc + step * 2, sr + step*2 - 1, ec);

		pp(sr+step*2, sc, er, sc + step - 1);
		pp(sr+step*2, sc + step, er, sc + step * 2 - 1);
		pp(sr+step*2, sc + step * 2, er, ec);
	}
}

int main(void) {
	fastio;
	cin >> n;
	paper.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	pp(0, 0, n-1, n - 1);
	cout << n_1 << endl << n0 << endl << n1;

	return 0;
}