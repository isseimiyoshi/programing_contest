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

const int MAX_H = 205, MAX_W = 205;
const int INF = 1000100100;

int d[10][10];

void init(){
    rep(i,MAX_H){
        rep(j,MAX_W){
            d[i][j] = ((i==j) ? 0 : INF);
        }
    }
}

int main()
{
    int H, W; cin >> H >> W;
    rep(i,10){
        rep(j,10){
            int cij; cin >> cij;
            d[i][j] = cij;
        }
    }
    rep(k,10){
        rep(i,10){
            rep(j,10){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    /*
    rep(i,10){
        rep(j,10) cout << d[i][j] << " ";
        cout << endl;
    }
    */
    int cost = 0;
    rep(i,H){
        rep(j,W){
            int Aij; cin >> Aij;
            if(Aij == -1 || Aij == 1) continue;
            else{
                cost += d[Aij][1];
            }
        }
    }
    cout << cost << endl;
}