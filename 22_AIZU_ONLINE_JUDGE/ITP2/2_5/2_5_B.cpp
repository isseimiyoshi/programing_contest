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

int main()
{
    int n; cin >> n;
    vector<tuple<int, int, char, ll, string> > Item;
    rep(i,n){
        int v, w; char t; string s;
        ll d;
        cin >> v >> w >> t >> d >> s;
        Item.push_back(make_tuple(v, w, t, d, s));
    }
    sort(Item.begin(), Item.end());
    rep(i,n){
        int v, w; char t; string s;
        ll d;
        tie(v, w, t, d, s) = Item[i];
        printf("%d %d %c %ld ", v, w, t, d);
        cout << s << endl;
    }
}