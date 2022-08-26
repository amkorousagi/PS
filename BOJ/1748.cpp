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



int main(void) {
	fastio;
	string s;
	cin >> s;
	int sum = 0, ss = 0;;
	
	for (int i = 1; i < s.size(); i++) {
		sum += i * 9 * pow(10,i-1);
		ss = ss * 10 + 9;
	}

	sum += s.size() * (stoi(s) - ss);
	
	cout << sum;

	return 0;
}