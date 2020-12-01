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

const int MAX = 100000;

int n, k;
ll T[MAX];

// 最大積載量Pのk台のトラックで何個の荷物を積めるか
int check(ll P){
    int i = 0;
    rep(j,k){
        ll s = 0;
        while(s + T[i] <= P){
            s += T[i];
            i++;    // iは積めた荷物の個数をカウントする変数
            if(i == n) return n;
        }
    }
    return i;
}

// 二分探索のアルゴリズムを用いて、
ll solve(){
    ll left = 0;
    ll right = 100000 * 10000;  // 荷物の個数　×　1個あたりの最大重量
    ll mid;
    while(right - left > 1){
        mid = (left + right) / 2;
        int v = check(mid);
        if(v >= n) right = mid;
        else left = mid;
    }
    return right;
}

int main()
{
    cin >> n >> k;    // 荷物の数n、トラックの数k
    rep(i,n) cin >> T[i];
    ll ans = solve();   // 写経するときはmain関数から、使用する関数が出現したときにその関数に移るというように実行順に書くと理解しやすい
    cout << ans << endl;
}