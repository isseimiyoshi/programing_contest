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
    int N, K; cin >> N >> K;
    vector<tuple<int, int> > T;
    for(int i=2; i<=N; i++){
        // まず頂点1と他の頂点を結んだグラフを作成する
        T.push_back(make_tuple(1, i));
    }
    int rn = (N-1)*(N-2)/2 - K; // 他に頂点同士を結ぶ回数を確定させる
    if(rn < 0){
        cout << -1 << endl;
        return 0;   // プログラムの終了
    }
    int cnt = 0;
    for(int i=2; i<=N; i++){
        if(rn == 0) break;
        for(int j=i+1; j<=N; j++){
            T.push_back(make_tuple(i, j));
            cnt++;
            if(cnt == rn){
                break;
            }
        }
        if(cnt == rn) break;
    }
    cout << T.size() << endl;
    rep(i,T.size()){
        int u, v;
        tie(u, v) = T[i];
        printf("%d %d\n", u, v);
    }
    return 0;
}