#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

vector<int> lis_last_min_val;
int tmp1[10001];
int tmp2[10001];
int tmp3[10001];

int binary_search(int start, int end, int target) {
	if (start == end) { // 종료조건 1
		return start;
	}
	if (start + 1 == end) { // 종료조건 2
		if (lis_last_min_val[start] < target) {
			return end;
		}
		else {
			return start;
		}
	}

	int mid = (start + end) / 2; // 소수점 버림

	if (lis_last_min_val[mid] > target) {
		return binary_search(start, mid, target);
	}
	else {
		return binary_search(mid + 1, end, target);
	}

}

int main() {
	fastio;
	int n;
	cin >> n;
	lis_last_min_val.assign(n + 1, INF);
	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		tmp1[i] = a;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a;
		tmp2[a] = i;
		tmp3[i] = a;
	}
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		arr[i] = tmp2[tmp1[i+1]];
	}
	lis_last_min_val[0] = -INF;
	int max_lis_len = 0;
	int tt;
	vector<pair<int,int>> trace;
	for (int& item : arr) {
		if (lis_last_min_val[max_lis_len] < item) {// 지금 보는 숫자가 가장긴부분수열의 마지막 값보다 크면 그냥 갖다 붙이면 됨
			max_lis_len++;
			lis_last_min_val[max_lis_len] = item;
			trace.push_back({ max_lis_len,item });
		}
		else {
			// 훼손 되기 전에 저장해두기
			tt = binary_search(0, max_lis_len, item);
			lis_last_min_val[tt] = item;
			trace.push_back({ tt,item });
		}
	}
	cout << max_lis_len << endl;
	
	
	vector<int> res;
	for (int i = trace.size() - 1; i >= 0; i--) {
		if (trace[i].first != max_lis_len) continue;
		res.push_back(tmp3[trace[i].second]);
		max_lis_len--;
	}
	sort(res.begin(),res.end());
	for (int i = 0; i < res.size() - 1; i++) {
		cout << res[i] << " ";
	}
	cout << res[res.size()-1];
	
	
	return 0;
}