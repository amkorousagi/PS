#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

vector<int> arr;
int n;

int brute_lis_from(int start) {
	if (start >= n) return 0;

	int res = 1;
	for (int i = start+1; i < n; i++) {
		if (start == 0) {
			res = max(res, brute_lis_from(i));
		}
		if (arr[start] < arr[i]) {
			res = max(res, 1 + brute_lis_from(i));
		}
	}
	return res;
}

int dp[1000];
int dp_lis(int start) {
	if (dp[start] != 0) return dp[start];
	if (start >= n) return 0;

	int res = 1;
	for (int i = start + 1; i < n; i++) {
		if (start == 0) {
			res = max(res, brute_lis_from(i));
		}
		if (arr[start] < arr[i]) {
			res = max(res, 1 + brute_lis_from(i));
		}
	}
	dp[start] = res;
	return res;
}

int bs[1001];
vector<pair<int, int>> trace;
int binary_search(int start, int end, int target) {
	if (start == end || start + 1 == end) return start;

	int mid = (start + end) / 2;
	if (target < bs[mid]) {
		return binary_search(start, mid, target);
	}
	if (bs[mid] == target) {
		return -1;
	}
	if (bs[mid] < target) { // 중복을 허용하는 수열인 경우를 고려. 가장 길이가 긴 놈 바로 뒤로 가야됨
		return binary_search(mid, end, target);
	}
}
void print_trace(int max_len) {
	cout << endl;
	for (int i = trace.size() - 1; i >= 0; i--) {

		if (trace[i].first != max_len) {
			continue;
		}
		else {
			max_len--;
			cout << trace[i].second << " ";
		}
	}
	cout << endl;
}
int bs_lis() {
	int max_len = 0;
	int tmp;
	for (int item : arr) {
		if (bs[max_len] < item) {
			max_len++;
			bs[max_len] = item;
			trace.push_back({ max_len, item });
			continue;
		}
		// binary search
		tmp = binary_search(0, max_len, item);
		if (tmp == -1) {
			continue;
		}
		bs[tmp + 1] = item;
		trace.push_back({ tmp + 1, item });
	}
	return max_len;

}


int main(void) {
	fastio;

	cin >> n;
	arr.assign(n, 0);
	for (int& it : arr)
		cin >> it;
	// 완전탐색의 경우 O(2^n)
	// cout << brute_lis_from(0);


	// 일반적인 DP의 경우 O(n^2)
	// dp_lis(0);
	// cout << dp[0];
	
	// 이진탐색을 이용하는 경우 O(n*logn)
	int res = bs_lis();
	cout << res;
	//print_trace(res);
	return 0;
}