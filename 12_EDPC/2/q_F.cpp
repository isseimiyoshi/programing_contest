#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

class SegmentTree{
    int n;  // セグメント木の配列数を定義するための数値
    vector<ll> node;   // セグメント木の各値を格納するための配列

public:
    SegmentTree(vector<ll> a){
        int n_ = a.size();  // 引数の配列のサイズ
        
        n = 1;
        while(n<n_) n *= 2;

        node.resize(2*n-1, 0);  // 初期ツリー構造（初期値ゼロ）

        rep(i,n_) node[n-1+i] = a[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    ll RMQ(int a, int b, int k=0, int l=0, int r=0){
        if(l>=r) r = n;
        if(r<=a || b<=l) return 0;  // 範囲外
        if(a<=l && r<=b) return node[k];

        ll vl = RMQ(a, b, 2*k+1, l, (l+r)/2);
        ll vr = RMQ(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }

    void setvalue(int i, ll x){
        int k = n-1+i;
        node[k] = x;

        while(true){
            k = (k-1)/2;
            node[k] = max(node[2*k+1], node[2*k+2]);
            if(k == 0) break;
        }
    }
};

int main()
{
    int n; cin >> n;

    int max_h = 0; int h[n];
    rep(i,n){
        cin >> h[i];
        max_h = max(max_h, h[i]);
    }
    vector<ll> mh(max_h+1);
    rep(i,max_h+1) mh[i] = 0;

    ll a[n];
    rep(i,n) cin >> a[i];

    SegmentTree seg = SegmentTree(mh);

    rep(i,n){
        ll temp = seg.RMQ(0,h[i]);
        // cout << temp+a[i] << endl;
        seg.setvalue(h[i], temp+a[i]);
    }

    cout << seg.RMQ(0,max_h+1) << endl;
}