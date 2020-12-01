#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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

int m, n;
int mass[MAX_N][MAX_M];

const int dn[4] = {-1, 0, 1, 0};
const int dm[4] = {0, 1, 0, -1};

int ans = -1;

void dfs(int sn, int sm, int d){
    mass[sn][sm] = 0;
    rep(i,4){
        int nn = sn + dn[i], nm = sm + dm[i];
        if(nn >= n || nn < 0 || nm >= m || nm < 0) continue;
        if(mass[nn][nm] == 1){
            dfs(nn, nm, d+1);
        }
    }
    mass[sn][sm] = 1;
    ans = max(ans, d);
}

int main()
{
    cin >> m >> n;
    rep(i,n){
        rep(j,m) cin >> mass[i][j];
    }

    rep(i,n){
        rep(j,m){
            if(mass[i][j] == 1){
                dfs(i,j,0);
            }
        }
    }
    cout << ans+1 << endl;
}