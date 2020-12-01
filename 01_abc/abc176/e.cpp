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
    int H, W, M; cin >> H >> W >> M;
    int h[M], w[M];
    rep(i,M) cin >> h[i] >> w[i], --h[i], --w[i];

    int sumh[H];
    int sumw[W];
    rep(i,H) sumh[i] = 0;
    rep(i,W) sumw[i] = 0;
    rep(i,M){
        sumh[h[i]]++;
        sumw[w[i]]++;
    }
    
    vector<P> vh;
    vector<P> vw;
    rep(i,H) vh.push_back(make_pair(sumh[i], i));
    rep(i,W) vw.push_back(make_pair(sumw[i], i));

    //cout << "ok" << endl;
    sort(vh.begin(), vh.end());
    sort(vw.begin(), vw.end());
    //cout << "o2" << endl;

    ll hmax = vh[H-1].first;
    ll wmax = vw[W-1].first;
    //cout << "o3" << endl;

    set<int> hset;
    set<int> wset;
    
    rep(i,H) if(vh[i].first == hmax) hset.insert(vh[i].second);
    rep(i,W) if(vw[i].first == wmax) wset.insert(vw[i].second);

    ll res = hmax+wmax;

    /*
    for(auto hi: hset) cout << hi << " ";
    cout << endl;
    for(auto wi: wset) cout << wi << " ";
    cout << endl;
    */

    bool isok = false;
    rep(i,M){
        if(hset.count(h[i]) && wset.count(w[i])){
            continue;
        }else{
            isok = true;
        }
    }
    if(!isok) --res;
    cout << res << endl; 
    // cout << hmax << " " << wmax << endl;
    
}