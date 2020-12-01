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
    int d, n, m; cin >> d >> n >> m;
    vector<int> dv(n);
    dv[0] = 0;   // 本店の座標は常にゼロ
    rep(i,n-1) cin >> dv[i+1];   // 本店以外の座標を入れる
    sort(dv.begin(), dv.end());
    int sum = 0;
    rep(_,m){
        int k; cin >> k;
        int up = *lower_bound(dv.begin(), dv.end(), k);
        // cout << up;
        int lw = *(--lower_bound(dv.begin(), dv.end(), k));
        // cout << lw << endl;
        if(lw == dv[n-1]) sum += min(k-lw, d-k);
        else sum += min(k-lw, up-k);
    }
    cout << sum << endl;
}