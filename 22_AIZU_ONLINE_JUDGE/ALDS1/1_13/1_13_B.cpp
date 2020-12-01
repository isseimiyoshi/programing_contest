#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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
*/
static const int N = 3, N2 = 9;

struct Puzzle {
    int f[N2];
    int space;
    string path;
    
    // 自作した構造体用にオペランド演算子をオーバーロードしている
    // このプログラムでは、mapにPuzzleを用いているのでこれをする必要性が生じる
    bool operator < ( const Puzzle &p ) const {
        rep(i, N2){
            if(f[i] == p.f[i]) continue;
            return f[i] > p.f[i];
        }
        return false;
    }
    
};

static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char dir[4] = {'u', 'l', 'd', 'r'};

bool isTarget(Puzzle p){
    rep(i,N2){
        if(p.f[i] != i+1) return false;
    }
    return true;
}

string bfs(Puzzle s){
    queue<Puzzle> Q;
    map<Puzzle, bool> V;    // 自作した構造体に関するmapを定義
    Puzzle u, v;
    s.path = "";
    Q.push(s);
    V[s] = true;

    while(!Q.empty()){
        u = Q.front(); Q.pop();
        // もしパズルuがターゲットと合致していれば
        if(isTarget(u)) return u.path;
        int sx = u.space / N;   // space x
        int sy = u.space % N;   // space y
        rep(r, 4){
            int tx = sx + dx[r];    // transfer x
            int ty = sy + dy[r];    // transfer y
            if(tx<0 || ty<0 || tx>=N || ty>=N) continue;    // 移動先がパズルの枠を超えてしまわないようにする
            v = u;
            swap(v.f[u.space], v.f[tx*N + ty]);
            v.space = tx*N + ty;    // spaceの位置も移動
            if( !V[v] ){    // 既に同じ配置のパズルを動かし済みの場合はスルーする
                V[v] = true;
                v.path += dir[r];
                Q.push(v);
            }
        }
    }
    return "unsolvable";
}


int main()
{
    Puzzle in;

    rep(i,N2){
        cin >> in.f[i];
        if(in.f[i] == 0){
            in.f[i] = N2;   // set space
            in.space = i;
        }
    }
    string ans = bfs(in);
    cout << ans.size() << endl;
    // cout << ans << endl;
    return 0;
}