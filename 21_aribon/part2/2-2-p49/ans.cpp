#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 入力
const int MAX_N = 20000;
int N, L[MAX_N];

void solve(){
    ll ans = 0;

    // このやり方であれば確実にNが減っていき、確実なループの終わりが見える　バグに繋がりにくい
    // 板が１本になるまで適用
    while(N>1){
        // 一番短い板、次に短い板を求める
        int mii1 = 0, mii2 = 1;
        if(L[mii1] > L[mii2]) swap(mii1, mii2);

        for(int i=2; i<N; i++){
            if(L[i] < L[mii1]){
                mii2 = mii1;
                mii1 = i;
            }else if(L[i] < L[mii2]){
                mii2 = i;
            }
        }

        // それらを併合
        int t = L[mii1] + L[mii2];
        ans += t;

        if(mii1 == N-1) swap(mii1, mii2);
        L[mii1] = t;
        L[mii2] = L[N-1];
        N--;
    }

    printf("%lld\n", ans);
}

/*
input

5
3 4 5 1 2

3
8 5 8

*/

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        int l; cin >> l;
        L[i] = l;
    }
    solve();
}