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

const int MAX_H = 10;
const int INF = 1000100100;

int main()
{
    int H, W, K; cin >> H >> W >> K;
    char HWchar[H][W];
    rep(i,H){
        rep(j,W){
            cin >> HW[i][j];
        }
    }
    int HWint[H][W];
    rep(i,H){
        rep(j,W){
            if(HWchar[i][j] == '0') HWint[i][j] = 0;
            else HWint[i][j] = 1;
        }
    }

    int HWruiseki[H][W];
    rep(i,H){
        rep(j,W){
            if(j == 0) HWruiseki = HWint[i][j];
            else HWruiseki = HWint[i][j] + HWint[i][j-1]; 
        }
    }


    int res = INF;
    rep(i,(1<<(H-1))){
        bitset<i> Hbit; // 仕切りを上から入れるみたいな認識の仕方にする

        int oriBreak = -1;
        rep(i,H-1){
            if(Hbit.test(i)){
                if(oriBreak == -1){
                    
                }
            }
        }

    }
}