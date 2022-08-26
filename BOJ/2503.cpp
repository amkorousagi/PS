#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

bool answer[1001];

bool is_proper_base_answer(int example) {
	int digit100 = example / 100;
	int digit10 = example / 10 % 10;
	int digit1 = example % 10;

	//1~9
	if (digit100 == 0 || digit10 == 0 || digit1 == 0) {
		return false;
	}

	//서로 다른
	if (digit100 == digit10 || digit100 == digit1) {
		return false;
	}
	else if (digit10 == digit1) {
		return false;
	}

	return true;
}

bool is_match_sb(int prediction, int example, int  s, int b) {
	int pre100 = prediction / 100;
	int pre10 = prediction / 10 % 10;
	int pre1 = prediction % 10;
	int pre[3] = { pre100, pre10, pre1 };

	int ex100 = example / 100;
	int ex10 = example / 10 % 10;
	int ex1 = example % 10;
	int ex[3] = { ex100,ex10,ex1 };

	int b_cnt = 0, s_cnt = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (pre[i] == ex[j]) {
				if (i == j) {
					s_cnt++;
				}
				else {
					b_cnt++;
				}
			}
		}
	}

	if (b == b_cnt && s == s_cnt) {
		return true;
	}
	return false;
	
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 100; i <= 999; i++) {
		answer[i] = is_proper_base_answer(i);
	}

	int prediction, strike, ball;
	
	//무식하게 풀 수 있는가? 가능한 모든 경우를 고려
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &prediction,&strike,&ball);
		
		for (int example = 100; example <= 999; example++) {
			if (answer[example]) {
				answer[example] = is_match_sb(prediction, example,strike,ball);
			}
		}
		
	}

	int cnt = 0;
	for (int i = 100; i <= 999; i++) {
		if (answer[i]) {
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}