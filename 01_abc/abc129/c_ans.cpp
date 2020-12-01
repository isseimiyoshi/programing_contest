#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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

const int mod = pow(10,9)+7;

int main()
{
    int N,M; cin >> N >> M;
    vector<int> oks(N+1, true);
    rep(i,M){
        int a; cin >> a;
        oks[a] = false;
    }
    vector<ll> dp(N+1);
    dp[0] = 1;
    // nowは今何段目の階段にいるかを表す
    rep(now, N){
        for(int next=now+1; next<=min(N,now+2); next++){
            if(oks[next]){
                dp[next] += dp[now];
                dp[next] %= mod;
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}