#include <iostream>
#include <cstdio>
#define endl '\n'

using namespace std;
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1;i<=n;i++) {
		for (int j = 0;j < i;j++)
			cout << "*";
		cout << endl;
	}

	return 0;
}