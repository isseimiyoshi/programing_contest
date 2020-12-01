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
    int N; cin >> N;
    ll A[N];
    rep(i,N) cin >> A[i];
    ll S[N];
    rep(i,N){
        if(i == 0) S[i] = A[i];
        else S[i] = A[i] + S[i-1];
    }
    rep(i,N){
        int k = i+1;
        ll max_k = S[k-1];
        rep(j,N-k){
            if(max_k < (S[j+k] - S[j])) max_k = S[j+k] - S[j];
        }
        cout << max_k << endl;
    }
}