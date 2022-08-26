#include <bits/stdc++.h>
#include <regex>
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int main() {
	fastio;
	string s[5];
	int gen_cnt = 0;
	int del_cnt = 0;
	string gen[2][2];
	string del[2];
	string target;

	smatch match;

	regex gen_regex("gen:\\s([A,B]{1})\\s->\\s([A,B]{1,3})");
	regex del_regex("del:\\s([A,B]{2,5})");
	regex target_regex("target:\\s([A,B]{2,20})");


	int i = 0;
	while (1) {
		getline(cin, s[i]);
		if (regex_match(s[i],match, gen_regex)) {
			gen[gen_cnt][0] = match[1].str(); // 0 은 가장 밖의 생략된 capture group
			gen[gen_cnt][1] = match[2].str();
			gen_cnt++; i++;
			continue;
		}
		if (regex_match(s[i], match, del_regex)) {
			del[del_cnt]= match[1].str();
			del_cnt++; i++;
			continue;
		}
		if (regex_match(s[i], match, target_regex)) {
			target = match[1].str();
			break;
		}
		
	}

	vector<string> code = { "A" };
	for (int i = 0; i < 10; i++) {
		string start = "";
		vector<bool> is_gen(code.size(), false);
		for (int k = 0; k < code.size(); k++) {
			start += code[k];
		}
		//cout << "start "<< start << endl;
		//gen
		for (int k = 0; k < code.size(); k++) {
			for (int j = 0; j < gen_cnt; j++) {
				string result;
				regex a(gen[j][0]);
				if (regex_match(code[k], a) && is_gen[k] == false) {
					is_gen[k] = true;
					code[k] = regex_replace(code[k], a, gen[j][1]);
				}
			}
		}

		//del
		string middle_code;
		for (int k = 0; k < code.size(); k++) {
			middle_code += code[k];
		}
		//cout <<"middle "<< middle_code << endl;
		vector<bool> is_match(middle_code.size(), false);
		for (int j = 0; j < del_cnt; j++) {
			//겹치는 것 인덱스만 세리고 한꺼번에 지움
			//겹치는 것 까지 지움 + 지우고 난 후 다시 적용 안함.
			regex a("("+del[j]+")");

			string tmp = middle_code;
			int offset = 0;
			while (regex_search(tmp,match,a)) {
				for (int x = match.position(0); x < match.position(0) + match.str().size(); x++) {
					is_match[x + offset] = true;
				}
				tmp = tmp.substr(1, tmp.size() - 1);
				offset++;
			}
					
		}/*
gen: A -> ABB
del: BB
target: AAAAAAAAAA
		 */
		string result = "";
		code.clear();
		for (int k = 0; k < middle_code.size(); k++) {
			if (!is_match[k]) {
				string s;
				s+= middle_code[k];
				result += middle_code[k];
				code.push_back(s);
			}
		}

		//cout <<"result " << result << endl;
		if (result == target) {
			cout << "O";
			return 0;
		}
		if (result == "") {
			break;
		}
		if (result.size() > 20) {
			//break;
		}
	}

	cout << "X";
	return 0;
}