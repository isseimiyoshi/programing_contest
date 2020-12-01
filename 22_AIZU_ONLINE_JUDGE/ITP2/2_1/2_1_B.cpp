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
    int q; cin >> q;
    deque<int> deq;
    rep(i,q){
        int query; cin >> query;
        if(query == 0){
            int d; cin >> d;
            if(d == 0){
                int x; cin >> x;
                deq.push_front(x);
            }else if(d == 1){
                int x; cin >> x;
                deq.push_back(x);
            }
        }else if(query == 1){
            int p; cin >> p;
            // デキューでも、あるインデックスの要素を取り出す操作が可能
            cout << deq[p] << endl;
        }else if(query == 2){
            int d; cin >> d;
            if(d == 0) deq.pop_front();
            else deq.pop_back();
        }
    }
}