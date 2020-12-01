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
    vector<pair<int, int> > Act;
    rep(i,n){
        int ft, st; cin >> st >> ft;
        Act.push_back(make_pair(ft, st));
    }
    sort(Act.begin(), Act.end());
    queue<pair<int, int> > qAct;
    rep(i,n) qAct.push(Act[i]);

    int sum = 0;
    pair<int, int> act = qAct.front(); qAct.pop(); sum += 1;
    int ori_ft = act.first;
    while(!qAct.empty()){
        pair<int,int> action = qAct.front(); qAct.pop();
        if(action.second > ori_ft){
            sum += 1;
            ori_ft = action.first;
        }
    }
    cout << sum << endl;
}
