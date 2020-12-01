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

const int MAX_N = 100, MAX_M = 100;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int n, m;
int M[MAX_N][MAX_M];
int max_d = 0;

void dfs(int h, int w, int d){
    M[h][w] = 0;
    if(max_d < d) max_d = d;
    rep(i,4){
        int vh = h + dx[i];
        int vw = w + dy[i];
        if(vh>=0 && vh<n && vw>=0 && vw<m){
            if(M[vh][vw] == 1) dfs(vh, vw, d+1);
        }
    }
    M[h][w] = 1;
}

int main()
{
    cin >> m >> n;
    rep(i,n){
        rep(j,m){
            cin >> M[i][j];
        }
    }
    rep(i,n){
        rep(j,m){
            if(M[i][j]) dfs(i,j,1);
        }
    }
    cout << max_d << endl;
}