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
    int64_t N, K;
    cin >> N >> K;
    int64_t a[N];
    vector<int64_t> s(N);
    rep(i,N) cin >> a[i];
    rep(i,N){
        if(i == 0){
            s[0] = a[0];
            continue;
        }
        s[i] = s[i-1]+a[i];
    }
    ll cnt = 0;
    rep(i,N){
        if(i == 0){
            auto itr = lower_bound(s.begin(), s.end(), K);
            cnt += (N - distance(s.begin(), itr));
        }else{
            auto itr = lower_bound(s.begin(), s.end(), K+s[i-1]);
            cnt += (N - distance(s.begin(), itr));
        }
    }
    cout << cnt << endl;
}