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

int main()
{
    int N, M, Q; cin >> N >> M >> Q;
    int L[M], R[M];
    rep(i,M){
        int Li, Ri;
        cin >> Li >> Ri;
        L[i] = Li; R[i] = Ri;
    }
    int p[Q], q[Q];
    rep(i,Q){
        cin >> p[i] >> q[i];
    }
    int sum[N+1][N+1];
    rep(i,N+1) rep(j,N+1) sum[i][j] = 0;
    rep(i,M) sum[L[i]][R[i]]++;
    rep(i,N+1){
        rep(j,N+1){
            sum[i][j] += sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    rep(i,Q){
        int l = p[i], r = q[i];
        int ans = sum[r][r] - sum[r][l-1] - sum[l-1][r] + sum[l-1][l-1];
        cout << ans << endl;
    }
}