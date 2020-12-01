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
    int H, W; ll K, V;
    cin >> H >> W >> K >> V;
    ll A[H+1][W+1];
    rep(i,H+1) rep(j,W+1) A[i][j] = 0;
    rep(i,H) rep(j,W) cin >> A[i+1][j+1];
    for(int i=1; i<H+1; i++){
        for(int j=1; j<W+1; j++){
            A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
        }
    }
    // cout << A[1][1] << endl;
    // すべての長方形を網羅する
    ll max_S = 0;
    for(int h1=1; h1<=H; h1++){
        for(int h2=h1; h2<=H; h2++){
            for(int w1=1; w1<=W; w1++){
                for(int w2=w1; w2<=W; w2++){
                    ll S = (h2-h1+1)*(w2-w1+1); // 長方形の面積
                    ll M = A[h2][w2] - A[h2][w1-1] - A[h1-1][w2] + A[h1-1][w1-1] + K*S;
                    // cout << S << " " << M << endl;
                    if(V>=M && S>max_S){
                        max_S = S;
                    }
                }
            }
        }
    }
    cout << max_S << endl;
}