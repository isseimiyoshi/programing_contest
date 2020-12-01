#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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

int toy[4] = {-1, 0, 1, 0};
int tox[4] = {0, 1, 0, -1};

int main()
{
    int r, c; cin >> r >> c;
    int sy, sx; cin >> sy >> sx; --sy, --sx;
    int gy, gx; cin >> gy >> gx; --gy, --gx;

    int mass[r][c];
    int dis[r][c];
    rep(i,r) rep(j,c){
        char moji; cin >> moji;
        if(moji == '#') mass[i][j] = 0;
        else mass[i][j] = 1;
        dis[i][j] = INF;
    }

    dis[sy][sx] = 0;
    queue<P> q;
    q.push(make_pair(sy,sx));

    while(!q.empty()){
        P pu = q.front(); q.pop();
        int uy = pu.first, ux = pu.second;
        rep(i,4){
            int vy = uy + toy[i], vx = ux + tox[i];
            if(vy>=r || vy<0 || vx>=c || vy<0) continue;
            if(dis[vy][vx] == INF && mass[vy][vx] == 1){
                dis[vy][vx] = dis[uy][ux] + 1;
                q.push(make_pair(vy, vx));
            }
        }
    }

    cout << dis[gy][gx] << endl;
}   