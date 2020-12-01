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

int main()
{
    while(true){
        int w, h; cin >> w >> h;
        if(w == 0 && h == 0) break;

        int hor[h][w-1];
        int ver[h-1][w];
        rep(i,2*h-1){
            if(i%2 == 0){
                rep(j,w-1){
                    cin >> hor[h/2][j];
                }
            }else{
                rep(j,w){
                    cin >> ver[h/2][j];
                }
            }
        }

        int dis[h][w];
        rep(i,h) rep(j,w) dis[i][j] = INF;

        dis[0][0] = 0;
        queue<P> q;
        q.push(make_pair(0,0));

        int toh[4] = {-1, 0, 1, 0};
        int tow[4] = {0, 1, 0, -1};
        
        while(!q.empty()){
            P u = q.front(); q.pop();
            
            int h2, w2;

            h2 = u.first; w2 = u.second + 1;
            if((h2<0 || h2>=h || w2<0 || w2>=w)){
                if(hor[u.first][u.second] == 0 && dis[h2][w2] == INF){
                    dis[h2][w2] = dis[u.first][u.second] + 1;
                    q.push(make_pair(h2, w2));
                }
            }

            h2 = u.first+1; w2 = u.second;
            if((h2<0 || h2>=h || w2<0 || w2>=w)){
                if(ver[u.first][u.second] == 0 && dis[h2][w2] == INF){
                    dis[h2][w2] = dis[u.first][u.second] + 1;
                    q.push(make_pair(h2, w2));
                }
            }

            h2 = u.first-1; w2 = u.second;
            if((h2<0 || h2>=h || w2<0 || w2>=w)){
                if(hor[u.first][u.second-1] == 0 && dis[h2][w2] == INF){
                    dis[h2][w2] = dis[u.first][u.second] + 1;
                    q.push(make_pair(h2, w2));
                }
            }

            h2 = u.first; w2 = u.second-1;
            if((h2<0 || h2>=h || w2<0 || w2>=w)){
                if(ver[u.first-1][u.second] == 0 && dis[h2][w2] == INF){
                    dis[h2][w2] = dis[u.first][u.second] + 1;
                    q.push(make_pair(h2, w2));
                }
            }
        }
        if(dis[h-1][w-1] == INF) cout << 0 << endl;
        else cout << dis[h-1][w-1] << endl;
        
    }
}