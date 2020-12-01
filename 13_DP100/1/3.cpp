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

    int ng[301];
    rep(i,301) ng[i] = 1;

    rep(i,3){
        int ngi; cin >> ngi;
        ng[ngi] = 0;
    }

    if(ng[n] == 0){
        cout << "NO" << endl;
        return 0;
    }

    int dp[n+1];
    rep(i,n+1) dp[i] = 0;
    dp[0] = 1;

    int cnt = 0;
    int prev = 0;

    while(cnt<100){
        int admax = 0;
        if(ng[prev+3]){
            dp[prev+3] = 1;
            admax = max(admax, 3);
        }
        if(ng[prev+2]){
            dp[prev+2] = 1;
            admax = max(admax, 2);
        }
        else if(ng[prev+1]){
            dp[prev+1] = 1;
            admax = max(admax,1);
        }
        if(admax == 0) break;
        else prev += admax;
        cnt++;
    }
    // cout << dp[57] << endl;
    if(dp[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
}