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

const int LIM = 10000001;

int main()
{
    int N; cin >> N;
    vector<int> Div(LIM);
    rep(i,LIM) Div[i] = 0;
    Div[0] = 0;
    Div[1] = 1;
    for(int i=2; i<LIM; i++){
        int M = i;
        for(int j=2; j*j<=M; j++){
            if(M % j != 0) continue;
            if(M % j == 0){
                int ori_M = M;
                M /= j;
                Div[ori_M] = Div[M] + 1;
                M = 1;
                break;
            }
        }
        if(M != 1) Div[M] = 1;
    }
    ll ans = 0;
    for(int i=1; i<=N; i++){
        ans += i*Div[i];
    }
    cout << ans << endl;
}