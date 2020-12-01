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

const int MAX_N = 200200;

int main()
{
    int N; cin >> N;
    map<int, int> m;
    set<int> s;
    vector<int> A;

    // 初期化
    rep(i,MAX_N){
        m[i] = 0;
    }

    rep(i,N){
        int Ai; cin >> Ai;
        
        m[Ai]++;

        s.insert(Ai);

        A.push_back(Ai);
    }

    ll goukei = 0;
    for(int si: s){
        // cout << m[si]*(m[si]-1)/2 << endl;
        goukei += (m[si]*(m[si]-1))/2;
    }

    rep(k,N){
        ll ans = goukei;
        ans -= m[A[k]]*(m[A[k]]-1)/2;
        ans += (m[A[k]]-2)*(m[A[k]]-1)/2;
        cout << ans << endl;
    }
}