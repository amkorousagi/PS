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

int A[10001];
int main(void) {
    fastio;
    int N;
    cin >> N;
    int original_N = N;

    int cnt = 0;
    for (;;) {

        int n10 = N / 10;
        int n1 = N % 10;
        int sum = n10 + n1;

        N = n1 * 10 + sum % 10;
        cnt++;

        if (original_N == N) {
            break;
        }

    }
    cout << cnt;


    return 0;
}