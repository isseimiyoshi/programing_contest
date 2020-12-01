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

int n, m, q;
vector<int> a, b, c, d;
int ans;

void dfs(vector<int> A){
    // A[0]は1で固定して増加させず使わないのでn+1になるまで
    if(A.size() == n+1){
        int now = 0;
        rep(i,q){
            if(A[b[i]] - A[a[i]] == c[i]) now += d[i];
        }
        if(ans < now) ans = now;
        return;
    }
    // A.back()はAの最後尾の数値
    A.push_back(A.back());
    while(A.back() <= m){
        dfs(A);
        A.back()++;
    }
}


int main()
{
    cin >> n >> m >> q;
    a = b = c = d = vector<int>(q); // この定義の仕方をしっかり覚える
    rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    dfs(vector<int>(1,1));
    cout << ans << endl;
    return 0;
}