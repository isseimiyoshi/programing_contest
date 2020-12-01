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
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    sort(A.begin(), A.end());

    ll sum = 0;
    if(N % 2 == 1){
        rep(i,N/2) sum += A[N-1-i];
        rep(i,N/2) sum += A[N-2-i];
    }else{
        rep(i,N/2-1) sum += A[N-1-i];
        rep(i,N/2-1) sum += A[N-2-i];
        sum += A[N-N/2];
    }
    cout << sum << endl;
}