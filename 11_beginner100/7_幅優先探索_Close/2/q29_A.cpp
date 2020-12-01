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

int tox[4] = {0, 1, 0, -1};
int toy[4] = {-1, 0, 1, 0};

int main()
{
    int r, c; cin >> r >> c;
    int sy, sx; cin >> sy >> sx; --sy, --sx;
    int gy, gx; cin >> gy >> gx; --gy, --gx;

    int mass[r][c];

    rep(i,r){
        rep(j,c){
            char m; cin >> m;
            if(m == '#') mass[i][j] = 0;
            else mass[i][j] = 1;
        }
    }

    int dist[r][c];
    rep(i,r)rep(j,c) dist[i][j] = -1;

    queue<P> q;
    q.push(make_pair(sx, sy));
    dist[sy][sx] = 0;

    while(!q.empty()){
        P u = q.front(); q.pop();
        rep(i,4){
            int x = u.first + tox[i]; int y = u.second + toy[i];
            if(x<0 || x>=c || y<0 || y>=r) continue;
            if(dist[y][x] == -1 && mass[y][x] == 1){
                dist[y][x] = dist[u.second][u.first] + 1;
                q.push(make_pair(x, y));
            }
        }
    }

    cout << dist[gy][gx] << endl;
}