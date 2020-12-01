#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector <int64_t> l(2);
    l[0] = 2;
    l[1] = 1;
    int64_t ori_l;
    for(int i=2; i<=N; i++){
        ori_l = l[1];
        l[1] = l[0] + l[1];
        l[0] = ori_l;
    }
    cout << l[1] << endl;
}