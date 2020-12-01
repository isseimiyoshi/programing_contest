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

const int INF = 1000100100;

int tow[4] = {0, 1, 0, -1};
int toh[4] = {-1, 0, 1, 0};

int main()
{
    int h, w; cin >> h >> w;
    int mass[h][w];

    int wcnt = 0;

    rep(i,h){
        rep(j,w){
            char moji; cin >> moji;
            if(moji == '.'){
                mass[i][j] = 1;
                wcnt++;
            }else{
                mass[i][j] = 0;
            }
        }
    }

    int dis[h][w];
    rep(i,h) rep(j,w) dis[i][j] = INF;

    dis[0][0] = 0;
    queue<P> q;
    q.push(make_pair(0,0));

    while(!q.empty()){
        P u = q.front(); q.pop();
        rep(i,4){
            P v = make_pair(u.first+toh[i], u.second+tow[i]);
            if(v.first<0 || v.second<0 || v.first>=h || v.second>=w) continue;

            if(dis[v.first][v.second] == INF && mass[v.first][v.second] == 1){
                dis[v.first][v.second] = dis[u.first][u.second] + 1;
                q.push(v);
            }
        }
    }

    if(dis[h-1][w-1] == INF) cout << -1 << endl;
    else cout << (wcnt-dis[h-1][w-1]-1) << endl;
}