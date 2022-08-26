#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))

char board[50][50];

int paint(char top_left, int top, int left) {

	int numPaint = 0;
	for (int i = 0; i < 8;i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 1) {
				//odd row
				if ((i * 8 + j) % 2 == 0) {
					//even index
					if (top_left == board[top+i][left+j]) {
						//must differ top_left,
						//but if same, increase paint count
						numPaint++;
					}
				}
				else {
					//odd index
					if (top_left != board[top+i][left+j]) {
						//must same top_left
						//but if differ, increase paint count
						numPaint++;
					}

				}
			}
			else {
				//even row
				if ((i * 8 + j) % 2 == 0) {
					//even index
					if (top_left != board[top+i][left+j]) {
						//must same top_left,
						//but if differ, increase paint count
						numPaint++;
					}
				}
				else {
					//odd index
					if (top_left == board[top+i][left+j]) {
						//must differ top_left
						//but if same, increase paint count
						numPaint++;
					}

				}

			}
		}
	}
	//printf("%c %d %d %d\n", top_left, top, left, numPaint);
	return numPaint;
}

int main(void) {
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);

	for (int i = 0; i < m;i++) {
			char temp[50];
			scanf("%s", temp);
			for (int j = 0;j < n;j++) {
				board[i][j] = temp[j];
			}
			
		
	}

	//search every case
	int minPaint = 50 * 50;
	for (int i = 0; i + 7 < m; i++) {
		for (int j = 0; j + 7 < n;j++) {
			//paint , return num of paint
			//printf("%d %d\n", i, j);
			int temp1 = paint('W', i, j);
			int temp2 = paint('B', i, j);
			minPaint = min(minPaint, min(temp1, temp2));
		}
	}



	printf("%d", minPaint);

	return 0;
}