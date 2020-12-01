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
    int n; cin >> n;
    string s; cin >> s;

    map<char, set<int> > m;
    rep(i,n) m[s[i]].insert(i);


    int q; cin >> q;
    rep(_,q){
        int que; cin >> que;
        if(que == 1){
            int i; char c; cin >> i >> c;
            --i;
            m[s[i]].erase(i);
            s[i] = c;
            m[c].insert(i);
        }else{
            int l, r; cin >> l >> r;
            --l, --r;
            int cnt = 0;
            for(char moji='a'; moji<='z'; moji++){
                if(!m[moji].empty()){
                    auto it = m[moji].lower_bound(l);
                    if(it != m[moji].end() && *it <= r) ++cnt;
                }
            }
            cout << cnt << endl;
        }
    }
}