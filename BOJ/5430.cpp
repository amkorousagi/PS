#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

void solve(string p, int n, string x) {
	deque<int> seq;
	int sum = 0;
	for (int i = 1; i < x.size(); i++) {
		if (x[i] == ',' || x[i] == ']') {
			if(sum!=0)
				seq.push_back(sum);
			sum = 0;
			continue;
		}
		sum = sum * 10 + (x[i] - '0');
	}
	bool is_reverse = false;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 'R') {
			//reverse(seq.begin(), seq.end()); // 시간 복잡도 O(n)
			is_reverse = !is_reverse;
		}
		else {
			if (seq.size() == 0) {
				cout << "error" << endl;
				return;
			}
			if (is_reverse) {
				seq.pop_back();
			}
			else { 
				seq.pop_front();
			}
		}
	}


	cout << "[";
	if (!is_reverse) {
		for (int i = 0; i < seq.size(); i++) {
			cout << seq[i];
			if (i != seq.size() - 1) {
				cout << ",";
			}
		}
	}
	else {
		for (int i = seq.size()-1; i >=0; i--) {
			cout << seq[i];
			if (i != 0) {
				cout << ",";
			}
		}
	}
	cout << "]" << endl;
}

int main() {
	fastio;
	int T;
	cin >> T;
	string p, x;
	int n;
	for (int t = 0; t < T; t++) {
		cin >> p;
		cin >> n;
		cin >> x;
		solve(p, n, x);
	}

	return 0;
}