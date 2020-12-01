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


const int MAX_N = 1 << 17;

// [1,n]
int bit[MAX_N+1], n;

int sum(int i){
    int s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i;   // iの最後の1ビットを引いている
    }
    return s;
}

void add(int i, int x){
    while(i<=n){
        bit[i] += x;
        i += i & -i;
    }
}

int main()
{
    cin >> n;
    int q; cin >> q;
    rep(_,q){
        int com; cin >> com;
        if(com == 0){
            int x, y; cin >> x >> y;
            add(x, y);
        }else if(com == 1){
            int x, y; cin >> x >> y;
            cout << sum(y) - sum(x-1) << endl;
        }
    }
}