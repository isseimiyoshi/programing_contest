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

const int MAX_V = 105;
const ll INF = 10001001000;

ll d[MAX_V][MAX_V];

int main()
{
    int V, E; cin >> V >> E;
    rep(i,MAX_V) rep(j,MAX_V) d[i][j] = ((i == j) ? 0 : INF);
    rep(_,E){
        int s, t, h; cin >> s >> t >> h;
        d[s][t] = h;
    }

    rep(k,V){
        rep(i,V){
            if(d[i][k] == INF) continue;
            rep(j,V) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        }
    }

    bool isNegative = false;
    rep(i,V) if(d[i][i] < 0) isNegative = true;

    if(isNegative) cout << "NEGATIVE CYCLE" << endl;
    else{
        rep(i,V){
            rep(j,V){
                if(d[i][j] > (INF - pow(10,9))) cout << "INF";
                else cout << d[i][j];
                if(j != V-1) cout << " ";
            }
            cout << endl;
        }
    }
}