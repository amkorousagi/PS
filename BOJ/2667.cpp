/*
2020 3 3 park se chan
https://www.acmicpc.net/problem/2667
this problem does require dfs
*/
/*

Q.how do i access this problem?
A. solve brute forth, feel some rule, optimize algorithm. transform ofline algorithm to online algorithm.

Q.critical point for solving the problem
A.
we cannot save all sequenece --> online algorithm
when making candidate interval(or section), we insert one side, pop the other side! --> interval is implemented by queue!


*/

#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int count_complex;
int size_map;

int home[25][25];
int home_name[25][25];
vector<int> complex_n;

int dfs_complex(int y, int x);
void how_many_colplex();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	size_map = n;
	for (int i = 0; i < n; i++) {
		char s[25];
		cin >> s;
		for (int j = 0; j < n;j++) {
			int c;
			c = s[j] - '0';
			home[i][j] = c;
			home_name[i][j] = 0;

		}
		

	}
	how_many_colplex();


	return 0;
}

int dfs_complex(int y, int x) {
	if (y < 0 || y >= size_map || x < 0 || x >= size_map) {
		return 0; 
	}
	
	home_name[y][x] = 1;

	int ret = 1;
	const int dir_y[4] = { -1,0,1,0 };
	const int dir_x[4] = { 0,1,0,-1 };
	int next_x, next_y;

	for (int i = 0; i < 4;i++) {
		next_y = dir_y[i] + y;
		next_x = dir_x[i] + x;
		if (next_y >= 0 && next_y < size_map &&
			next_x >= 0 && next_x < size_map) {

			if (home[next_y][next_x] == 1 &&
				home_name[next_y][next_x] == 0)
				ret += dfs_complex(next_y, next_x);
		}
	}
	return ret;
}
void how_many_colplex() {
	int ret = 0;
	for (int y = 0; y < size_map;y++) {
		for (int x = 0; x < size_map;x++) {
			
			if (home[y][x] == 1 && home_name[y][x] == 0) {
				int size_complex;
				size_complex = dfs_complex(y, x);
				complex_n.push_back(size_complex);
				ret++;
			}
		}
	}
	cout << ret << endl;
	sort(complex_n.begin(), complex_n.end());
	for (int i = 0; i < complex_n.size(); i++)
		cout << complex_n[i] << endl;
}