#include <stdio.h>
#include <cstdio>
#include <iostream>


using namespace std;

int area[101][101] = { 0, };

void paint(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			area[i][j]++;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int i = 0; i < 4;i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		paint(x1, y1, x2, y2);
	}
	int cnt = 0;
	for (int i = 0;i < 101; i++) {
		for (int j = 0; j < 101;j++) {
			if (area[i][j]) cnt++;
		}
	}
	cout << cnt;
	return 0;
}

