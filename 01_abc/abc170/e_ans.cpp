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
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    
    vector<multiset<int>> s(200005);    // 各幼稚園にいる園児のレートを格納する（multisetは平衡二分探索木である）
    multiset<int> maxs;                 // 各幼稚園の最強園児レートを格納する

    // ここからラムダ式の関数を定義していく
    // 幼稚園番号iに所属している園児のうち最強園児のレートを取得する
    auto getMax = [&](int i){
        if(s[i].size() == 0) return -1;
        return *s[i].rbegin();
    };
    // 幼稚園iの最強園児のレートを各幼稚園最強レートを格納しているmultisetに追加する
    auto addYochien = [&](int i){
        int x = getMax(i);
        if(x == -1) return;
        maxs.insert(x);
    };
    auto delYochien = [&](int i){
        int x = getMax(i);
        if(x == -1) return;
        maxs.erase(maxs.find(x));   // 引数にxを入れてしまうと、multiset内にある要素xのものがすべて削除されてしまう
    };
    auto addEnji = [&](int i, int x){
        delYochien(i);
        s[i].insert(x);
        addYochien(i);
    };
    auto delEnji = [&](int i, int x){
        delYochien(i);
        s[i].erase(s[i].find(x));
        addYochien(i);
    };

    rep(i,n){
        cin >> a[i] >> b[i];
        addEnji(b[i], a[i]);
    }

    rep(i,q){
        int c, d; cin >> c >> d;
        --c;
        delEnji(b[c], a[c]);
        b[c] = d;
        addEnji(b[c], a[c]);
        int ans = *maxs.begin();
        printf("%d\n", ans);
    }

    return 0;
}