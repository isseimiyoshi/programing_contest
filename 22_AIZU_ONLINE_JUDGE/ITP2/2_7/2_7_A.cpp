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
    // multisetは重複を許し、set内の要素を平衡二分木の構造で昇順に並び替えている
    multiset<int> S;
    rep(i,q){
        int query; cin >> query;
        if(query == 0){
            int x; cin >> x;
            S.insert(x);
            cout << S.size() << endl;
        }else if(query == 1){
            int x; cin >> x;
            cout << S.count(x) << endl;
        }else if(query == 2){
            int x; cin >> x;
            S.erase(x);
        }else if(query == 3){
            int L,R; cin >> L >> R;
            auto it = S.lower_bound(L);
			while (it != S.end() && *it <= R) {
				printf("%d\n", *it); ++it;
			}
        }
        
    }
}