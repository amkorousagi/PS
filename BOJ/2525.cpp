#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	int c;
	cin >> c;
	if (c + b >= 60) {
		if (a + (b + c) / 60 >= 24) {
			cout << (a + (b + c) / 60) % 24 << " " << (b + c) % 60;
		}
		else {
			cout << a + (b + c) / 60 << " " << (b + c) % 60;
		}
	}
	else {
		cout << a << " " << (b + c);
	}
	return 0;
}