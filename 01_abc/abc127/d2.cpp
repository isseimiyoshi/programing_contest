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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

int main()
{
    int N,M; cin >> N >> M;
    map<ll, ll> A;
    rep(i,N){
        int Ai; cin >> Ai;
        Ai *= -1;
        if(Ai) A[Ai]++;
        else A[Ai] = 1;
    }
    rep(i,M){
        int B, C; cin >> B >> C;
        C *= -1;
        if(A[C]) A[C] += B;
        else A[C] = B;
    }
    ll sum = 0;
    for(auto p: A){
        auto key = p.first;
        auto val = p.second;
        if(N >= val){
            sum += (-1)*key*val;
            N -= val;
        }
        else{
            sum += (-1)*key*N;
            break;
        }
    }
    cout << sum << endl;
}