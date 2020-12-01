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

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int main()
{
    int H, W; cin >> H >> W;
    int c[H][W], dist[H][W];
    int Bn = 0;
    rep(i,H){
        rep(j,W){
            char cij; cin >> cij;
            if(cij == '.') c[i][j] = 1;
            else if(cij == '#') c[i][j] = 0, ++Bn;
            dist[i][j] = -1;
        }
    }
    dist[0][0] = 0;
    queue<P> q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        P u = q.front(); q.pop();
        rep(i,4){
            P v = make_pair(u.first+dx[i], u.second+dy[i]);
            if(v.first>=0 && v.first<H && v.second>=0 && v.second<W){
                if(dist[v.first][v.second] == -1 && c[v.first][v.second] == 1){
                    dist[v.first][v.second] = dist[u.first][u.second]+1;
                    q.push(v);
                }
            }
        }
    }
    if(dist[H-1][W-1] == -1) cout << -1 << endl;
    else cout << H*W-Bn-dist[H-1][W-1]-1 << endl;
}