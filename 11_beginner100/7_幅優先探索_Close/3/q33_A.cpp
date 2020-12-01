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

const int toy[4] = {-1, 0, 1, 0};
const int tox[4] = {0, 1, 0, -1};

int main()
{
    int h, w; cin >> h >> w;

    int Bnum = 0;
    int mass[h][w];

    rep(i,h){
        rep(j,w){
            char moji; cin >> moji;
            if(moji == '.'){
                mass[i][j] = 1;
            }else{
                mass[i][j] = 0;
                Bnum++;
            }
        }
    }

    int d[h][w];
    rep(i,h) rep(j,w) d[i][j] = INF;

    d[0][0] = 0;
    queue<P> q;
    q.push(make_pair(0,0));

    while(!q.empty()){
        int uy = q.front().first, ux = q.front().second;
        q.pop();
        rep(i,4){
            int vy = uy + toy[i], vx = ux + tox[i];
            if(vy<0 || vx<0 || vy>=h || vx>=w) continue;
            if(d[vy][vx] == INF && mass[vy][vx] == 1){
                d[vy][vx] = d[uy][ux]+1;
                q.push(make_pair(vy,vx));
            }
        }
    }

    if(d[h-1][w-1] == INF) cout << -1 << endl;
    else cout << h*w-Bnum-d[h-1][w-1]-1 << endl;
}