/*
5
3 1 4 3 2


1 a1 a2 a3 ... ai... ai+1... an

ai > 1, 1<=i<=n

ai a1 a2 a3 ... 1...  ai+1... an = 최적해 ,가정

변형

선택



1 a1 a2 a3 ... ai...  ai+1... an

최적해?
행위가 손해?

ai+1~an : 앞에 인출 시간 총합 * (n-i)

ai * i
->
1 * i 더 적게 걸림

첫번째 선택에서,
가장 적은 인출 시간을 가장 앞에 두는 게 

"손해가 없다." ==> 탐욕 선택 속성 증명

최적 부분 구조도 성립
두번째 선택 부터도
첫번째 선택후 남은 사람들도 최소한 시간을 기다리도록 최선을 다하는 것이 옳다


*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>

int time[1001];


using namespace std;
int main(void) {

    int n;
    scanf("%d", &n);

    for (int i = 0;i < n;i++) {
        scanf("%d", &time[i]);
    }

    // swap? sort
    
    int min = INT_MAX;
    int min_idx = -1;
    for (int i = 0;i < n;i++) {
        int temp; // 공간 복잡도 O(1)
        for (int j = i; j < n; j++) {
            if (min > time[j]) { // > 비교연산 : 1/2 * n^2 = O(n^2)
                min = time[j];
                min_idx = j;
            }
        }
        temp = time[i];
        time[i] = time[min_idx];
        time[min_idx] = temp;

        min = INT_MAX;
        min_idx = -1;
    }
    
    // 오름차순 정렬 완료

    int sum = 0;
    for (int i = 0;i < n;i++) {
        sum += time[i] * (n - i);
    }

    printf("%d", sum);

    return 0;
}
