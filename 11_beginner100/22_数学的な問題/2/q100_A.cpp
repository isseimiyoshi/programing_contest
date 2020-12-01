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


int main()
{
    int n; cin >> n;


    pair<bool, ll> isok[n+1];
    rep(i,n+1) isok[i] = make_pair(false, -1);
    int c = 1;
    isok[c] = make_pair(true, c+1);
    while(c*(c+1)/2 <= n){
        isok[c*(c+1)/2] = make_pair(true, c+1);
        c++;
    }

    if(isok[n].first){
        cout << "Yes" << endl;
        int k = isok[n].second;
        cout << k << endl;

        int res[c][c-1];
        rep(i,c) rep(j,c-1) res[i][j] = 0;

        int cross = 0;
        int i = 0;
        int cnt = 1;
        while(cnt <= n){
            res[cross+i+1][cross] = cnt;
            res[cross][cross+i] = cnt;
            cnt++;
            if(cross+i+1 == c-1){
                cross++;
                i = 0;
            }else{
                i++;
            }
        }

        rep(i,c){
            cout << c-1 << " ";
            rep(j,c-1){
                cout << res[i][j];
                if(j != c-2) cout << " ";
            }cout << endl;
        }

    }else{
        cout << "No" << endl;
    }

}