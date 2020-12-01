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

const int MAX_N = 305;
const int INF = 1000100100;

int d[MAX_N][MAX_N];

void init(){
    rep(i,MAX_N) rep(j, MAX_N){
        if(i == j){
            d[i][j] = 0;
        }else{
            d[i][j] = INF;
        }
    }
}

int main()
{
    int N, M; cin >> N >> M;
    init();
    rep(_,M){
        int a, b, t; cin >> a >> b >> t;
        --a; --b;
        d[a][b] = t;
        d[b][a] = t;
    }
    rep(k,N){
        rep(i,N){
            if(d[i][k] == INF) continue;
            rep(j,N){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    int min_t = INF;
    rep(i,N){
        int max_d = -1;
        rep(j,N){
            if(max_d < d[i][j]) max_d = d[i][j];
            // cout << d[i][j] << " ";
        }// cout << endl;
        if(min_t > max_d) min_t = max_d;
    }
    cout << min_t << endl;
}