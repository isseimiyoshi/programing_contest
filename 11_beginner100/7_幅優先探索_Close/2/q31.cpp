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

int evenh[6] = {-1, -1, 0, 1, 1, 0};
int evenw[6] = {-1, 0, 1, 1, 0, -1};

int oddh[6] = {-1, -1, 0, 1, 1, 0};
int oddw[6] = {0, 1, 1, 1, 0, -1};

int main()
{
    int h, w; cin >> w >> h;
    int mass[h][w];
    rep(i,h) rep(j,w) cin >> mass[i][j];

    rep(i,h){
        rep(j,w){
            int cnt = 0;
            if(j % 2 == 1){
                rep(k,6){
                    int h2 = h + oddh[k]; int w2 = w + oddw[k];
                    if(h2<0 || h2>=h || w2<0 || w2>=w) cnt++;
                    else if(mass[h2][w2] == 1) cnt++;
                }
            }else{
                rep(k,6){
                    int h2 = h + evenh[k]; int w2 = w + evenw[k];
                    if(h2<0 || h2>=h || w2<0 || w2>=w) cnt++;
                    else if(mass[h2][w2] == 1) cnt++;
                }
            }
            if(cnt == 6) mass[i][j] = 1;
        }
    }

    int distance[h][w];
    rep(i,h) rep(j,w) distance[i][j] = INF;

    rep(i,h){
        rep(j,w){
            if(mass[i][j] == 1 && distance[i][j] == INF){
                distance[i][j] = 0;
                queue<P> q;
                q.push(make_pair(i,j));

                while(!q.empty()){
                    P u = q.front(); q.pop();
                    rep(k,6){
                        int vh, vw;
                        if(u.second % 2 == 0){
                            vh = u.first + oddh[k]; vw = u.second + oddw[k];
                        }else{
                            vh = u.first + evenh[k]; vw = u.second + evenw[k];
                        }
                        if(vh<0 || vh>=h || vw<0 || vw>=w) continue;

                        if(distance[vh][vw] == INF && mass[vh][vw] == 1){
                            distance[vh][vw] = distance[u.first][u.second] + 1;
                            q.push(make_pair(vh, vw));
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    rep(i,h){
        rep(j,w){
            if(distance[i][j] != INF){
                int cnt = 0;
                rep(k,6){
                    int i2, j2;
                    if(j % 2 == 0){
                        i2 = i + oddh[k]; j2 = j + oddw[k];
                    }else{
                        i2 = i + evenh[k]; j2 = j + evenw[k];
                    }
                    if(i2<0 || i2>=h || j2<0 || j2>=w){
                        continue;
                    }else{
                        if(abs(distance[i][j] - distance[i2][j2]) <= 1) cnt++;
                    }
                }
                ans += (6-cnt);
            }
        }
    }
    cout << ans << endl;
    /*
    rep(i,h){
        rep(j,w){
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
    */
}