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

const int MAX_N = 1 << 17;
const ll INT_MA = pow(2,31) - 1;

// セグメント木を持つグローバル変数
int n, dat[2*MAX_N - 1];

// 初期化
void init(int n_){
    // 簡単のため要素数を2のべき乗に
    n = 1;
    while(n < n_) n *= 2;
    // 全ての値をINT_MAXに
    rep(i,2*n-1) dat[i] = INT_MA;
}

// k番目の値をaに変更
void update(int k, int a){
    // 葉の節点
    k += n-1;   // 根をインデックス0になるように並べ替えた時の葉の節点のインデックスはこのようになる
    dat[k] = a; // 葉の節点の値を指定のものに変更する
    // 登りながら更新(根にたどり着いたところで終了する)
    while(k > 0){
        k = (k-1) / 2;
        dat[k] = min(dat[k*2 + 1], dat[k*2 + 2]);
    }
}

// k: 節点の番号、l r: その節点が[l,r)に近づいていることを示す
// min[l,r)
int query(int a, int b, int k, int l, int r){
    // [a,b)と[l,r)が交差しなければ、INT_MAX
    if(r<=a || b<=l){
        return INT_MA;
    }
    // [a,b)が[l,r)を完全に含んでいれば、この節点の値を返す
    if(a <= l && r <= b){
        return dat[k];
    }else{
        // そうでなければ2つの子の最小値
        int vl = query(a, b, k*2+1, l, (l+r) / 2);  // 検索範囲を前半分にする
        int vr = query(a, b, k*2+2, (l+r)/2, r);    // 検索範囲を後半分にする
        return min(vl, vr);
    }
}

// min[l,r]
int query(int l, int r){
    return query(l,r+1, 0, 0, n);
}

int main()
{
    cin >> n; int q; cin >> q;
    init(n);    // セグメント木を表す配列の構築
    rep(_,q){
        int com; cin >> com;
        if(com == 0){
            int x, y; cin >> x >> y;
            update(x,y);
        }else if(com == 1){
            int x,y; cin >> x >> y;
            cout << query(x,y) << endl;
        }
    }
}