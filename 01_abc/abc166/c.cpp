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
    vector<int> H(N);
    rep(i,N) cin >> H[i]; 
    vector<int> to[N];
    rep(i,M){
        int A, B; cin >> A >> B;
        A--; B--;
        to[A].push_back(B);
        to[B].push_back(A);
    }
    int cnt = 0;
    rep(i,N){
        bool isGood = true;
        for(int u: to[i]){
            if(H[i] <= H[u]) isGood = false;
        }
        if(isGood) cnt++; 
    }
    cout << cnt << endl;
}