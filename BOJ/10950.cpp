#include <iostream>

using namespace std;
int main(void) {
	int n;
	cin >> n;

	for (int i = 1;i <= n;i++) {
		int a, b;
		cin >> a >> b;
		cout << a + b << endl;
	}

	return 0;
}