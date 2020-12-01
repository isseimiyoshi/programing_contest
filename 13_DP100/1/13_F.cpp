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
    string s, t; cin >> s >> t;
    int sn = s.size();
    int tn = t.size();

    int dp[sn+1][tn+1];
    rep(i,sn+1) dp[i][0] = 0;
    rep(j,tn+1) dp[0][j] = 0;

    rep(i,sn){
        rep(j,tn){
            if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    string ans = "";
    int len = dp[sn][tn];
    int i = sn;
    int j = tn;
    while(len>0){
        if(s[i-1] == t[j-1]){
            ans += s[i-1];
            --len;
            --i;
            --j;
        }else if(dp[i][j] == dp[i-1][j]){
            --i;
        }else{
            --j;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}