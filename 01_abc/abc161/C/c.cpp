#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t N, K;
    cin >> N >> K;
    int64_t ori_N;
    int64_t minN;
    minN = N % K;
    int64_t ori_minN = minN;
    if(ori_minN > abs(minN - K)) cout << abs(minN - K) << endl;
    else cout << minN << endl;
}