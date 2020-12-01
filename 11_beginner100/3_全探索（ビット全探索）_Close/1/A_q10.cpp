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

const int MAX_N = 20;

int main()
{
    int n; cin >> n;
    int A[n];
    rep(i,n) cin >> A[i];
    int q; cin >> q;
    rep(i,q){
        int m; cin >> m;
        bool isOK = false;
        for(int tmp = 0; tmp < (1 << n); tmp++){
            bitset<MAX_N> B(tmp);
            // cout << B << endl;
            int sum = 0;
            rep(k,n){
                if(B.test(k)) sum += A[k];
            }
            if(sum == m){
                isOK = true;
                break;
            }
        }
        if(isOK) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}