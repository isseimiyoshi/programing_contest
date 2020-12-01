#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

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

const int MOD = 1000000007;


int main()
{
    int n; cin >> n;
    int a[n];
    int maxa = -1;
    rep(i,n){
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }

    int num[maxa+1];
    rep(i,maxa+1) num[i] = 0;
    num[0] = 3; // 最初は三色の帽子がどれも使われていない

    ll res = 1;
    rep(i,n){
        if(num[a[i]] == 0){
            res = 0;
            break;
        }
        res *= num[a[i]];
        res %= MOD;
        num[a[i]+1]++;
        num[a[i]]--;
    }
    cout << res << endl;
}