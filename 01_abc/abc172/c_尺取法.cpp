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
    int n, m, k; cin >> n >> m >> k;
    vector<int> A(n);
    vector<int> B(m);
    rep(i,n) cin >> A[i];
    rep(i,m) cin >> B[i];
    // 本棚Bにある本の読書分の合計を計算する
    ll t = 0;
    rep(i,m) t += B[i];

    int j = m;
    int ans = 0;
    // n+1は、0冊〜n冊の合計n+1通りを考えるため
    rep(i,n+1){
        // j=0となるときは、すでにB[0]が合計時間から減らされたあと
        while(j > 0 && t > k){
            --j;
            t -= B[j];
        }
        if(t > k) break;
        ans = max(ans, i+j);    // i:number of A, j:number of B
        if(i == n) break;
        t += A[i];
    }
    cout << ans << endl;

}