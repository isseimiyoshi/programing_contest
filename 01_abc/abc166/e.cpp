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
    vector<int> B(N);
    rep(i,N){
        int Ai; cin >> Ai;
        A[i] = i+1 + Ai;
        B[i] = i+1 - Ai;
    }
    sort(B.begin(), B.end());   // クイックソート、不安定
    int cnt = 0;
    rep(i,N){
        cnt += upper_bound(B.begin(), B.end(), A[i]) - lower_bound(B.begin(), B.end(), A[i]);
    }
    cout << cnt << endl;
    return 0;
}