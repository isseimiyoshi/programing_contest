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
*/

ll rtn_max(vector<ll> A, int b, int e){
    ll max_n = (-1)*pow(10,9);
    for(int i=b; i<e; i++){
        if(max_n < A[i]) max_n = A[i];
    }
    return max_n;
}

ll rtn_min(vector<ll> A, int b, int e){
    ll min_n = pow(10,9);
    for(int i=b; i<e; i++){
        if(min_n > A[i]) min_n = A[i];
    }
    return min_n;
}

int main()
{
    int n; cin >> n;
    vector<ll> A(n);
    rep(i,n){
        ll Ai; cin >> Ai;
        A[i] = Ai;
    }
    int q; cin >> q;
    rep(i,q){
        int query; cin >> query;
        if(query == 0){
            int b, e; cin >> b >> e;
            int minn = rtn_min(A, b, e);
            cout << minn << endl;
        }else if(query == 1){
            int b, e; cin >> b >> e;
            int maxn = rtn_max(A, b, e);
            cout << maxn << endl;
        }
    }
}