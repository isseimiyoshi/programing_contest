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

int w[310];
int dp[310][310];

void init(){
    rep(i,310){
        w[i] = -1;
        rep(j,310){
            dp[i][j] = -1;
        }
    }
}

int rec(int l, int r){
    // すでに計算済みなら
    if(dp[l][r] != -1) return dp[l][r];

    // これ以上取り除けない
    if(abs(l - r) <= 1) return 0;

    int res = 0;
    // 取り出そうとしている区間の間のブロックがすべて取り除けるか検証
    if(abs(w[l] - w[r-1]) <= 1 && rec(l+1, r-1) == r-l-2){
        res = r - l;
    }

    // もし取り出そうとしている区間の間のブロックがすべて取り除けなかったとき
    // いま検証しようとしている区間のうち、どこで区切れば一番多くブロックを取り出すことができるか検証
    for(int mid=l+1; mid <= r-1; mid++){
        res = max(res, rec(l,mid)+rec(mid,r));
    }
    return dp[l][r] = res;

}

int main()
{
   while(true){
        int n; cin >> n;
        if(n == 0) break;
        // 初期化
        init();

        rep(i,n) cin >> w[i];

        cout << rec(0,n) << endl;
   } 

   return 0;
}