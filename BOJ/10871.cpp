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

    int N, X;
    cin >> N >> X;
    for (int i = 0;i < N;i++)
        cin >> A[i];

    for (int i = 0;i < N;i++){
        if (X > A[i])
            cout << A[i] << " ";
    }


    return 0;
}