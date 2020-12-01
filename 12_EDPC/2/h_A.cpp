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

const int mod = 1000000007;

int main()
{
    int h, w; cin >> h >> w;
    int a[h][w];
    rep(i,h){
        rep(j,w){
            char moji; cin >> moji;
            if(moji == '.'){
                a[i][j] = 0;
            }else{
                a[i][j] = 1;
            }
        }
    }

    ll dp[h][w];
    rep(i,h) rep(j,w) dp[i][j] = 0;
    dp[0][0] = 1;
    rep(i,h){
        rep(j,w){
            if(a[i][j] == 1) continue;
            if(i == 0 && j == 0) continue;
            else if(i == 0){
                dp[i][j] = dp[i][j-1];
            }else if(j == 0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            dp[i][j] %= mod;
        }
    }

    cout << dp[h-1][w-1] << endl;
}