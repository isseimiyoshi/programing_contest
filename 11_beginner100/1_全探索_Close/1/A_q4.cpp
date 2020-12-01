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

const int MAX_N = 105, MAX_M = 105;

int main()
{
    int N, M; cin >> N >> M;
    int A[N][M];
    rep(i,N) rep(j,M) cin >> A[i][j];
    ll max_sum = 0;
    rep(i,M){
        for(int j=i+1; j<M; j++){
            ll sum = 0;
            rep(k,N){
                sum += max(A[k][i], A[k][j]);
            }
            if(max_sum < sum) max_sum = sum;
        }
    }
    cout << max_sum << endl;
}