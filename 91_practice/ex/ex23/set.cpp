#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> S;
    S.insert(3);
    S.insert(8);
    S.insert(7);
    S.insert(10);
    // すでに3は含まれているから無視
    S.insert(3);

    // 集合の要素数を出力
    cout << "size:" << S.size() << endl;

    // 7が含まれるかの判定
    if(S.count(7)){
        cout << "found 7" << endl;
    }

    // 5が含まれるかの判定
    if(S.count(5)){
        cout << "found 5" << endl;
    }

    for(auto v: S){
        cout << v << endl;
    }
}