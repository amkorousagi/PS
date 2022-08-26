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

int main(void) {
	fastio;
	char S[105];  //사이즈가 100인 배열생성
	cin >> S; //각 index에 문자 입력

	int size = 0;
	for (int i = 0; i < 105; i++)  //문자가 들어가 있는 배열의 실제 사이즈 찾기
	{
		if (S[i] == '\0') {
			size = i;
			break;
		}
	}

	for (int i = 0; i < 26; i++) //소문자 a~z까지 반복
	{
		int change = 0;
		for (int j = 0; j < size; j++) //각 소문자마다 배열의 실사이즈를 반복
		{
			if (i == S[j] - 'a') //소문자와 배열의 문자가 같다면 그때의 index값 출력
			{
				cout << j << " ";
				change = 1;
				break;
			}
		}
		if (change == 0) //만약 같은 문자가 없다면 -1 출력
			cout << "-1 ";
	}


	return 0;
}