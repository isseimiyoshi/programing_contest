#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

int main()
{
    int N, W; cin >> N >> W;
    P item[N];
    rep(i,N){
        cin >> item[i].first >> item[i].second;
    }
    int A[N+1][W+1];
    rep(i,W+1) A[0][i] = 0; // 何も品物を選択しない場合は、価値が0になる
    rep(i,N+1) A[i][0] = 0; //ナップザックの耐久重量が0のとき、品物の価値は0となる
    // ここから動的計画法により実装してく
    for(int i=1; i<=N; i++){
        int in = i-1;
        for(int w=1; w<=W; w++){
            if(item[in].second > w) A[i][w] = A[i-1][w];
            else{
                if(item[in].first + A[i-1][w-item[in].second] > A[i-1][w]){
                    A[i][w] = A[i-1][w-item[in].second] + item[in].first;
                }else{
                    A[i][w] = A[i-1][w];
                }
            }
        }
    }
    cout << A[N][W] << endl;
}