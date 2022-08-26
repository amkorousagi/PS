#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int n;
	vector<int> honey;

	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		honey.push_back(temp);
	}

	// case 1 벌벌통
	int sum1 = 0;
	int max1 = INT_MIN;
	for (int i = 1; i < n; i++) {
		sum1 += honey[i];
	}
	sum1 -= honey[n - 1];
	for (int i = n-2; i >=1; i--) {
		sum1 += 2 * honey[i + 1] - honey[i];
		if (sum1 > max1) {
			max1 = sum1;
		}
	}

	// case 2 벌통벌
	int sum2 = 0;
	int max_honey = INT_MIN;
	int max2;
	for (int i = 1; i < n - 1; i++) {
		sum2 += honey[i];
		if (max_honey < honey[i]) {
			max_honey = honey[i];
		}
	}
	max2 = sum2 + max_honey;
	

	// case 3 통벌벌
	int sum3 = 0;
	int max3 = INT_MIN;
	for (int i = n-2; i >=0; i--) {
		sum3 += honey[i];
	}
	sum3 -= honey[0];
	for (int i = 1; i < n-1 ; i++) {
		sum3 += 2 * honey[i - 1] - honey[i];
		if (sum3 > max3) {
			max3 = sum3;
		}
	}

	int final_max = max(max1, max(max2,max3));

	cout << final_max;
	



	return 0;
}