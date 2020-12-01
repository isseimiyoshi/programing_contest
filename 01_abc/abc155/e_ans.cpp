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

int dp[1000005][2];

int main()
{
    string s; cin >> s;
    reverse(s.begin(), s.end());
    s += '0';   // 桁が1つだけ上る可能性があるので
    int n = s.size();
    rep(i,n+1) rep(j,2) dp[i][j] = INF;
    dp[0][0] = 0;

    rep(i,n) rep(j,2){
        int x = s[i]-'0';   // 今の桁、nのi桁目
        x += j; // 繰り下がりを引く数をプラス1することで対応している

        rep(a,10){
            // ni：次の桁に行くだけなのでi+1
            // nj：繰り下がりが遷移先で起こる場合1、起こらない場合0、デフォルトは0
            int ni = i+1, nj = 0;    // 次の遷移先
            int b = a-x;
            if(b<0){
                nj = 1; // 繰り下がりを1にして、次の桁で繰り下がりが起こるようにする
                b += 10;
            }
            dp[ni][nj] = min(dp[ni][nj], dp[i][j]+a+b);
        }
    }
    int ans = dp[n][0];
    cout << ans << endl;
    return 0;
}