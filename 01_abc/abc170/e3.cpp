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
    int N, Q; cin >> N >> Q;
    int a[N], b[N];
    vector<multiset<int> > s(200005);
    multiset<int> maxs;
    rep(i,N){
        int ai, bi; cin >> ai >> bi;
        a[i] = ai; b[i] = bi;
        s[bi].insert(ai);
    }
    rep(i,200005){
        if(s[i].size() == 0) continue;
        maxs.insert(*s[i].rbegin());
    }
    cout << "ok" << endl;
    rep(_,Q){
        int c, d; cin >> c >> d;
        --c;
        // maxsからその幼稚園の最強レートを削除し、その幼児をもともといた幼稚園から削除する
        cout << "phase1" << endl;
        maxs.erase(maxs.find(*s[b[c]].rbegin()));
        s[b[c]].erase(s[b[c]].find(a[c]));
        // 幼児が元いた幼稚園の最強レートを修正し、maxsに追加する
        cout << "phase2" << endl;
        maxs.insert(*s[b[c]].rbegin());
        // maxsから園児の移動先の幼稚園の最強レートを削除し、幼児を転園先に追加する
        cout << "phase3" << endl;
        b[c] = d;
        maxs.erase(maxs.find(*s[b[c]].rbegin()));
        s[b[c]].insert(a[c]);
        // 幼児が転園した幼稚園の最強レートを修正し、maxsに追加する
        cout << "phase4" << endl;
        maxs.insert(*s[b[c]].rbegin());
        // maxsのうちの最小値を出力する
        int ans = *maxs.begin();
        printf("%d\n", ans);
    }
}   