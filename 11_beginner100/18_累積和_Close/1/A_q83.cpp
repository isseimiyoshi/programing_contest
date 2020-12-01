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
    int N, M; cin >> N >> M;
    ll G[N], T[M];
    rep(i,M) cin >> T[i];
    rep(i,N) G[i] = 0;
    int A[N-1], B[N-1], C[N-1];
    rep(i,N-1) cin >> A[i] >> B[i] >> C[i];
    // いもす法を行うためのデータ構造を作成する
    // rep(i,M) cout << T[i] << endl;
    for(int i=1; i<M; i++){
        int Pto = T[i]; Pto--;
        int Pfrom = T[i-1]; Pfrom--;
        if(Pfrom > Pto) swap(Pto, Pfrom);
        G[Pfrom]++; G[Pto]--;
    }
    
    ll sum_cost = 0;
    for(int i=1; i<N-1; i++){
        if(i == 1){
            if(G[0]*A[0] > G[0]*B[0]+C[0]) sum_cost += G[0]*B[0]+C[0];
            else sum_cost += G[0]*A[0];
        }
        G[i] += G[i-1];
        if(G[i]*A[i] > G[i]*B[i]+C[i]) sum_cost += G[i]*B[i]+C[i];
        else sum_cost += G[i]*A[i];
    }
    
    cout << sum_cost << endl;
}