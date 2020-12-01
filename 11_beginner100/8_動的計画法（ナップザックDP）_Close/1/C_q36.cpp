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
    rep(i,N) cin >> item[i].first >> item[i].second;
    int dp[N+1][W+1];
    // 初期化する
    rep(i,W+1) dp[0][i] = 0;    // 選択する品物がないときは重さに関わらず、価値の総和は0
    rep(i,N+1) dp[i][0] = 0;    // 重さが0のときは品物を選ぶことはできない
    // 動的計画法を適用する
    rep(i,N){
        for(int w=1; w<=W; w++){
            int vi, wi;
            vi = item[i].first; wi = item[i].second;
            if(wi > w){
                dp[i+1][w] = dp[i][w];
            }else{
                dp[i+1][w] = max(dp[i][w], max(dp[i][w-wi]+vi, dp[i+1][w-wi]+vi));
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}