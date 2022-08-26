#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
#define INF 1e8+1
#define init(a,b) memset((a),(b),sizeof((a)));
using namespace std;

int main() {
	fastio;
	int n;
	cin >> n;

	// 중복되는 경우가 많음, 더 자세히 말하자면, 2*2...*2 형태로 나누어지는 것은 다 중복됨.
	// 4부터 만들수 있는 2*2로 분해 불가능한 것만 뒤에서 더 세리면 됨
	// F(n) = F(n-2)*F(2) + (F(n-4)*2) +... + (F(0)*2)

	vector<int> v(n + 1, 0);
	v[0] = 1;
	for (int i = 2; i <= n; i+=2) {
		v[i] = 3 * v[i - 2];
		for (int j = i - 4; j >= 0; j--) {
			v[i] += 2 * v[j];
		}
	}
	cout << v[n];


	return 0;
}