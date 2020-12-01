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
    int h, w, n; cin >> h >> w >> n;
    P cheese[n+1];
    int mass[h][w];
    rep(i,h) rep(j,w){
        char moji; cin >> moji;
        if(moji == 'X'){
            mass[i][j] = 0;
            continue;
        }
        if(moji == 'S') cheese[0] = make_pair(i,j);
        else if(moji != '.'){
            int ind = moji-'0';
            // cout << ind << endl;
            cheese[ind] = make_pair(i,j);
        }
        mass[i][j] = 1;
    }

    int ans = 0;
    rep(i,n){
        int d[h][w];
        rep(j,h) rep(k,w) d[j][k] = INF;

        int sy = cheese[i].first, sx = cheese[i].second;
        int gy = cheese[i+1].first, gx = cheese[i+1].second;

        d[sy][sx] = 0;
        queue<P> q;
        q.push(make_pair(sy,sx));
        while(!q.empty()){
            int uy = q.front().first, ux = q.front().second;
            q.pop();
            rep(j,4){
                int vy = uy + toy[j], vx = ux + tox[j];
                if(vy>=h || vy<0 || vx>=w || vx<0) continue;
                if(d[vy][vx] == INF && mass[vy][vx] == 1){
                    d[vy][vx] = d[uy][ux] + 1;
                    q.push(make_pair(vy,vx));
                }
            }
        }
        ans += d[gy][gx];
    }
    cout << ans << endl;
}