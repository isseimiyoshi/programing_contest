#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

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
    int H, W, M; cin >> H >> W >> M;
    int h[M], w[M];
    rep(i,M){
        cin >> h[i] >> w[i];
        --h[i], --w[i];
    }

    int nh[H];
    int nw[W];
    rep(i,H) nh[i] = 0;
    rep(i,W) nw[i] = 0;
    rep(i,M){
        nh[h[i]]++;
        nw[w[i]]++;
    }

    sort(nh, nh+H);
    sort(nw, nw+W);

    int maxh = nh[H-1];
    int maxw = nw[W-1];

    set<int> hset;
    set<int> wset;
    rep(i,H) if(nh[i] == maxh) hset.insert(h[i]);
    rep(i,W) if(nw[i] == maxw) wset.insert(w[i]);

    /*
    cout << maxh << endl;
    cout << maxw << endl;
    
    for(int th: hset){
        for(int tw: wset){
            printf("%d %d\n", th, tw);
        }
    }
    */

    int cnt = 0;
    rep(i,M){
        if(hset.count(h[i]) && wset.count(w[i])){
            cnt++;
        }
    }
    int judge = (int)hset.size() * (int)wset.size();
    int res = maxh + maxw;

    // cout << cnt << endl;
    if(cnt >= judge) cout << res -1 << endl;
    else cout << res << endl;
}