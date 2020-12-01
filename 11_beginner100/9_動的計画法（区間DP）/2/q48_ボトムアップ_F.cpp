#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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
    while(true){
        int n; cin >> n;
        if(n == 0) break;

        int w[n];
        rep(i,n) cin >> w[i];

        int dp[n+1][n+1];
        rep(i,n+1) rep(j,n+1) dp[i][j] = 0;

        for(int W=2; W<=n; W++){    // ブロックを選択する個数
            // left
            rep(l,n){
                int r = l + W;
                if(r > n) continue;

                if(dp[l+1][r-1] == W-2 && abs(w[l]-w[r-1])<=1){
                    dp[l][r] = W;
                }else{
                    for(int mid=l; mid<=r; mid++){
                        dp[l][r] = max(dp[l][r], dp[l][mid] + dp[mid][r]);
                    }
                }
            }
        }
        cout << dp[0][n] << endl;
    }
}