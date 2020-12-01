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
    vector<int> p;
    rep(i,n){
        int r, c; cin >> r >> c;
        p.push_back(r);
        if(i == n-1){
            p.push_back(c);
        }
    }

    // 初期化
    ll dp[n][n];
    rep(i,n) rep(j,n) dp[i][j] = INF;
    rep(i,n) dp[i][i] = 0;

    for(int l=2; l<=n; l++){    // l:選ぶ行列の数、徐々に増えていく
        for(int i=1; i<=n-l+1; i++){
            int j = i+l-1;
            for(int k=i; k<j-1; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
}