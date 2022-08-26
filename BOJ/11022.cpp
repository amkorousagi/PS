#include <iostream>
#include <cstdio>
#define endl '\n'

using namespace std;
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a, b;
	for (int i = 1;i<=n;i++) {
		cin >> a >> b;
		cout << "Case #" << i << ": " <<a<<" + "<<b<< " = " <<a + b << endl;
	}

	return 0;
}