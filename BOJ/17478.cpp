/**
 * @file template.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-11-18 16:29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int max_depth;

void recursion(int depth) {
	if (depth > max_depth) {
		return;
	}
	string pre = "";
	for (int i = 0; i < depth; i++) {
		pre += "____";
	}

	cout << pre << "\"재귀함수가 뭔가요?\"" << endl;

	if (depth < max_depth) {
		cout << pre << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
		cout << pre << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
		cout << pre << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
	}
	else {
		cout << pre << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
	}

	recursion(depth + 1);
	cout << pre << "라고 답변하였지." << endl;
}

int main(void) {
	fastio;
	cin >> max_depth;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
	recursion(0);
	return 0;
}