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
    int v, e; cin >> v >> e;
    ll m[v][v];
    rep(i,v){
        rep(j,v){
            if(i == j) m[i][j] = 0;
            else m[i][j] = INF;
        }
    }
    rep(i,e){
        int s, t, d; cin >> s >> t >> d;
        m[s][t] = d;
    }

    rep(k,v){
        rep(i,v){
            if(m[i][k] == INF) continue;    // i k間の経路が存在しない場合は処理を飛ばす
            rep(j,v){
                if(m[k][j] == INF) continue;
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
            }
        }
    }
    bool isnegative = false;
    rep(i,v){
        if(m[i][i] < 0) isnegative = true;
    }
    if(isnegative) cout << "NEGATIVE CYCLE" << endl;
    else{
        rep(i,v){
            rep(j,v){
                if(m[i][j] == INF) cout << "INF";
                else cout << m[i][j];
                if(j != v-1) cout << " ";
            }cout << endl;
        }
    }
}