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

int main()
{
    int H, W, K; cin >> H >> W >> K;
    char mass[H][W];
    int sum_blck = 0;
    rep(i,H){
        rep(j,W) cin >> mass[i][j];
        if(mass[i][j] == '#') sum_blck++;
    }
    // cout << mass[0][0] << endl;

    // 縦の黒の個数
    int H_blck[H];
    rep(i,H) H_blck[i] = 0;
    rep(i,H){
        rep(j,W){
            if(mass[i][j] == '#') H_blck[i]++;
        }
    }

    // 横の黒の個数
    int W_blck[W];
    rep(i,W) W_blck[i] = 0;
    rep(j,W){
        rep(i,H){
            if(mass[i][j] == '#') W_blck[j]++;
        }
    }

    rep(w1, W){
        for(int w2 = w1; w2<W; w2++){
            rep(h1, H){
                for(int h2 = h1; h2<H; h2++){
                    int ori_sum_blck = sum_blck;
                    for(int i=h1; i<=h2; i++) ori_sum_blck -= H_blck
                }
            }
        }
    }

}