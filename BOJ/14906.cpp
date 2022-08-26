#include <bits/stdc++.h>
#include <regex>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

regex split("(AB{0,1}.*C).*");
regex split2("(AH).*");
regex slump_regex("[D|E]{1}F+(.*)");
regex slimp_regex("AB(.*)C");
regex slimp_regex_to_slump("A(.*)C");
bool slump(string s) {
	smatch sm;
	regex_match(s, sm, slump_regex);
	if (sm.size() == 2) {
		if (sm[1].str() == "G") {
			return true;
		}
		else {
			return slump(sm[1].str());
		}
	}
	return false;
}
bool slimp (string s) {
	if (s == "AH") {
		return true;
	}
	smatch sm_to_slimp;
	smatch sm_to_slump;
	regex_match(s, sm_to_slimp, slimp_regex);
	if (sm_to_slimp.size() == 2) {
		return slimp(sm_to_slimp[1].str());
	}
	regex_match(s, sm_to_slump, slimp_regex_to_slump);
	if (sm_to_slump.size() == 2) {
		return slump(sm_to_slump[1].str());
	}
	return false;
}
bool slurpy(string s) {
	smatch sm;
	regex_match(s, sm, split);
	if (sm.size() == 2) {
		return slimp(sm[1].str()) && slump(s.substr(sm[1].str().size(), s.size() - sm[1].str().size()));
	}
	regex_match(s, sm, split2);
	if (sm.size() == 2) {
		return slimp(sm[1].str()) && slump(s.substr(sm[1].str().size(), s.size() - sm[1].str().size()));
	}
	return false;
}


int main() {
	fastio;
	int n;
	cin >> n;
	cout << "SLURPYS OUTPUT" << endl;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (slurpy(s)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
	
	return 0;
}