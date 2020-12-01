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
    int H, W, N; cin >> H >> W >> N;
    P N_coor[N]; P s;
    int c[H][W];
    rep(i,H) rep(j,W) c[i][j] = 0;  // 初期化
    rep(i,H){
        rep(j,W){
            char in; cin >> in;
            if(in == 'S') s.first = i, s.second = j, c[i][j] = 1;
            else if(in == '.') c[i][j] = 1;
            else if(in == 'X') continue;
            else{
                c[i][j] = 1;
                int n = in; n -= 48;    // 要改善（char → int）
                --n;
                // printf("%d %d %d\n", n, i, j);
                N_coor[n].first = i; N_coor[n].second = j;
            } 
        }
    }
    int sum = 0;
    rep(i,N){
        if(i != 0) s = N_coor[i-1];
        P g = N_coor[i];
        int dist[H][W];
        rep(j,H) rep(k,W) dist[j][k] = -1;
        queue<P> q;
        q.push(s);
        dist[s.first][s.second] = 0;
        while(!q.empty()){
            P u = q.front(); q.pop();
            rep(j,4){
                P v = make_pair(u.first+dx[j], u.second+dy[j]);
                if(v.first>=0 && v.first<H && v.second>=0 && v.second<W){
                    if(dist[v.first][v.second] == -1 && c[v.first][v.second] == 1){
                        dist[v.first][v.second] = dist[u.first][u.second]+1;
                        q.push(v);
                    }
                }
            }
        }
        sum += dist[g.first][g.second];
    }
    cout << sum << endl;
}