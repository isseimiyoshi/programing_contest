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
int ori_d[MAX_N][MAX_N];

int main()
{
    int N; cin >> N;
    rep(i,N) rep(j,N){
        cin >> d[i][j];
        ori_d[i][j] = d[i][j];
    }
    rep(k,N){
        rep(i,N){
            rep(j,N){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    bool isMin = true;
    rep(i,N){
        rep(j,N){
            if(d[i][j] != ori_d[i][j]){
                isMin = false;
                break;
            }
        }
        if(!isMin) break;
    }
    if(isMin){
        rep(k,N){
            rep(i,N){
                rep(j,N){
                    if(d[i][j] == (d[i][k] + d[k][j]) && (i != k) && (j != k)){
                        d[i][j] = INF;
                    }
                }
            }
        }
        ll sum = 0;
        rep(i,N) for(int j=i+1; j<N; j++){
            if(d[i][j] != INF) sum += d[i][j];
        }
        cout << sum << endl;
    }
    else{
        cout << -1 << endl;
    }
}