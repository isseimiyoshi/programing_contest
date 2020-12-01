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
    int n, q; cin >> n >> q;
    queue<pair<string, int>> RR;
    rep(i,n){
        string name; int time;
        cin >> name >> time;
        RR.push(make_pair(name, time));
    }
    int sum = 0;
    while(!RR.empty()){
        auto task = RR.front(); RR.pop();
        if(task.second <= q){
            sum += task.second;
            cout << task.first << " " << sum << endl;
        }else{
            sum += q;
            RR.push(make_pair(task.first, task.second-q));
        }
    }
}