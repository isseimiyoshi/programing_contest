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

int N; 
int p[2100];
ll dp[2100][2100];

ll calc(int l, int r, int s){   // l:区間の左端 r:区間の右端 s:
    if(~dp[l][r]) return dp[l][r];
    if(l == r){
        if(s) return dp[l][r]=0;
        return dp[l][r]=p[l];
    }
    if(s){
        if(p[l]>p[r]){
            return dp[l][r] = calc((l+1)%N, r, 0);
        }else{
            return dp[l][r] = calc(l,(r+N-1)%N, 0);
        }
    }
    return dp[l][r] = max(calc((l+1)%N, r, 1)+p[l], calc(l,(r+N-1)%N, 1)+p[r]);
}

int main()
{
    cin >> N;
    rep(i,N) cin >> p[i];

    rep(i,N) rep(j,N) dp[i][j] = -1;
    
    ll ret = 0; // これがJOIくんが獲得できる最大のポイントを格納するための変数
    rep(i,N){
        ret=max(ret,calc((i+1)%N,(i+N-1)%N,1)+p[i]);
    }
    cout << ret << endl;
}