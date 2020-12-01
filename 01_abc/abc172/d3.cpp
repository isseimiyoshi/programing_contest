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
    vector<ll> f(N+1);
    f[0] = 0;
    f[1] = 1;
    // 2の倍数と3の倍数だけは最初に記録しておく
    for(int i=2; i<=N; i++){
        f[i] = 1;
        if(i % 2 == 0) ++f[i];
        if(i % 3 == 0) ++f[i];
    }
    // それぞれの約数の個数を配列に記録していく
    for(int i=4; i<=N; i++){
        ++f[i];
        int j = 2;
        while(true){
            if(i * j <= N){
                ++f[i*j];
                ++j;
            }else{
                break;
            }
        }
    }
    ll sum = 0;
    for(ll i=1; i<=N; i++) sum += i*f[i];
    cout << sum << endl;
}