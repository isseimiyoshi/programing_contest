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
    int n; cin >> n;
    int G[1000002];
    rep(i,1000002) G[i] = 0;
    rep(_,n){
        int ai, bi; cin >> ai >> bi;
        G[ai]++;
        G[bi+1]--;
    }
    for(int i=1; i<=1000000; i++){
        G[i] += G[i-1];
    }
    int max_g = 0;
    rep(i,1000001){
        if(max_g < G[i]) max_g = G[i];
    }
    cout << max_g << endl;
}