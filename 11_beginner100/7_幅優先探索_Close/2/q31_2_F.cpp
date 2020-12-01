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

const int MAX_H = 200, MAX_W = 200;

int evenh[6] = {-1, -1, 0, 1, 1, 0};
int evenw[6] = {-1, 0, 1, 1, 0, -1};

int oddh[6] = {-1, -1, 0, 1, 1, 0};
int oddw[6] = {0, 1, 1, 1, 0, -1};

int main()
{
    int w, h; cin >> w >> h;

    int mass[MAX_H][MAX_W];
    rep(i,MAX_H) rep(j,MAX_W) mass[i][j] = 0;

    rep(i,h){
        rep(j,w){
            cin >> mass[i+50][j+50];
        }
    }

    int isblue[MAX_H][MAX_W];
    rep(i,MAX_H) rep(j,MAX_W) isblue[i][j] = 0;

    queue<P> q;
    q.push(make_pair(0,0));
    isblue[0][0] = 1;

    while(!q.empty()){
        P u = q.front(); q.pop();
        rep(k,6){
            P v;
            if(u.second % 2 == 0){
                v = make_pair(u.first+oddh[k], u.second+oddw[k]);
            }else{
                v = make_pair(u.first+evenh[k], u.second+evenw[k]);
            }
            if(v.first<0 || v.first>=MAX_H || v.second<0 || v.second>=MAX_W) continue;
            if(isblue[v.first][v.second] == 0 && mass[v.first][v.second] == 0){
                isblue[v.first][v.second] = 1;
                q.push(make_pair(v.first, v.second));
            }
        }
    }

    ll ans = 0;
    rep(i,MAX_H){
        rep(j,MAX_W){
            if(mass[i][j] == 1){
                int i2, j2;
                rep(k,6){
                    if(j % 2 == 0){
                        i2 = i + oddh[k]; j2 = j + oddw[k];
                    }else{
                        i2 = i + evenh[k]; j2 = j + evenw[k];
                    }
                    if(isblue[i2][j2]) ans++;
                }
            }
        }
    }
    cout << ans << endl;
}