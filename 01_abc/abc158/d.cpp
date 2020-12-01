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
    string s; cin >> s;
    int q; cin >> q;

    vector<tuple<int, char, int> > fc;

    int rev = 0;

    rep(_,q){
        int t; cin >> t;
        if(t == 1) rev++;
        else{
            int fi; char ci;
            cin >> fi >> ci;
            fc.push_back(make_tuple(fi, ci, rev));
        }
    }

    if(rev%2 == 1) reverse(s.begin(), s.end());

    string fronts = "";
    for(auto f: fc){
        int fi; char ci; int revi;
        tie(fi, ci, revi) = f;
        if((rev-revi)%2 == 1){
            if(fi == 1) fi = 2;
            else fi = 1;
        }
        if(fi == 1) fronts += ci;
        else s += ci;

        //cout << fi << " " << ci << " " << revi << endl;
    }
    reverse(fronts.begin(), fronts.end());
    // rep(i,fronts.size()) cout << fronts[i] << endl;

    rep(i,s.size()){
        fronts += s[i];
    }
    cout << fronts << endl;
}