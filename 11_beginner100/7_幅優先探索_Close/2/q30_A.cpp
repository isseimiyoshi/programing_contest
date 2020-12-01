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

int tox[4] = {0, 1, 0, -1};
int toy[4] = {-1, 0, 1, 0};

int main()
{
    int h, w, n; cin >> h >> w >> n;

    vector<P> pur(n+1);
    int c[h][w];

    rep(i,h){
        rep(j,w){
            char moji; cin >> moji;
            if(moji == 'X') c[i][j] = 0;
            else{
                c[i][j] = 1;
                if(moji == 'S') pur[0] = make_pair(i, j);
                else if(moji == '.') continue;
                else{
                    int imoji; imoji = moji - '0';
                    pur[imoji] = make_pair(i, j);
                }
            }
        }
    }
    // rep(i,n+1) cout << pur[i].first << " " << pur[i].second << endl;
    ll ans = 0;
    rep(i,n){
        int sh = pur[i].first; int sw = pur[i].second;
        int gh = pur[i+1].first; int gw = pur[i+1].second;

        int distance[h][w];
        rep(j,h) rep(k,w) distance[j][k] = INF;
        
        distance[sh][sw] = 0;
        queue<P> q;
        q.push(make_pair(sh, sw));

        while(!q.empty()){
            P u = q.front(); q.pop();
            rep(j,4){
                int h2 = u.first + toy[j]; int w2 = u.second + tox[j];
                if(h2<0 || h2>=h || w2<0 || w2>=w) continue;
                if(distance[h2][w2] == INF && c[h2][w2] == 1){
                    distance[h2][w2] = distance[u.first][u.second]+1;
                    q.push(make_pair(h2, w2));
                }
            }
        }
        ans += distance[gh][gw];
    }
    cout << ans << endl;
}