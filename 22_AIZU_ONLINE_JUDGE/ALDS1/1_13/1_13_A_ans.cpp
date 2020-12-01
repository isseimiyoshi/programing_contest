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

static const int N = 8;
static const int FREE = 1, NOT_FREE = 0;

int row[N], col[N], dpos[2*N-1], dneg[2*N-1];
bool X[N][N];   // 初期クイーン配置を記録しておく

void initialize(){
    rep(i,N) row[i] = col[i] = FREE;
    rep(i,2*N-1) dpos[i] = dneg[i] = FREE;
}

// クイーン配置全パターンのうち、初期配置に合致した場合（この場合は必ず1つ）に出力する
void printBorad(){
    rep(i,N) rep(j,N) if(X[i][j]) if(row[i] != j) return;
    rep(i,N){
        rep(j,N) cout << (row[i] == j ? "Q":".");
        cout << endl;
    }
}

// この関数によってクイーン配置全パターンを試す
void recursive(int i){
    if(i == 8){
        printBorad(); return;
    }
    rep(j,N){
        if(col[j] == NOT_FREE || dpos[i+j] == NOT_FREE || dneg[i-j+(N-1)] == NOT_FREE) continue;
        // i,jにクイーンを配置する
        row[i] = j; col[j] = dpos[i+j] = dneg[i-j+(N-1)] = NOT_FREE;
        // 次の行を試す
        recursive(i+1);
        // (i, j)に配置されているクイーンを取り除く
        row[i] = col[j] = dpos[i+j] = dneg[i-j+(N-1)] = FREE;
    }
    // クイーンの配置に失敗した処理を書く
}

int main()
{
    initialize();

    int n; cin >> n;
    rep(i,n){
        int r, c; cin >> r >> c;
        X[r][c] = true;
    }

    recursive(0);

    return 0;
}