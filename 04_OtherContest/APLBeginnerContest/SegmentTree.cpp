#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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

class SegmentTree{
    int n;
    // represent tree as array
    // parent of k : (k-1)/2, child of k : 2*k+1, 2*k+2
    vector<int> node;

public:
    SegmentTree(vector<int> a){
        int n_ = a.size();  // n_ : 実際に引数に取られた配列のサイズ

        n = 1;
        while(n<n_) n *= 2; // セグメント木構造を作るために、要素数を2の乗数に調整している

        node.resize(2*n-1, INF);    // 初期ツリー構造（最初に全要素にINFを代入している）

        // 作成したツリー構造にデータを代入する
        rep(i,n_) node[n-1+i] = a[i];   // もとの配列の要素をセグメント木の一番葉の要素に代入している
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);  // 元の配列の要素から親配列を作成している
    }

    // [a,b)の範囲内で最小値を返す　[l,r)区間の最小値に対応している値がkである。
    int RMQ(int a, int b, int k=0, int l=0, int r=0){       // 初期値：[0,n)の範囲で最小値はnode[0]
        if(l>=r) r = n;
        if(r<=a || b<=l) return INF;    // 範囲外
        if(a<=l && r<=b) return node[k];    // 範囲内に収まったため、そのインデックスの配列に格納されている

        int vl = RMQ(a, b, 2*k+1, l, (l+r)/2);
        int vr = RMQ(a, b, 2*k+2, (l+r)/2, r);
        return min(vl,vr);
    }
}

int main()
{
    
}