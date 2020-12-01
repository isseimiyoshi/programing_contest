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

const int MAX_M = 100, MAX_N = 100;

int tox[4] = {0, 1, 0, -1};
int toy[4] = {-1, 0, 1, 0};

int m, n;
int mass[MAX_M][MAX_N];

int ans = -1;

void init(){
    rep(i,MAX_N){
        rep(j,MAX_M){
            mass[i][j] = -1;
        }
    }
}

void dfs(int x, int y, int cnt){
    mass[x][y] = 0;
    rep(i,4){
        int x2 = x + tox[i]; int y2 = y + toy[i];
        if(x2 >= m || x2 < 0 || y2 >= n || y2 < 0) continue;
        if(mass[x2][y2] == 1) dfs(x2, y2, cnt+1);
    }
    ans = max(ans, cnt);
    mass[x][y] = 1;
}

int main()
{
    cin >> m >> n;
    rep(i,n) rep(j,m) cin >> mass[i][j];

    rep(i,n) rep(j,m){
        if(mass[i][j] == 1) dfs(i, j, 1);
    }

    cout << ans << endl;
}