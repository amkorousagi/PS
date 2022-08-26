#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int score[1001];

int cal_max_score(int card[5]) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += card[i];
	}

	int max_score = -1;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			int current_score = (sum - card[i] - card[j]) % 10;
			if (max_score < current_score) {
				max_score = current_score;
			}
		}
	}
	
	return max_score;
}

int main(void) {
	int n;
	scanf("%d", &n);
	// 가능한 모든 경우를 고려
	int card[5];
	int max_score = -1;
	int max_idx = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++)
			scanf("%d", &card[j]);


		score[i] = cal_max_score(card);

		if (max_score <= score[i]) { //같은 점수라면 더 높은 번호가 정답이라서 <=
			max_idx = i;
			max_score = score[i];
		}
		
	}

	

	printf("%d", max_idx);

	return 0;
}