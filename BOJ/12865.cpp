#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int w[101];
int v[101];
int sum[100001];
int n, k;

int main(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	int max=0;
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= 1; j--) {
			//정순으로하면 이번 물건으로 업데이트한 값을 다시 이번 물건으로 업데이트함
			// sum[j - w[i]]!=0 를 넣으면 그 물건 하나만 넣는 경우를 시작 못함
			if (w[i] <= j) {
				if (sum[j] < sum[j - w[i]] + v[i]) {
					sum[j] = sum[j - w[i]] + v[i];
					if (max < sum[j]) {
						max = sum[j];
					}
				}
				
			}
		}
	}
	cout << max;

	return 0;
}