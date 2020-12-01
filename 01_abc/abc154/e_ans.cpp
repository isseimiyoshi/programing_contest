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

int dp[105][4][2];

int main(){
    string s; cin >> s;
    int n = s.size();
    int K; cin >> K;

    dp[0][0][0] = 1;
    rep(i,n) rep(j,4) rep(k,2){
        int nd = s[i]-'0';
        rep(d,10){
            int ni = i+1, nj = j, nk = k;
            if(d != 0) nj++;
            if(nj > K) continue;
            if(k == 0){
                if(d>nd) continue;
                if(d<nd) nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    int ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << endl;
    return 0;
}