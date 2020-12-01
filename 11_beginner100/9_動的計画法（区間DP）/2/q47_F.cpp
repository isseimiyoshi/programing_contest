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

int n;
int p[2100];
ll dp[2100][2100];

// メモ化再帰という手法
ll calc(int l, int r, int s){   // l:区間の左端、r:区間の右端、s:1の場合はIOIちゃんの出番、0の場合はJOIくんの出番

    // このブロックの条件に引っかからないと最終的な戻り値が確定できない
    if(~dp[l][r]) return dp[l][r];
    if(l == r){
        if(s) return dp[l][r] = 0;
        return dp[l][r] = p[l];
    }

    // このブロックは理解できた
    if(s){
        if(p[l]>p[r]){
            return dp[l][r] = calc((l+1)%n, r, 0);
        }else{
            return dp[l][r] = calc(l, (r+n-1)%n, 0);    // 次の番をJOIくんにしている
        }
    }

    // ここも理解できた
    return dp[l][r] = max(calc((l+1)%n, r, 1)+p[l], calc(l, (r+n-1)%n, 1)+p[r]);
}

int main()
{
    cin >> n;
    rep(i,n) cin >> p[i];

    rep(i,n) rep(j,n) dp[i][j] = -1;

    ll ret = 0;
    rep(i,n) ret = max(ret, calc((i+1)%n, (i+n-1)%n, 1)+p[i]);  // %nは円環である条件を考慮している
    cout << ret << endl;
}