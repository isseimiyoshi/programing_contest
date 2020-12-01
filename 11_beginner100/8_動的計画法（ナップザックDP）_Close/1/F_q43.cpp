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
    int n; cin >> n;
    vector<string> S(5);
    rep(i,5){
        cin >> S[i];
    }

    int dp[n][3];   // 0:白、1:赤、2:青
    rep(i,n) rep(j,3){
        if(i == 0){
            dp[i][j] = 5;
        }else{
            dp[i][j] = INF;
        }
    }

    // 初期値
    rep(j,5){
        // cout << S[j][0] << endl;
        if(S[j][0] == 'W'){
            dp[0][0]--;
        }else if(S[j][0] == 'R'){
            dp[0][1]--;
        }else if(S[j][0] == 'B'){
            dp[0][2]--;
        }else{
            continue;
        }
    }

    // printf("%d %d %d\n", dp[0][0], dp[0][1], dp[0][2]);

    // 動的計画法を適用する
    for(int i=1; i<n; i++){
        int Wcnt = 0, Rcnt = 0, Bcnt = 0;
        rep(j,5){
            if(S[j][i] == 'W'){
                ++Wcnt;
            }else if(S[j][i] == 'R'){
                ++Rcnt;
            }else if(S[j][i] == 'B'){
                ++Bcnt;
            }
        }
        
        // printf("%d %d %d\n", Wcnt, Rcnt, Bcnt);

        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + (5-Wcnt);
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + (5-Rcnt);
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + (5-Bcnt);
    }

    int ans = INF;
    rep(k,3){
        ans = min(ans, dp[n-1][k]);
    }

    cout << ans << endl;

    return 0;
}