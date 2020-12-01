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

const int INF = 1000100100;

int main()
{
    int N, M; cin >> N >> M;
    vector<int> C(M), D(N);
    rep(i,N) cin >> D[i];
    rep(j,M) cin >> C[j];

    // 初期化
    int dp[M+1][N+1];
    rep(i,N+1){
        if(i == 0) dp[0][i] = 0;
        else dp[0][i] = INF;
    }
    rep(i,M+1){
        dp[i][0] = 0;
    }

    rep(i,M){
        rep(j,N){
            dp[i+1][j+1] = min(dp[i][j+1], dp[i][j] + C[i]*D[j]);

            // cout << dp[i+1][j+1] << " ";
        }// cout << endl;
    }

    cout << dp[M][N] << endl;
}