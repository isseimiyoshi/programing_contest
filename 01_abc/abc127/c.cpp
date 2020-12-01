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

const ll MAX_N = pow(10,6);

int main()
{
    int N, M; cin >> N >> M;
    int max_l = 0;
    int min_r = pow(10,6);
    rep(i,M){
        int L, R; cin >> L >> R;
        if(max_l < L) max_l = L;
        if(min_r > R) min_r = R;
    }
    if(min_r-max_l<0) cout << 0 << endl;
    else cout << min_r-max_l+1 << endl;
}