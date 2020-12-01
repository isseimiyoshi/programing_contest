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

const int MAX_N = 200100;

int P[65][MAX_N];   // 10**18 == 2*60だから

int main()
{
    ll N, K; cin >> N >> K;
    int A[N];
    rep(i,N){
        cin >> A[i];
        A[i]--;
    }
    rep(i,65){
        if(i == 0){
            rep(j,N) P[i][j] = A[j];
        }else{
            rep(j,N) P[i][j] = P[i-1][P[i-1][j]];
        }
    }
    bitset<65> Kbit(K);
    int cur = 0;
    for(int i=64; i>=0; i--){
        if(Kbit.test(i)){
            cur = P[i][cur];
        }
    }
    cur++;
    cout << cur << endl;
}