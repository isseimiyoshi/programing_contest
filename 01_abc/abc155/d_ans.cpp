#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const ll INF = ll(1e18)+1;

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
    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    /*
    k番目の数字としてあり得るものを二分探索で求める
    
    ある数字未満の配列同士の組み合わせの個数がk個未満の場合
    　leftを中間地点にすすめる
    ある数字未満の配列同士の組み合わせの個数がk個以上の場合
    　rightを中間地点まですすめる
    */

    // 二分探索をするときの初期値
    ll l = -INF, r = INF;
    // 二分探索開始
    while(l+1<r){
        ll x = (l+r)/2; // 中間位置
        // ラムダ式で関数にまとめる
        bool ok = [&]{  // [&] これをつけることで関数の外の変数にアクセス可能になる
            // x未満の数の個数を格納するための変数tot
            ll tot = 0;
            rep(i,n){
                if(a[i]<0){
                    int l=-1, r=n;
                    while(l+1<r){
                        int c = (l+r)/2;
                        if(a[c]*a[i]<x) r=c; else l=c;
                    }
                    tot += n-r;
                }else{
                    int l=-1, r=n;
                    // いま選択されている配列番号とのペアでどの番号まで、かけ合わせた数字がx未満として成立するかを求めている
                    while(l+1<r){
                        int c = (l+r)/2;
                        if(a[c]*a[i]<x) l=c; else r = c;
                    }
                    tot += r;
                }
                if(a[i]*a[i]<x) tot--;
            }
            tot /= 2;
            return tot<k;
        }();    // () 定義し終わったあとで関数呼び出しを行っているという意味

        if(ok) l=x; else r=x;
    }
    cout << l << endl;
    return 0;
}