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

struct Node{
    int key;
    Node *parent, *left, *right;
}

Node *root, *NIL;

int main()
{
    string S; cin >> S;
    
    map<char, int> moji_cnt;
    rep(i,S.size()){
        if(!moji_cnt.count(S[i])) moji_cnt[S[i]] = count(S.cbegin(), S.cend(), S[i]);
    }
    map<int, char> cnt_moji;
    for(auto moji_cnt_f: moji_cnt){
        cnt_moji[moji_cnt_f.second] = moji_cnt_f.first;
    }
    // 順位キューを用意（最小値から出てくるようにしている）
    priority_queue<int, vector<int>, greater<int> >que;
    for(auto moji_cnt_f: moji_cnt) que.push(moji_cnt_f.second);

    int mi1 = que.top(); que.pop();
    int mi2 = que.top(); que.pop();
    while(!que.emtpy()){
        
    }
}