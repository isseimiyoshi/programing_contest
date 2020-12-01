#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T &b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}


int f(int n){
    return n*n - 8*n + 3;
}

int main()
{
    int ans_min = 1000000000;
    int ans_max = 0;
    for(int i=0; i<=10; i++){
        chmin(ans_min, f(i));
        chmax(ans_max, f(i));
    }
    cout << ans_min << " " << ans_max << endl;
}