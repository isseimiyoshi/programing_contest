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
    int N, K; cin >> N >> K;
    double prb = 0.0;
    for(int i=1; i<=N; i++){
        ll me = i;
        int coinn = 0;
        while(me < K){
            me *= 2;
            coinn++;
        }
        prb += pow(0.5, coinn) / N;
    }
    printf("%.10lf\n", prb);
}