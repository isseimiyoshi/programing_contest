#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //　保持している餅の枚数
    int N;
    cin >> N;
    // 保持している餅の直径を格納する配列
    vector <int> di(N);
    for(int i=0; i<N; i++){
        int d;
        cin >> d;
        di[i] = d;
    }
    sort(di.begin(), di.end());
    int dan = 0;
    int ori_d = 0;
    for(int i: di){
        if(i > ori_d){
            dan += 1;
            ori_d = i;
        }
    }
    cout << dan << endl;
}