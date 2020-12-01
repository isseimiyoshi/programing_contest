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

int main()
{
    int n; cin >> n;
    vector<bitset<64> > M;
    rep(i,n){
        bitset<64> m(0);
        int k; cin >> k;
        rep(j,k){
            int b; cin >> b;
            m.set(b);
        }
        M.push_back(m);
    }
    bitset<64> A(0);
    int q; cin >> q;
    rep(_,q){
        int query; cin >> query;
        if(query == 0){
            int i; cin >> i;
            if(A.test(i)) cout << 1 << endl;
            else cout << 0 << endl;
        }else if(query == 1){
            int mn; cin >> mn;
            A |= M[mn];
        }else if(query == 2){
            int mn; cin >> mn;
            A = (A & M[mn]) ^ A;
        }else if(query == 3){
            int mn; cin >> mn;
            A ^= M[mn];
        }else if(query == 4){
            int mn; cin >> mn;
            if((A & M[mn]) == M[mn]) cout << 1 << endl;
            else cout << 0 << endl;
        }else if(query == 5){
            int mn; cin >> mn;
            if(!((A & M[mn]) == 0)) cout << 1 << endl;
            else cout << 0 << endl;
        }else if(query == 6){
            int mn; cin >> mn;
            if((A & M[mn]) == 0) cout << 1 << endl;
            else cout << 0 << endl;
        }else if(query == 7){
            int mn; cin >> mn;
            cout << (A & M[mn]).count() << endl;
        }else if(query == 8){
            int mn; cin >> mn;
            cout << ((A & M[mn]).to_ullong()) << endl;
        }
    }
}