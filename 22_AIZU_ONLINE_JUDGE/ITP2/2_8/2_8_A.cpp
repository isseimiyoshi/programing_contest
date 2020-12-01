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
    int q; cin >> q;
    multimap<string, int> M;
    rep(i,q){
        int query; cin >> query;
        if(query == 0){
            string key; int x;
            cin >> key >> x;
            M.insert(make_pair(key, x));
        }else if(query == 1){
            string key; cin >> key;
            auto itr = M.find(key);
            while((*itr).first == key){
                cout << (*itr).second << endl;
                itr++;
            }
        }else if(query == 2){
            string key; cin >> key;
            M.erase(key);
        }else if(query == 3){
            string L, R; cin >> L >> R;
            auto itr = M.lower_bound(L);
            while(itr != M.end() && (*itr).first <= R){
                if((*itr).second != 0) cout << (*itr).first << " " << (*itr).second << endl;
                itr++;
            }
        }
    }
}