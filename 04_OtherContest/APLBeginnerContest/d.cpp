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

struct SegmentTree{
    int n;
    vector<int> node;

    SegmentTree(vector<int> a){
        int n_ = a.size();

        n = 1;
        while(n<n_) n *= 2;

        node.resize(2*n-1, 0);
        rep(i,n_) node[n-1+i] = a[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    int RMQ(int a, int b, int k=0, int l=0, int r=0){
        if(l>=r) r = n;
        if(a>=r || b<=l) return 0;
        if(a<=l && r<=b) return node[k];

        int vl = RMQ(a, b, 2*k+1, l, (l+r)/2);
        int vr = RMQ(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }

    void setvalue(int i, int x){
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
    int n, k; cin >> n >> k;
    int a[n];
    int max_a = 0;
    rep(i,n) cin >> a[i], max_a = max(max_a, a[i]);

    vector<int> v(max_a+1);
    rep(i,max_a+1) v[i] = 0;

    SegmentTree seg = SegmentTree(v);

    rep(i,n){
        int l = max(0,a[i]-k);
        int r = min(max_a, a[i]+k);
        int temp = seg.RMQ(l,r+1);
        seg.setvalue(a[i], temp+1);
    }
    cout << seg.RMQ(0,max_a+1) << endl;
}