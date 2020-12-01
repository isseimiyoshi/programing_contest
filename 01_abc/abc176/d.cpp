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
const int MAX_H = 1010, MAX_W = 1010;


int dis[MAX_H][MAX_W];
int c[MAX_H][MAX_W];
int h, w; 

int tow[4] = {0, 1, 0, -1};
int toh[4] = {-1, 0, 1, 0};

void init(){
    rep(i,MAX_H){
        rep(j,MAX_W){
            dis[i][j] = INF;
            c[i][j] = 0;
        }
    }
}

int main()
{
    init();
    cin >> h >> w;
    int ch, cw, dh, dw; cin >> ch >> cw >> dh >> dw; --ch, --cw, --dh, --dw;
    rep(i,h){
        rep(j,w){
            char moji; cin >> moji;
            if(moji == '#') c[i][j] = 0;
            else c[i][j] = 1;
        }
    }

    int cnt = 0;

    queue<P> q;
    q.push(make_pair(ch, cw));
    dis[ch][cw] = 0;

    while(true){
        vector<P> re;
        while(!q.empty()){
            P pair_u = q.front(); q.pop();
            int uh = pair_u.first, uw = pair_u.second;
            dis[uh][uw] = cnt;
            re.push_back(make_pair(uh, uw));
            rep(i,4){
                int vh = uh + toh[i], vw = uw + tow[i];
                if(vh<0 || vw<0 || vh>=h || vw>=w) continue;
                if(dis[vh][vw] == INF && c[vh][vw] == 1){
                    dis[vh][vw] = cnt;
                    q.push(make_pair(vh, vw));
                }
            }
        }
        int rs = re.size();
        bool isok = true;
        rep(i,rs){
            P pair_u = re[i];
            int uh = re[i].first, uw = re[i].second;
            for(int ii=-2; ii<=2; ii++){
                for(int jj=-2; jj<=2; jj++){
                    int nh = uh + ii, nw = uw + jj;
                    if(nh<0 || nw<0 || nh>=h || nw>=w) continue;
                    if(dis[nh][nw] == INF && c[nh][nw] == 1){
                        q.push(make_pair(nh, nw));
                        // printf("%d %d\n", nh, nw);
                        isok = false;
                    }
                }
            }
        }
        if(isok) break;
        cnt++;
    }
    if(dis[dh][dw] == INF) cout << -1 << endl;
    else cout << dis[dh][dw] << endl;
}