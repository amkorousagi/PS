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
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

char tarr[20010][52];
int arr[20010];
int mm[20010];
int temp[20010];

int main(void) {
	fastio;

	int num;
	int temp2;
	int count = 0;
	int count2 = 0;
	int max = -1;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s", tarr[i]);
		for (int j = 0; tarr[i][j] != 0; j++) //문자열 받으면서 문자가 몇개 있는지 세기
			arr[i]++;
		if (arr[i] > max)
			max = arr[i];                     //한 문자열에 최대 몇개의 문자가 있는지 확인
	}
	for (int i = 1; i <= max; i++) {
		for (int j = 0; j < num; j++)
			if (arr[j] == i)                    //문자의 개수가 i개인 것을 찾아서 temp에 몇번째 문자열인지 저장
				temp[count++] = j;
		for (int j = 0; j < count - 1; j++) {  //문자의 개수가 같은 것끼리 사전 순으로 비교. 버블 정렬.
			for (int k = 0; k < count - 1 - j; k++) {
				if (strcmp(tarr[temp[k]], tarr[temp[k + 1]]) > 0) {
					temp2 = temp[k + 1];
					temp[k + 1] = temp[k];
					temp[k] = temp2;
				}
			}
		}
		for (int j = 0; j < count; j++) { //사전순으로 정렬된 문자열을 인덱스에 순서대로 저장
			if (j < (count - 1) && strcmp(tarr[temp[j]], tarr[temp[j + 1]]) == 0) {
				continue;                //만약 다음 문자열과 같다면 뛰어넘기
			}
			mm[count2++] = temp[j];
		}
		count = 0;
	}
	for (int i = 0; i < count2; i++) {  //인덱스에 저장되있는 순으로 문자열 출력
		printf("%s\n", tarr[mm[i]]);
	}

	return 0;
}