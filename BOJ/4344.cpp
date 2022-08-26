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

int student[1001];
int main(void) {
    fastio;
    int C;
    cin >> C;

    for (int c = 0; c < C;c++) {
        int N;
        cin >> N;

        int sum = 0;
        for (int n = 0; n < N;n++) {
            cin >> student[n];
            sum += student[n];
        }
        int average = sum / N;
        int cnt = 0;
        for (int n = 0; n < N;n++) {
            if (average < student[n]) {
                cnt++;
            }
        }
        float rate = ((float)cnt / N) * 100;

        printf("%0.3lf%%\n", rate);

    }

    return 0;
}