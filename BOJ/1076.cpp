/**
 * @template file author kadrick (kbk2581553@gmail.com)
 *
 * author:amkorousagi (hasmi5452@gmail.com)
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int ss(string s) {
	if (s == "black") {
		return 0;
	}
	else if (s == "brown") {
		return 1;
	}
	else if (s == "red") {
		return 2;
	}
	else if (s == "orange") {
		return 3;
	}
	else if (s == "yellow") {
		return 4;
	}
	else if (s == "green") {
		return 5;
	}
	else if (s == "blue") {
		return 6;
	}
	else if (s == "violet") {
		return 7;
	}
	else if (s == "grey") {
		return 8;
	}
	else if (s == "white") {
		return 9;
	}
}

int main(void) {
	fastio;
	long long sum = 0;
	string s;
	cin >> s;

	sum = ss(s) * 10;

	cin >> s;

	sum += ss(s);

	cin >> s;

	int a = ss(s);
	for (int i = 0; i < a; i++) {
		sum *= 10;
	}

	cout << sum;
	

	return 0;
}