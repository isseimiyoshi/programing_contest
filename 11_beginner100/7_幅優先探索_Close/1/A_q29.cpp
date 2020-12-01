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

const int MAX_R = 55, MAX_C = 55;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int R, C;
int c[MAX_R][MAX_C];
int dist[MAX_R][MAX_C];

void init(){
    rep(i,MAX_R){
        rep(j,MAX_C){
            c[i][j] = 0;
            dist[i][j] = -1;
        }
    }
}

int main()
{
    cin >> R >> C;
    init();
    int ys, xs; cin >> ys >> xs; --ys; --xs;
    int yg, xg; cin >> yg >> xg; --yg; --xg;
    rep(i,R){
        rep(j,C){
            char cij; cin >> cij;
            if(cij == '.') c[i][j] = 1;
        }
    }
    queue<P> q;
    q.push(make_pair(ys, xs));
    dist[ys][xs] = 0;
    while(!q.empty()){
        P u = make_pair(q.front().first, q.front().second); q.pop();
        rep(i,4){
            P v;
            v.first = u.first + dx[i];
            v.second = u.second + dy[i];
            if(v.first>=0 && v.first<R && v.second>=0 && v.second<C){
                if(dist[v.first][v.second] == -1 && c[v.first][v.second] == 1){
                    dist[v.first][v.second] = dist[u.first][u.second]+1;
                    q.push(v);
                }
            }
        }
    }
    cout << dist[yg][xg] << endl;
}