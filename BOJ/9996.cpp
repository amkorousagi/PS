#include <bits/stdc++.h>
#include <regex>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

int main() {
	fastio;
	int n;
	cin >> n;
	string s;
	cin >> s;
	// string split 구현
	string buf;
	istringstream ss(s);
	vector<string> res;
	while (getline(ss, buf, '*')) {
		res.push_back(buf);
	}

	regex re(res[0] + ".*" + res[1]);

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (regex_match(s, re)) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}

	return 0;
}