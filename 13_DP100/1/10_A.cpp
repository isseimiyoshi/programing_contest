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
    int n; cin >> n;
    int r[n];
    rep(i,n) cin >> r[i];

    int dp[n];
    dp[0] = 1;

    int upflag = 0;
    int max_n = -INF;
    int min_n = INF;

    for(int i=1; i<n; i++){
        if(upflag == 0){
            if(r[i]>r[i-1]){
                upflag = -1;    // 小さいものを探す
                max_n = r[i];
                dp[i] = dp[i-1]+1;
            }else if(r[i]<r[i-1]){
                upflag = 1;    // 大きいものを探す
                min_n = r[i];
                dp[i] = dp[i-1]+1;
            }else{
                dp[i] = dp[i-1];
            }
        }else if(upflag == 1){
            if(r[i]>min_n){
                upflag = -1;
                dp[i] = dp[i-1]+1;
                max_n = r[i];
                min_n = INF;
            }else{
                min_n = r[i];
                dp[i] = dp[i-1];
            }
        }else{
            if(r[i]<max_n){
                upflag = 1;
                dp[i] = dp[i-1]+1;
                min_n = r[i];
                max_n = INF;
            }else{
                max_n = r[i];
                dp[i] = dp[i-1];
            }
        }
    }
    if(dp[n-1]<3) cout << 0 << endl;
    else cout << dp[n-1] << endl;
}