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

vector<vector<int>> mmap;
int n, m, r, c, d;
int cnt;



void clean(int cr, int cc, int cd, int ro) {
	//cout << cr << " " << cc <<" "<< cd<<" "<<ro << endl;
	if (mmap[cr][cc] == 0) {
		cnt++;
		mmap[cr][cc] = 2;
	}	

	int nr, nc, nd;

	if (ro == 4) {
		nd = (cd) % 4;
		if (nd == 0) {
			nr = cr+1;
			nc = cc;
		}else if (nd == 1) {
			nr = cr;
			nc = cc-1;
		}
		else if (nd == 2) {
			nr = cr-1;
			nc = cc;
		}
		else if (nd == 3) {
			nr = cr;
			nc = cc+1;
		}
		nd = (cd + 2) % 4;

		if (mmap[nr][nc] == 1) {
			return;
		}
		else {
			clean(nr, nc, cd, 0);
		}
		return;
	}

	if (cd == 0) {
		nr = cr;
		nc = cc-1;
		nd = 3;
		if (mmap[nr][nc] == 0) {
			clean(nr, nc, nd, 0);
		}
		else {
			clean(cr, cc, nd, ro + 1);
		}
	}else if (cd == 1) {
		nr = cr - 1;
		nc = cc;
		nd = 0;
		if (mmap[nr][nc] == 0) {
			clean(nr, nc, nd, 0);
		}
		else {
			clean(cr, cc, nd, ro + 1);
		}
	}
	else if (cd == 2) {
		nr = cr;
		nc = cc + 1;
		nd = 1;
		if (mmap[nr][nc] == 0) {
			clean(nr, nc, nd, 0);
		}
		else {
			clean(cr, cc, nd, ro + 1);
		}
	}
	else if (cd == 3) {
		nr = cr + 1;
		nc = cc;
		nd = 2;
		if (mmap[nr][nc] == 0) {
			clean(nr, nc, nd, 0);
		}
		else {
			clean(cr, cc, nd, ro + 1);
		}
	}
}

int main(void) {
	fastio;
	
	cin >> n >> m;
	cin >> r >> c >> d;

	mmap.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mmap[i][j];
		}
	}
	clean(r, c, d, 0);

	cout << cnt;
	return 0;
}